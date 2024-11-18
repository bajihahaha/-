#include "define_all.h"  
#include "user_init.h"
#include "rtthread.h"
#include "uart.h"
#include "adc.h"
#include "spi.h"
#include "flash.h"
#include "rtc.h"
#include "lptim.h"
#include "EC800.h"
#include "bt16.h"
#include "sleep.h"









		int ret=999;
		static rt_timer_t timer2;

uint8_t GP_TEST_LEVEL;
static rt_timer_t timer_10ms;
static rt_timer_t timer_1s;
rt_timer_t timer_2s;

rt_sem_t sem_Thread_Manage;
rt_sem_t sem_Pulse_Process;

rt_sem_t sem_GPRS_Uart_Revice;
rt_sem_t sem_RTC_Timeout;

rt_thread_t TM_thread;//�̹߳����߳�
rt_thread_t GPRS_CmdProcessing_thread;//GPRS������߳�
rt_thread_t EVC_HandShakeProcessing_thread;//EVC������������Э�鴦���߳�
rt_thread_t EVC_ProcessingOffline_thread;//EVC�ǳ�����������Э�鴦���߳�
rt_thread_t Timed_Launch_thread;//��ʱ�����߳�
rt_thread_t RTC_TimeOut_thread;//RTC��ʱ�����߳�

uint8_t flag_IS_First_PULSE=1;
uint8_t PULSE_count=0;


		rt_tick_t ret2;









uint32 Voltage_Bat=0;
uint32 Voltage_Spc=0;

uint8_t External_power=0;



/*-----------����---------------------------------------------------------------------��--------���ܺ���-----------------------------------------------------------------------------------------------------------*/
// ����CRCУ���룬Modbus RTUʹ�õ�CRC-16У��
uint16_t modbus_crc16(uint8_t *data, int len)
{		
		int i;
    uint16_t crc = 0xFFFF;
    while (len--) 
    {
        crc ^= *data++;
        for (i = 0; i < 8; i++) 
        {
            if (crc & 0x0001) 
            {
                crc = (crc >> 1) ^ 0xA001;
            } else 
            {
                crc >>= 1;
            }
        }
    }
    return crc;
}
uint8_t DEC_to_HEX(uint8_t num)
{
    return (uint8_t)((num/10)*16+(num%10));
}
uint8_t HEX_to_DEC(uint8_t num)
{
    return (uint8_t)(((num>>4)&0x0F)*10+(num&0x0F));
}

//������ص�ѹ��SPC��ѹ
void Voltage_Read()
{
		GPIO_SetBits(BAT_CON_GPIO,BAT_CON_PIN);
		Voltage_Bat=Test_ADC_ExVolt(ADC_CFGR_BUFSEL_ADC_IN1);
		GPIO_ResetBits(BAT_CON_GPIO,BAT_CON_PIN);
			
		GPIO_SetBits(SPC_CON_GPIO,SPC_CON_PIN);
		Voltage_Spc=Test_ADC_ExVolt(ADC_CFGR_BUFSEL_ADC_IN6);
		GPIO_ResetBits(SPC_CON_GPIO,SPC_CON_PIN);
}
//��ʱ������ҳ����ʱ����������  OK
void Set_Latest_Alarm(uint8_t time_array[12][2])
{
		int i=0;
		int j=0;
		uint8_t cup0,cup1;
		RTC_TimeDateTypeDef  real_time;
		RTC_AlarmTmieTypeDef  alarm_time;
		for(i=0;i<12;i++)//����
		{
				for(j=0;j<12-i-1;j++)
				{
						if((time_array[j][0]>time_array[j+1][0])||
							((time_array[j][0]==time_array[j+1][0])&&(time_array[j][1]>time_array[j+1][1])))
						{
								cup0=time_array[j][0];
								cup1=time_array[j][1];
								time_array[j][0]=time_array[j+1][0];
								time_array[j][1]=time_array[j+1][1];
								time_array[j+1][0]=cup0;
								time_array[j+1][1]=cup1;
						}
				}
		}
		if(0==RTC_GetRTC(&real_time))//��ȡ��ǰʱ��
		{
			for(i=0;i<12;i++)
			{
						if((time_array[i][0]>real_time.Hour)||
							((time_array[i][0]==real_time.Hour)&&(time_array[i][1]>real_time.Minute)))//���þ��뵱ǰʱ���������һ������
						{
								alarm_time.Hour=time_array[i][0];
								alarm_time.Minute=time_array[i][1];
								alarm_time.Second=0;
								RTC_Alarm(alarm_time);
								break;
						}
			}
			if(i==12)//���ж�ʱʱ����춼�Ѿ���ȥ�������������������
			{
					alarm_time.Hour=time_array[0][0];
					alarm_time.Minute=time_array[0][1];
					alarm_time.Second=0;
					RTC_Alarm(alarm_time);
			}
		}
}
//��ȡ�û�����2�����沢�趨RTC����    ����Э��3    OK
//���Ƕ�ʱ�����õģ�ÿ��RTC���Ӵ������Զ���һ��
void EVC_Read_UserDate2()
{		
		rt_err_t res;
		uint8_t time_array[12][2]={99};//��ʱʱ������
		int i;
		//�鷢������
		uint8_t CMD_Array[8]={0x03,0x03,0x07,0x6e,0x00,0x10,0x25,0x4d};
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0'; 
		//UART5����
		UART5_Send();
		//���Ի�ȡUART5������ɺ��ͷŵ��ź���
		res=rt_sem_take(sem_EVC_Uart_Revice, RT_WAITING_FOREVER);
		if(res==RT_EOK)
		{
				//CRCУ��
				uint16_t verify=(((uint16_t)EVC_RX_Buffer[EVC_recv_lenth-1]<<8)&(~0x0F))+(uint16_t)EVC_RX_Buffer[EVC_recv_lenth-2];
				if( modbus_crc16(EVC_RX_Buffer,EVC_recv_lenth-2)!=verify)//����CRCУ��
				{

				}
				//�Ѿ��ɹ���ȡ���û�����2
//				FlashWrite(100,0,EVC_RX_Buffer,EVC_recv_lenth);//�����ڵ�100ҳ	
				//������ʱ������ά����
				for(i=0;i<12;i++)
				{
						time_array[i][0]=EVC_RX_Buffer[9+2*i];
						time_array[i][1]=EVC_RX_Buffer[9+2*i+1];
				}
				Set_Latest_Alarm(time_array);
		}
		
}
//��ȡ������ģ���������
void EVC_Read_IoT_Module_Parameters()
{		
		rt_err_t res;
		//�鷢������
		uint8_t CMD_Array[8]={0x02,0x03,0x08,0x98,0x00,0x27,0x86,0x6C};
		memcpy(EVC_TX_Buffer,CMD_Array,sizeof(CMD_Array));
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0'; 
		//UART5����
		UART5_Send();
		//���Ի�ȡUART5������ɺ��ͷŵ��ź���
		res=rt_sem_take(sem_EVC_Uart_Revice, RT_WAITING_FOREVER);
		if(res==RT_EOK)
		{
				//CRCУ��
				uint16_t verify=(((uint16_t)EVC_RX_Buffer[EVC_recv_lenth-1]<<8)&(~0x0F))+(uint16_t)EVC_RX_Buffer[EVC_recv_lenth-2];
				if( modbus_crc16(EVC_RX_Buffer,EVC_recv_lenth-2)!=verify)//����CRCУ��
				{
						return ;
				}
				//�Ѿ��ɹ���ȡ��������ģ���������
				
		}
}
//��ȡʵʱ����(��������)��ʧ�ܷ���-1���ɹ�����0�� OK
int  EVC_Read_RealTimeDate()
{
		rt_err_t res;
		//�鷢������
		uint8_t CMD_Array[8]={0x03,0x03,0x00,0x78,0x00,0x1c,0xc5,0xf8};
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0'; 
		//UART5����
		UART5_Send();
		//���Ի�ȡUART5������ɺ��ͷŵ��ź���
		res=rt_sem_take(sem_EVC_Uart_Revice, RT_WAITING_FOREVER);
		if(res==RT_EOK)
		{
				//CRCУ��
				uint16_t verify=(((uint16_t)EVC_RX_Buffer[60]<<8)&(~0x0F))+(uint16_t)EVC_RX_Buffer[59];
				if( modbus_crc16(EVC_RX_Buffer,61-2)!=verify)//����CRCУ��
				{
						return -1;
				}
		}
		return 0;
}
//EVCУʱ,ʱ����ԴΪDTU��RTC��RTCӦ�û�ͨ����λ�����׼ȷʱ��
void EVC_TimeCalibration()
{
		uint16_t crc;
		RTC_TimeDateTypeDef  real_time;
		uint8_t CMD_Array[15]={0x03,0x10,0x01,0x2c,0x00,0x03,0x06,0x24,0x11,0x11,0x19,0x20,0x06,0x93,0xb5};
		RTC_GetRTC(&real_time);
		CMD_Array[7]=(real_time.Year);
		CMD_Array[8]=(real_time.Month);
		CMD_Array[9]=(real_time.Date);
		CMD_Array[10]=(real_time.Hour);
		CMD_Array[11]=(real_time.Minute);
		CMD_Array[12]=(real_time.Second);
		crc=modbus_crc16(CMD_Array,sizeof(CMD_Array)-2);
		CMD_Array[13]=(uint8_t)(crc & 0xFF);
		CMD_Array[14]=(uint8_t)((crc >> 8) & 0xFF);
		
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0'; 
		//UART5����
		UART5_Send();
		
}
//EVC��ȡ�����¼����
void EVC_ReadInterval()//ʮ���Ʒ���
{
		uint16_t crc;
		uint8_t CMD_Array[8]={0x03,0x03,0x01,0x31,0x00,0x01};
		crc=modbus_crc16(CMD_Array,sizeof(CMD_Array)-2);
		CMD_Array[6]=(uint8_t)(crc & 0xFF);
		CMD_Array[7]=(uint8_t)((crc >> 8) & 0xFF);
		
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0';  
		//UART5����
		UART5_Send();
	
}
//EVC���ü����¼����
void EVC_SetInterval(uint8_t interval)//ʮ���Ʒ���
{
		uint16_t crc;
		uint8_t CMD_Array[11]={0x03,0x10,0x01,0x31,0x00,0x01,0x02,0x00};
		CMD_Array[8]=interval;
		crc=modbus_crc16(CMD_Array,sizeof(CMD_Array)-2);
		CMD_Array[9]=(uint8_t)(crc & 0xFF);
		CMD_Array[10]=(uint8_t)((crc >> 8) & 0xFF);
		
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0';  
		//UART5����
		UART5_Send();
	
}


void Write_EVC_Parameters(uint8_t interval)
{
		uint16_t crc;
		uint8_t CMD_Array[61]={0x03,0x10,0x01,0xf4,0x00,0x1a,0x34,0x00};
		CMD_Array[8]=interval;
		crc=modbus_crc16(CMD_Array,sizeof(CMD_Array)-2);
		CMD_Array[59]=(uint8_t)(crc & 0xFF);
		CMD_Array[60]=(uint8_t)((crc >> 8) & 0xFF);
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0';  
		//UART5����
		UART5_Send();
}


//��ȡСʱ��¼
void EVC_ReadHourLog()
{
		
}

//����DTU״̬��Ϣ
void Send_DTU_State()//1.��ǰ����״̬(Is_connected)2.������3.״̬�ֱ�����4.�ź�ǿ��(Signal_Strength)5.λ����Ϣ6.ICCID(ICCID) 7.��ص�ѹ 8.������� 9.spc��ѹ 10.spc���� 11.���(External_power)
{
		//�鷢������
		uint8_t CMD_Array[100]={DTU_ADDR,0x10,0x09,0xc4,0x00,0x1a,0x34,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x58,0x8d,0x00,0x65,0xce,0xaa,0x38,0x39,0x38,0x36,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x40,0x66,0x66,0x66,0x55,0x20,0x40,0x6c,0xcc,0xcd,0x62,0x40,0x00,0x00,0x37,0xec};
		CMD_Array[8]=Is_connected;//��ǰ����״̬
		//������
		//״̬������
		CMD_Array[18]=Signal_Strength;//�ź�ǿ��
		//λ����Ϣ
		memcpy(&CMD_Array[25],ICCID,20);//ICCID
		//��ص�ѹ
		//�������
		//spc��ѹ
		//spc����
		//���
			
			
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0';
		//UART5����
		UART5_Send();
		
}

//GPRS�˽��ջ������е����ݵ�CRC��֤��ʧ�ܷ���-1���ɹ�����0��
int GPRS_CRC()
{
		int lenth;
		uint16_t verify;
		lenth=GPRS_recv_lenth;
		if(lenth>1)
		{
				verify=(((uint16_t)GPRS_RX_Buffer[lenth-1]<<8)&(~0x0F))+(uint16_t)GPRS_RX_Buffer[lenth-2];
				if( modbus_crc16(GPRS_RX_Buffer,lenth-2)==verify)//����CRCУ��
				{
						return 0;
				}
		}
		return -1;
}
 

/*-----------����---------------------------------------------------------------------��------�̵߳���ں���-------------------------------------------------------------------------------------------------------*/


static void TM_thread_entry(void *parameter)//��Դ�����߳�
{
		rt_err_t res;
		while(1)
		{
				res=rt_sem_take(sem_Thread_Manage, RT_WAITING_FOREVER);//ȷ���ⲿ��Դ�ϵ���µ��
				if(res==RT_EOK)
				{
						if(GP_TEST_LEVEL==1)//�������Դ
						{
								External_power=1;
								GPIO_SetBits(LED_GREEN_GPIO,LED_GREEN_PIN);
								if((Is_connected!=0x01)&&(Is_connecting==0x00))//�����������δ����,��δ�������ߣ�������
								{
										if(0==Connect())
										{
												Is_connected=0x01;
												
										}
								}
								else if(Is_connected==0x01)//����Ѿ��������ˣ���ʱ������磬��ϣ��������
								{
										//��ʱ������ڵȴ�15s
										rt_sem_release(sem_GPRS_Uart_Revice);//��ֹ�����볬ʱ����		
								}
						}
						else if(GP_TEST_LEVEL==0)//�Ͽ����Դ
						{
								External_power=0;
								GPIO_ResetBits(LED_GREEN_GPIO,LED_GREEN_PIN);
								if(Is_connected)
								{
										rt_sem_release(sem_GPRS_Uart_Revice);//�����ģʽ�£�GPRS�߳����޵ȣ������ͷų���
								}
						}
				}
		}
}
//������ǰ�����߳�Ӧ�ù��������ߺ������
static void GPRS_CmdProcessing_thread_entry(void *parameter)//GPRS������߳� ����GPRSģ������ݣ�����GPRS������ȥ��ȡEVC���ݣ���EVC�����ݷ��͵�GPRS
{
		rt_err_t res;
		uint16_t crc;
		RTC_TimeDateTypeDef now;
		RTC_AlarmTmieTypeDef TempAlarmTime;
		int resend_times=0;
		uint8_t temp[256];
		rt_thread_mdelay(500);//�ȴ�ϵͳ״̬��ȡ
		while(1)
		{
				if(Is_connected)
				{
				
						if(1==External_power)
						{
								res=rt_sem_take(sem_GPRS_Uart_Revice, RT_WAITING_FOREVER);//GPRSģ���յ���Ϣ��
						}
						else if(0==External_power)
						{
								res=rt_sem_take(sem_GPRS_Uart_Revice, 15*RT_TICK_PER_SECOND);//û����磬�ǳ�������ģʽ���ȴ�15��������·�ָ���û���յ������Զ�����
						}
						if(-RT_ETIMEOUT==res)//����������£����޵ȣ������ܽ���ʱ��
						{
								if(0x01==Is_connected)
								{
										Disconnect();
								}
								
						}
						else if(res==RT_EOK)
						{
								if(0==GPRS_CRC())
								{
										memcpy(temp,GPRS_RX_Buffer,256);
										//ÿ��gprs_rx_buffer���궼����������
										GPRS_recv_lenth=0;
										GPRS_rx_index=0;
										switch(PROTOCOL)
										{
											case 1://������ҵЭ�顷
												switch(temp[2])
												{
													case 0x05://���ü����¼����
														EVC_SetInterval(temp[3]);
//														res=rt_sem_take(sem_EVC_Uart_Revice,3*RT_TICK_PER_SECOND);
//														if(res==RT_EOK)
//														{
//																
//														}
//														EVC_ReadInterval();
//														res=rt_sem_take(sem_EVC_Uart_Revice,3*RT_TICK_PER_SECOND);
														if(res==RT_EOK)
														{
																Send_AT_Command('8');
																while(GPRS_byte!='>'){}
																GPRS_tx_length=6+1;
																GPRS_TX_Buffer[0]=0x3E;
																GPRS_TX_Buffer[1]=0x06;
																GPRS_TX_Buffer[2]=0x05;
																GPRS_TX_Buffer[3]=temp[3]/*EVC_RX_Buffer[4]*/;
																modbus_crc16(GPRS_TX_Buffer,4);//CRC
																GPRS_TX_Buffer[4]=(uint8_t)(crc & 0xFF);
																GPRS_TX_Buffer[5]=(uint8_t)((crc >> 8) & 0xFF);
																GPRS_TX_Buffer[6]=0x1A; 
																UART4_Send();
														}

														break;
													case 0x08://��������Сʱ��¼���
														
														break;
													case 0x11://�ϴ�ʵʱ����
RESEND:												
														if(0==EVC_Read_RealTimeDate())//�ɹ���ȡ��ʵʱ���ݣ�����EVC_RX_Buffer
														{
																Send_AT_Command('8');
																while(GPRS_byte!='>'){}
																GPRS_tx_length=81+1;
																GPRS_TX_Buffer[0]=0x3E;
																GPRS_TX_Buffer[1]=0x51;
																GPRS_TX_Buffer[2]=0x11;
																//���ʶ
																//λ��
																//�û���
																memcpy(&GPRS_TX_Buffer[25],&EVC_RX_Buffer[3],38);
																//״̬����
																memcpy(&GPRS_TX_Buffer[67],&EVC_RX_Buffer[47],12);
																modbus_crc16(GPRS_TX_Buffer,79);//CRC
																GPRS_TX_Buffer[79]=(uint8_t)(crc & 0xFF);
																GPRS_TX_Buffer[80]=(uint8_t)((crc >> 8) & 0xFF);
																GPRS_TX_Buffer[81]=0x1A; 
																UART4_Send();
																//��Ϊʵʱ����������DTU���յ�EVCЭ��Ķ�ʱ�ϱ����ϱ���ɺ�Ӧ�ü�ʱ���ߣ�����
																//�����Ǳ���ʵʱ���ĺ���15S��δ�յ��������Ļ��������������ģ�
																//���ط�һ�Σ����ȴ����ս������ģ��յ����δ�յ�15S�����ߣ�
																if(0==External_power)
																{
																		res=rt_sem_take(sem_GPRS_Uart_Revice,15*RT_TICK_PER_SECOND);//�ȴ�15s
																		if(-RT_ETIMEOUT==res)//��15��δ�յ���Ϣ
																		{
																				if(resend_times<1)
																				{
																						resend_times++;
																						goto RESEND;
																				}
																				else
																				{
																						resend_times=0;
																						Disconnect();
																				}
																		}
																		else if(RT_EOK==res)//����յ���
																		{
																				resend_times=0;
																				rt_sem_release(sem_GPRS_Uart_Revice);//�ͷ��ź������˳��ϴ�ʵʱ���ķ�֧�����̴߳���														
																		}
																}		
														}
														break;
													case 0x12://����������
														if(External_power==0)
														{
																Disconnect();
														}
														break;
													
													case 0x13://Уʱ �� ���ö�ʱ�ϴ�ʱ��
														Send_AT_Command('8');//��ı�tx_lenth
														while(GPRS_byte!='>'){}
														now.Year=temp[3];
														now.Month=temp[4];
														now.Date=temp[5];
														now.Hour=temp[6];
														now.Minute=temp[7];
														now.Second=temp[8];
														RTC_SetRTC(&now);
														EVC_TimeCalibration();
														res=rt_sem_take(sem_EVC_Uart_Revice,3*RT_TICK_PER_SECOND);
														if(res==RT_EOK)
														{
																//Уʱ�ɹ�
																
														}
														TempAlarmTime.Hour=temp[9];
														TempAlarmTime.Minute=temp[10];
														TempAlarmTime.Second=temp[11];
														RTC_Alarm(TempAlarmTime);
														GPRS_tx_length=5+1;
														GPRS_TX_Buffer[0]=0x3E;
														GPRS_TX_Buffer[1]=0x05;
														GPRS_TX_Buffer[2]=0x13;
														GPRS_TX_Buffer[3]=0x52;
														GPRS_TX_Buffer[4]=0x91;
														GPRS_TX_Buffer[5]=0x1A;
														UART4_Send();
														break;
													
													case 0x17://�ϴ��ź�ǿ��
														//Ϊ�˶�ȡatָ��أ���ʱ�޸�Is_connected����ȡ�����ϻָ�
														Is_connected=0;
														AT_IS_OverTime=0;
														BtimerStart(BT1);
														Send_AT_Command('5');//csq

														while((strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)&(AT_IS_OverTime!=1))
														{
																
														}
														BtimerStop(BT1);		
														if(strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)
														{
			
														}
														//��ȡ�ź�ֵ
														Signal_Strength=0;
														Signal_Strength+=((GPRS_RX_Buffer[15]-0x30)<<4);
														Signal_Strength+=(GPRS_RX_Buffer[16]-0x30);
														memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
														GPRS_recv_lenth=0;
														GPRS_rx_index=0;
														Is_connected=1;//�ָ�
														Send_AT_Command('8');
														while(GPRS_byte!='>'){}
														GPRS_tx_length=7+1;
														GPRS_TX_Buffer[0]=0x3E;
														GPRS_TX_Buffer[1]=0x07;
														GPRS_TX_Buffer[2]=0x17;
														GPRS_TX_Buffer[3]=Signal_Strength;
														GPRS_TX_Buffer[4]=0x99;
														modbus_crc16(GPRS_TX_Buffer,5);//CRC
														GPRS_TX_Buffer[5]=(uint8_t)(crc & 0xFF);
														GPRS_TX_Buffer[6]=(uint8_t)((crc >> 8) & 0xFF);
														GPRS_TX_Buffer[7]=0x1A; 
														UART4_Send();		
												}
												break;
												
												
										}
								}
						}
						rt_thread_mdelay(10);
				}
		}
}

static void EVC_HandShakeProcessing_thread_entry(void *parameter)//EVC����Э�鴦���߳�
{
		rt_err_t res;
		uint8_t  Pulse_Num;
		while(1)
		{
				if(1==External_power)//�����->��������ģʽ
				{
						res=rt_sem_take(sem_Pulse_Process, RT_WAITING_FOREVER);
						if(res==RT_EOK)
						{
								Pulse_Num=PULSE_count;
								flag_IS_First_PULSE=1;
								if(Pulse_Num==1||Pulse_Num==2)//Э��һ
								{
										
								}
								else if(Pulse_Num==3||Pulse_Num==4)//Э���
								{
										
								}
								else if(Pulse_Num==5||Pulse_Num==6)//Э����
								{
										EVC_Read_UserDate2();
								}
						}
				}
				else if(0==External_power)//û���->����������
				{
						res=rt_sem_take(sem_Pulse_Process, RT_WAITING_FOREVER);
						if(res==RT_EOK)
						{
								Pulse_Num=PULSE_count;
								flag_IS_First_PULSE=1;
								if(Pulse_Num==1||Pulse_Num==2)//Э��һ
								{
										//���ļ��������������ߺ����ϴ�ʵʱ���ĺ�λ����Ϣָ��
										//����ֻ��Ҫ����
										if(0==Connect())
										{
												Is_connected=0x01;
										}
										else
										{
												Is_connected=0x02;//����ʧ��
										}
																		
								}
								else if(Pulse_Num==3||Pulse_Num==4)//Э���
								{
										
								}
								else if(Pulse_Num==5||Pulse_Num==6)//Э����
								{
										EVC_Read_UserDate2();//��ȡ�û�����2�����沢�趨RTC����
								}
						}
				}
				
		}
}
static void RTC_TimeOut_thread_entry(void *parameter)//RTC�жϴ���:��ȡflash�е��û�����2����������RTCʱ��
{
		int res;
		while(1)
		{
				res=rt_sem_take(sem_RTC_Timeout, RT_WAITING_FOREVER);
				if(res==RT_EOK)
				{	
						if((Is_connected!=0x01)&&(Is_connecting==0x00))//�����������δ����,��δ�������ߣ�������
						{
								if(0==Connect())
								{
										Is_connected=0x01;	
								}
						}
						//������һ��RTCʱ��
						 EVC_Read_UserDate2();
				}
		}
}

/*-----------����---------------------------------------------------------------------��------�жϴ�����--------------------------------------------------------------------------------------------------------*/
//GPIO�жϴ�����  
void GPIO_IRQHandler(void)
{
		if(SET == GPIO_EXTI_EXTIISR_ChkEx(GP_TEST_GPIO,GP_TEST_PIN))//���Դ����жϡ���ֹ��������ǰ�Ѿ�����磬Ӧ���ڳ���ʼ����ʱ�ж�һ��������硷
    {
        GPIO_EXTI_EXTIISR_ClrEx(GP_TEST_GPIO, GP_TEST_PIN);
				GP_TEST_LEVEL=GPIO_ReadInputDataBit(GP_TEST_GPIO,GP_TEST_PIN);
				rt_timer_start(timer_10ms);
		}
		else if(SET == GPIO_EXTI_EXTIISR_ChkEx(PULSE_GPIO,PULSE_PIN))//�������ж�
		{
				GPIO_EXTI_EXTIISR_ClrEx(PULSE_GPIO,PULSE_PIN);
				if(flag_IS_First_PULSE)
				{
						PULSE_count=0;
						rt_timer_start(timer_1s);
				}
				PULSE_count++;		
		}
} 

//��ʱ���жϴ�����
static void timeout_10ms(void *parameter)
{
    if(GP_TEST_LEVEL==GPIO_ReadInputDataBit(GP_TEST_GPIO,GP_TEST_PIN))//ȷ���ⲿ��Դ�ϵ���µ�
		{
				rt_sem_release(sem_Thread_Manage);//�ͷ��ź����������̻߳�ȡ
		}
}
//��ʱ���жϴ��������жϽ��յ��������壬�ж�Э��
static void timeout_1s(void *parameter)
{
		rt_sem_release(sem_Pulse_Process);//
}

static void timeout_2s(void *parameter)
{
		AT_IS_OverTime=1;//��ʱ����ʱ��־λ
}
RTC_TimeDateTypeDef temp;
//RTC��ʱ�жϴ�����
void RTC_IRQHandler(void)
{
			
		if( RTC_ISR_SEC_IF_Chk() == SET)//��ѯ���Ӷϱ�־�Ƿ�����
		{
				RTC_GetRTC(&temp);
				RTC_ISR_SEC_IF_Clr();		//������жϱ�־
		}
		if( RTC_ISR_ALARM_IF_Chk() == SET)//��ѯ�����Ӷϱ�־�Ƿ�����
		{		
				RTC_ISR_ALARM_IF_Clr();		//��������жϱ�־
				rt_sem_release(sem_RTC_Timeout);////�ͷ��ź��� �����û�����2�������µ�RTC����			
		}	
}



void LPTIM_IRQHandler(void)//LPTIM�жϷ������
{

    if (LPTIM_ISR_OVIF_Chk() == SET)//����жϱ�־������
    {
        LPTIM_ISR_OVIF_Clr();//����жϱ�־
        Voltage_Read();
        
    }
}
	






static void timeout2(void *parameter)
{
    ret=888;
}

//RTC_TimeDateTypeDef  kkk;
//RTC_AlarmTmieTypeDef ppp;

int main(void)
{
		//Init_System();
		__enable_irq();

    timer_10ms=rt_timer_create("timer_10ms", timeout_10ms,RT_NULL,  10, RT_TIMER_FLAG_ONE_SHOT);//����10ms��ʱ����ʱ��
    timer_1s=rt_timer_create("timer_1s", timeout_1s,RT_NULL,RT_TICK_PER_SECOND,RT_TIMER_FLAG_ONE_SHOT);//����1s��ʱ�����ζ�ʱ��
		timer_2s=rt_timer_create("timer_2s",timeout_2s,RT_NULL,2000, RT_TIMER_FLAG_ONE_SHOT );//�������붨ʱ��������������atָ��ĳ�ʱ
		sem_Thread_Manage=rt_sem_create("sem_1ms",0,RT_IPC_FLAG_PRIO); 
		sem_Pulse_Process=rt_sem_create("sem_1s",0,RT_IPC_FLAG_PRIO);
		sem_EVC_Uart_Revice=rt_sem_create("sem_uart_recv",0,RT_IPC_FLAG_PRIO);
		sem_GPRS_Uart_Revice=rt_sem_create("sem_uart_recv",0,RT_IPC_FLAG_PRIO);
		sem_RTC_Timeout=rt_sem_create("sem_rtc_timeout",0,RT_IPC_FLAG_PRIO); 
	
		BtimerInit(BT1,20);//��ʼ��������ʱ������ʱʱ��20s,����atָ�ʱ
		

		
		TM_thread=rt_thread_create("TM",TM_thread_entry,RT_NULL,256,10,10);//������µ�����жϣ��жϿ�����ʱ������ʱ���ж���ȷ���ȶ���ȷ���ͷ��ź��������߳�ѭ�����Ի�ȡ���ź��������о����ֱ࣬���ж���д���ͺ��ˡ�
		if(TM_thread!=RT_NULL)
		{
			rt_thread_startup(TM_thread);  
		}
		
		GPRS_CmdProcessing_thread=rt_thread_create("GPRS_CmdProcessing",GPRS_CmdProcessing_thread_entry,RT_NULL,512,10,10);
		if(GPRS_CmdProcessing_thread!=RT_NULL)
		{
			rt_thread_startup(GPRS_CmdProcessing_thread);  
		}	
		
		EVC_HandShakeProcessing_thread=rt_thread_create("EVC_HandShakeProcessing",EVC_HandShakeProcessing_thread_entry,RT_NULL,256,10,10);
		if(EVC_HandShakeProcessing_thread!=RT_NULL)
		{
			rt_thread_startup(EVC_HandShakeProcessing_thread);  
		}	
		
//		EVC_ProcessingOffline_thread=rt_thread_create("EVC_ProcessingOffline",EVC_ProcessingOffline_thread_entry,RT_NULL,512,10,10);
//		if(EVC_ProcessingOffline_thread!=RT_NULL)
//		{
//			rt_thread_startup(EVC_ProcessingOffline_thread);  
//		}
		
//		Timed_Launch_thread=rt_thread_create("Timed_Launch",Timed_Launch_thread_entry,RT_NULL,256,10,10);
//		if(Timed_Launch_thread!=RT_NULL)
//		{
//			rt_thread_startup(Timed_Launch_thread);  
//		}
//		
		RTC_TimeOut_thread=rt_thread_create("RTC_TimeOut",RTC_TimeOut_thread_entry,RT_NULL,256,10,10);
		if(RTC_TimeOut_thread!=RT_NULL)
		{
			rt_thread_startup(RTC_TimeOut_thread);  
		}
//		LPTIM_COUNTER_5Min();//����5���Ӷ�ʱ�������ڶ�ʱ����ص���


		GPIO_EXTI_EXTIISR_ClrEx(GP_TEST_GPIO, GP_TEST_PIN);
		GP_TEST_LEVEL=GPIO_ReadInputDataBit(GP_TEST_GPIO,GP_TEST_PIN);
		rt_timer_start(timer_10ms);
//		Write_EVC_Parameters(0x01);
//		EVC_Read_UserDate2();

		if(0==Connect())
		{
			Is_connected=1;
		}
//		kkk.Year=24;
//		kkk.Month=11;
//		kkk.Date=12;
//		kkk.Hour=15;
//		kkk.Minute=38;
//		kkk.Second=10;
//		RTC_SetRTC(&kkk);
//		ppp.Hour=15;
//		ppp.Minute=38;
//		ppp.Second=15;
//		 RTC_Alarm(ppp);



    
}







