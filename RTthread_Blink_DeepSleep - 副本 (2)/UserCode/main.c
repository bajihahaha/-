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

rt_thread_t TM_thread;//线程管理线程
rt_thread_t GPRS_CmdProcessing_thread;//GPRS命令处理线程
rt_thread_t EVC_HandShakeProcessing_thread;//EVC长期在线握手协议处理线程
rt_thread_t EVC_ProcessingOffline_thread;//EVC非长期在线握手协议处理线程
rt_thread_t Timed_Launch_thread;//定时上线线程
rt_thread_t RTC_TimeOut_thread;//RTC超时处理线程

uint8_t flag_IS_First_PULSE=1;
uint8_t PULSE_count=0;


		rt_tick_t ret2;









uint32 Voltage_Bat=0;
uint32 Voltage_Spc=0;

uint8_t External_power=0;



/*-----------——---------------------------------------------------------------------—--------功能函数-----------------------------------------------------------------------------------------------------------*/
// 计算CRC校验码，Modbus RTU使用的CRC-16校验
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

//测量电池电压和SPC电压
void Voltage_Read()
{
		GPIO_SetBits(BAT_CON_GPIO,BAT_CON_PIN);
		Voltage_Bat=Test_ADC_ExVolt(ADC_CFGR_BUFSEL_ADC_IN1);
		GPIO_ResetBits(BAT_CON_GPIO,BAT_CON_PIN);
			
		GPIO_SetBits(SPC_CON_GPIO,SPC_CON_PIN);
		Voltage_Spc=Test_ADC_ExVolt(ADC_CFGR_BUFSEL_ADC_IN6);
		GPIO_ResetBits(SPC_CON_GPIO,SPC_CON_PIN);
}
//在时间表中找出最近时间设置闹钟  OK
void Set_Latest_Alarm(uint8_t time_array[12][2])
{
		int i=0;
		int j=0;
		uint8_t cup0,cup1;
		RTC_TimeDateTypeDef  real_time;
		RTC_AlarmTmieTypeDef  alarm_time;
		for(i=0;i<12;i++)//排序
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
		if(0==RTC_GetRTC(&real_time))//读取当前时间
		{
			for(i=0;i<12;i++)
			{
						if((time_array[i][0]>real_time.Hour)||
							((time_array[i][0]==real_time.Hour)&&(time_array[i][1]>real_time.Minute)))//设置距离当前时间最近的下一个闹钟
						{
								alarm_time.Hour=time_array[i][0];
								alarm_time.Minute=time_array[i][1];
								alarm_time.Second=0;
								RTC_Alarm(alarm_time);
								break;
						}
			}
			if(i==12)//所有定时时间今天都已经过去，设置明天最早的闹钟
			{
					alarm_time.Hour=time_array[0][0];
					alarm_time.Minute=time_array[0][1];
					alarm_time.Second=0;
					RTC_Alarm(alarm_time);
			}
		}
}
//读取用户参数2并储存并设定RTC闹钟    用于协议3    OK
//这是定时上线用的，每次RTC闹钟触发可以都读一次
void EVC_Read_UserDate2()
{		
		rt_err_t res;
		uint8_t time_array[12][2]={99};//定时时间数组
		int i;
		//组发送命令
		uint8_t CMD_Array[8]={0x03,0x03,0x07,0x6e,0x00,0x10,0x25,0x4d};
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0'; 
		//UART5发送
		UART5_Send();
		//尝试获取UART5接收完成后释放的信号量
		res=rt_sem_take(sem_EVC_Uart_Revice, RT_WAITING_FOREVER);
		if(res==RT_EOK)
		{
				//CRC校验
				uint16_t verify=(((uint16_t)EVC_RX_Buffer[EVC_recv_lenth-1]<<8)&(~0x0F))+(uint16_t)EVC_RX_Buffer[EVC_recv_lenth-2];
				if( modbus_crc16(EVC_RX_Buffer,EVC_recv_lenth-2)!=verify)//进行CRC校验
				{

				}
				//已经成功读取到用户参数2
//				FlashWrite(100,0,EVC_RX_Buffer,EVC_recv_lenth);//保存在第100页	
				//将闹钟时间存入二维数组
				for(i=0;i<12;i++)
				{
						time_array[i][0]=EVC_RX_Buffer[9+2*i];
						time_array[i][1]=EVC_RX_Buffer[9+2*i+1];
				}
				Set_Latest_Alarm(time_array);
		}
		
}
//读取物联网模块参数参数
void EVC_Read_IoT_Module_Parameters()
{		
		rt_err_t res;
		//组发送命令
		uint8_t CMD_Array[8]={0x02,0x03,0x08,0x98,0x00,0x27,0x86,0x6C};
		memcpy(EVC_TX_Buffer,CMD_Array,sizeof(CMD_Array));
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0'; 
		//UART5发送
		UART5_Send();
		//尝试获取UART5接收完成后释放的信号量
		res=rt_sem_take(sem_EVC_Uart_Revice, RT_WAITING_FOREVER);
		if(res==RT_EOK)
		{
				//CRC校验
				uint16_t verify=(((uint16_t)EVC_RX_Buffer[EVC_recv_lenth-1]<<8)&(~0x0F))+(uint16_t)EVC_RX_Buffer[EVC_recv_lenth-2];
				if( modbus_crc16(EVC_RX_Buffer,EVC_recv_lenth-2)!=verify)//进行CRC校验
				{
						return ;
				}
				//已经成功读取到物联网模块参数参数
				
		}
}
//读取实时数据(包含警报)【失败返回-1，成功返回0】 OK
int  EVC_Read_RealTimeDate()
{
		rt_err_t res;
		//组发送命令
		uint8_t CMD_Array[8]={0x03,0x03,0x00,0x78,0x00,0x1c,0xc5,0xf8};
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0'; 
		//UART5发送
		UART5_Send();
		//尝试获取UART5接收完成后释放的信号量
		res=rt_sem_take(sem_EVC_Uart_Revice, RT_WAITING_FOREVER);
		if(res==RT_EOK)
		{
				//CRC校验
				uint16_t verify=(((uint16_t)EVC_RX_Buffer[60]<<8)&(~0x0F))+(uint16_t)EVC_RX_Buffer[59];
				if( modbus_crc16(EVC_RX_Buffer,61-2)!=verify)//进行CRC校验
				{
						return -1;
				}
		}
		return 0;
}
//EVC校时,时间来源为DTU的RTC，RTC应该会通过上位机获得准确时间
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
		//UART5发送
		UART5_Send();
		
}
//EVC读取间隔记录周期
void EVC_ReadInterval()//十进制分钟
{
		uint16_t crc;
		uint8_t CMD_Array[8]={0x03,0x03,0x01,0x31,0x00,0x01};
		crc=modbus_crc16(CMD_Array,sizeof(CMD_Array)-2);
		CMD_Array[6]=(uint8_t)(crc & 0xFF);
		CMD_Array[7]=(uint8_t)((crc >> 8) & 0xFF);
		
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0';  
		//UART5发送
		UART5_Send();
	
}
//EVC设置间隔记录周期
void EVC_SetInterval(uint8_t interval)//十进制分钟
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
		//UART5发送
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
		//UART5发送
		UART5_Send();
}


//读取小时记录
void EVC_ReadHourLog()
{
		
}

//发送DTU状态信息
void Send_DTU_State()//1.当前连接状态(Is_connected)2.故障码3.状态字报警字4.信号强度(Signal_Strength)5.位置信息6.ICCID(ICCID) 7.电池电压 8.电池容量 9.spc电压 10.spc容量 11.外电(External_power)
{
		//组发送命令
		uint8_t CMD_Array[100]={DTU_ADDR,0x10,0x09,0xc4,0x00,0x1a,0x34,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x58,0x8d,0x00,0x65,0xce,0xaa,0x38,0x39,0x38,0x36,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x40,0x66,0x66,0x66,0x55,0x20,0x40,0x6c,0xcc,0xcd,0x62,0x40,0x00,0x00,0x37,0xec};
		CMD_Array[8]=Is_connected;//当前连接状态
		//故障码
		//状态报警字
		CMD_Array[18]=Signal_Strength;//信号强度
		//位置信息
		memcpy(&CMD_Array[25],ICCID,20);//ICCID
		//电池电压
		//电池容量
		//spc电压
		//spc容量
		//外电
			
			
		EVC_tx_length=sizeof(CMD_Array);
		memcpy(EVC_TX_Buffer,CMD_Array,EVC_tx_length);
		EVC_TX_Buffer[sizeof(CMD_Array)]='\0';
		//UART5发送
		UART5_Send();
		
}

//GPRS端接收缓冲区中的数据的CRC验证【失败返回-1，成功返回0】
int GPRS_CRC()
{
		int lenth;
		uint16_t verify;
		lenth=GPRS_recv_lenth;
		if(lenth>1)
		{
				verify=(((uint16_t)GPRS_RX_Buffer[lenth-1]<<8)&(~0x0F))+(uint16_t)GPRS_RX_Buffer[lenth-2];
				if( modbus_crc16(GPRS_RX_Buffer,lenth-2)==verify)//进行CRC校验
				{
						return 0;
				}
		}
		return -1;
}
 

/*-----------——---------------------------------------------------------------------—------线程的入口函数-------------------------------------------------------------------------------------------------------*/


static void TM_thread_entry(void *parameter)//电源管理线程
{
		rt_err_t res;
		while(1)
		{
				res=rt_sem_take(sem_Thread_Manage, RT_WAITING_FOREVER);//确定外部电源上电或下电后
				if(res==RT_EOK)
				{
						if(GP_TEST_LEVEL==1)//接入外电源
						{
								External_power=1;
								GPIO_SetBits(LED_GREEN_GPIO,LED_GREEN_PIN);
								if((Is_connected!=0x01)&&(Is_connecting==0x00))//接入外电后，如果未上线,且未正在上线，则上线
								{
										if(0==Connect())
										{
												Is_connected=0x01;
												
										}
								}
								else if(Is_connected==0x01)//如果已经在线上了，这时接入外电，不希望它下线
								{
										//这时大概率在等待15s
										rt_sem_release(sem_GPRS_Uart_Revice);//防止它进入超时下线		
								}
						}
						else if(GP_TEST_LEVEL==0)//断开外电源
						{
								External_power=0;
								GPIO_ResetBits(LED_GREEN_GPIO,LED_GREEN_PIN);
								if(Is_connected)
								{
										rt_sem_release(sem_GPRS_Uart_Revice);//有外电模式下，GPRS线程无限等，将他释放出来
								}
						}
				}
		}
}
//在上线前，该线程应该挂起，在上线后才运行
static void GPRS_CmdProcessing_thread_entry(void *parameter)//GPRS命令处理线程 接收GPRS模块的数据，根据GPRS的数据去读取EVC数据，将EVC的数据发送到GPRS
{
		rt_err_t res;
		uint16_t crc;
		RTC_TimeDateTypeDef now;
		RTC_AlarmTmieTypeDef TempAlarmTime;
		int resend_times=0;
		uint8_t temp[256];
		rt_thread_mdelay(500);//等待系统状态读取
		while(1)
		{
				if(Is_connected)
				{
				
						if(1==External_power)
						{
								res=rt_sem_take(sem_GPRS_Uart_Revice, RT_WAITING_FOREVER);//GPRS模块收到消息后
						}
						else if(0==External_power)
						{
								res=rt_sem_take(sem_GPRS_Uart_Revice, 15*RT_TICK_PER_SECOND);//没有外电，非持续在线模式，等待15秒服务器下发指令，若没有收到，则自动下线
						}
						if(-RT_ETIMEOUT==res)//有外电的情况下，无限等，不肯能进超时，
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
										//每次gprs_rx_buffer用完都得做这两步
										GPRS_recv_lenth=0;
										GPRS_rx_index=0;
										switch(PROTOCOL)
										{
											case 1://《工商业协议》
												switch(temp[2])
												{
													case 0x05://设置间隔记录周期
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
													case 0x08://请求间隔和小时记录打包
														
														break;
													case 0x11://上传实时报文
RESEND:												
														if(0==EVC_Read_RealTimeDate())//成功读取到实时数据，存在EVC_RX_Buffer
														{
																Send_AT_Command('8');
																while(GPRS_byte!='>'){}
																GPRS_tx_length=81+1;
																GPRS_TX_Buffer[0]=0x3E;
																GPRS_TX_Buffer[1]=0x51;
																GPRS_TX_Buffer[2]=0x11;
																//表标识
																//位置
																//用户号
																memcpy(&GPRS_TX_Buffer[25],&EVC_RX_Buffer[3],38);
																//状态报警
																memcpy(&GPRS_TX_Buffer[67],&EVC_RX_Buffer[47],12);
																modbus_crc16(GPRS_TX_Buffer,79);//CRC
																GPRS_TX_Buffer[79]=(uint8_t)(crc & 0xFF);
																GPRS_TX_Buffer[80]=(uint8_t)((crc >> 8) & 0xFF);
																GPRS_TX_Buffer[81]=0x1A; 
																UART4_Send();
																//因为实时报文命令是DTU接收到EVC协议的定时上报，上报完成后应该及时下线，所以
																//对于仪表发送实时报文后在15S内未收到结束报文或其他正常请求报文，
																//将重发一次，并等待接收结束报文，收到后或未收到15S后下线；
																if(0==External_power)
																{
																		res=rt_sem_take(sem_GPRS_Uart_Revice,15*RT_TICK_PER_SECOND);//等待15s
																		if(-RT_ETIMEOUT==res)//若15后未收到信息
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
																		else if(RT_EOK==res)//如果收到了
																		{
																				resend_times=0;
																				rt_sem_release(sem_GPRS_Uart_Revice);//释放信号量，退出上传实时报文分支，让线程处理														
																		}
																}		
														}
														break;
													case 0x12://结束，下线
														if(External_power==0)
														{
																Disconnect();
														}
														break;
													
													case 0x13://校时 和 设置定时上传时间
														Send_AT_Command('8');//会改变tx_lenth
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
																//校时成功
																
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
													
													case 0x17://上传信号强度
														//为了读取at指令返回，临时修改Is_connected，读取完马上恢复
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
														//读取信号值
														Signal_Strength=0;
														Signal_Strength+=((GPRS_RX_Buffer[15]-0x30)<<4);
														Signal_Strength+=(GPRS_RX_Buffer[16]-0x30);
														memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
														GPRS_recv_lenth=0;
														GPRS_rx_index=0;
														Is_connected=1;//恢复
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

static void EVC_HandShakeProcessing_thread_entry(void *parameter)//EVC握手协议处理线程
{
		rt_err_t res;
		uint8_t  Pulse_Num;
		while(1)
		{
				if(1==External_power)//有外电->持续在线模式
				{
						res=rt_sem_take(sem_Pulse_Process, RT_WAITING_FOREVER);
						if(res==RT_EOK)
						{
								Pulse_Num=PULSE_count;
								flag_IS_First_PULSE=1;
								if(Pulse_Num==1||Pulse_Num==2)//协议一
								{
										
								}
								else if(Pulse_Num==3||Pulse_Num==4)//协议二
								{
										
								}
								else if(Pulse_Num==5||Pulse_Num==6)//协议三
								{
										EVC_Read_UserDate2();
								}
						}
				}
				else if(0==External_power)//没外电->不持续在线
				{
						res=rt_sem_take(sem_Pulse_Process, RT_WAITING_FOREVER);
						if(res==RT_EOK)
						{
								Pulse_Num=PULSE_count;
								flag_IS_First_PULSE=1;
								if(Pulse_Num==1||Pulse_Num==2)//协议一
								{
										//中心监听到流量计上线后发送上传实时报文和位置信息指令
										//所以只需要上线
										if(0==Connect())
										{
												Is_connected=0x01;
										}
										else
										{
												Is_connected=0x02;//上线失败
										}
																		
								}
								else if(Pulse_Num==3||Pulse_Num==4)//协议二
								{
										
								}
								else if(Pulse_Num==5||Pulse_Num==6)//协议三
								{
										EVC_Read_UserDate2();//读取用户参数2并储存并设定RTC闹钟
								}
						}
				}
				
		}
}
static void RTC_TimeOut_thread_entry(void *parameter)//RTC中断处理:读取flash中的用户参数2，设置最新RTC时钟
{
		int res;
		while(1)
		{
				res=rt_sem_take(sem_RTC_Timeout, RT_WAITING_FOREVER);
				if(res==RT_EOK)
				{	
						if((Is_connected!=0x01)&&(Is_connecting==0x00))//接入外电后，如果未上线,且未正在上线，则上线
						{
								if(0==Connect())
								{
										Is_connected=0x01;	
								}
						}
						//设置下一个RTC时钟
						 EVC_Read_UserDate2();
				}
		}
}

/*-----------——---------------------------------------------------------------------—------中断处理函数--------------------------------------------------------------------------------------------------------*/
//GPIO中断处理函数  
void GPIO_IRQHandler(void)
{
		if(SET == GPIO_EXTI_EXTIISR_ChkEx(GP_TEST_GPIO,GP_TEST_PIN))//外电源检测中断《防止程序运行前已经上外电，应该在程序开始运行时判定一次有无外电》
    {
        GPIO_EXTI_EXTIISR_ClrEx(GP_TEST_GPIO, GP_TEST_PIN);
				GP_TEST_LEVEL=GPIO_ReadInputDataBit(GP_TEST_GPIO,GP_TEST_PIN);
				rt_timer_start(timer_10ms);
		}
		else if(SET == GPIO_EXTI_EXTIISR_ChkEx(PULSE_GPIO,PULSE_PIN))//脉冲检测中断
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

//定时器中断处理函数
static void timeout_10ms(void *parameter)
{
    if(GP_TEST_LEVEL==GPIO_ReadInputDataBit(GP_TEST_GPIO,GP_TEST_PIN))//确定外部电源上电或下电
		{
				rt_sem_release(sem_Thread_Manage);//释放信号量，管理线程获取
		}
}
//定时器中断处理函数，判断接收到几个脉冲，判断协议
static void timeout_1s(void *parameter)
{
		rt_sem_release(sem_Pulse_Process);//
}

static void timeout_2s(void *parameter)
{
		AT_IS_OverTime=1;//定时器超时标志位
}
RTC_TimeDateTypeDef temp;
//RTC定时中断处理函数
void RTC_IRQHandler(void)
{
			
		if( RTC_ISR_SEC_IF_Chk() == SET)//查询秒钟断标志是否置起
		{
				RTC_GetRTC(&temp);
				RTC_ISR_SEC_IF_Clr();		//清除秒中断标志
		}
		if( RTC_ISR_ALARM_IF_Chk() == SET)//查询闹钟钟断标志是否置起
		{		
				RTC_ISR_ALARM_IF_Clr();		//清除闹钟中断标志
				rt_sem_release(sem_RTC_Timeout);////释放信号量 根据用户参数2，设置新的RTC闹钟			
		}	
}



void LPTIM_IRQHandler(void)//LPTIM中断服务程序
{

    if (LPTIM_ISR_OVIF_Chk() == SET)//溢出中断标志被置起
    {
        LPTIM_ISR_OVIF_Clr();//清除中断标志
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

    timer_10ms=rt_timer_create("timer_10ms", timeout_10ms,RT_NULL,  10, RT_TIMER_FLAG_ONE_SHOT);//创建10ms定时器定时器
    timer_1s=rt_timer_create("timer_1s", timeout_1s,RT_NULL,RT_TICK_PER_SECOND,RT_TIMER_FLAG_ONE_SHOT);//创建1s定时器单次定时器
		timer_2s=rt_timer_create("timer_2s",timeout_2s,RT_NULL,2000, RT_TIMER_FLAG_ONE_SHOT );//创建两秒定时器，用于上线是at指令的超时
		sem_Thread_Manage=rt_sem_create("sem_1ms",0,RT_IPC_FLAG_PRIO); 
		sem_Pulse_Process=rt_sem_create("sem_1s",0,RT_IPC_FLAG_PRIO);
		sem_EVC_Uart_Revice=rt_sem_create("sem_uart_recv",0,RT_IPC_FLAG_PRIO);
		sem_GPRS_Uart_Revice=rt_sem_create("sem_uart_recv",0,RT_IPC_FLAG_PRIO);
		sem_RTC_Timeout=rt_sem_create("sem_rtc_timeout",0,RT_IPC_FLAG_PRIO); 
	
		BtimerInit(BT1,20);//初始化基础定时器，定时时长20s,用于at指令超时
		

		
		TM_thread=rt_thread_create("TM",TM_thread_entry,RT_NULL,256,10,10);//外电上下电会有中断，中断开启定时器，定时器中断中确保稳定正确后释放信号量，该线程循环尝试获取该信号量，《感觉多余，直接中断里写不就好了》
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
//		LPTIM_COUNTER_5Min();//开启5分钟定时器，用于定时检查电池电量


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







