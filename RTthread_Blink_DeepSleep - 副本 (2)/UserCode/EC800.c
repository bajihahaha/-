#include "EC800.h"
#include "sleep.h"
uint8_t ICCID[20];
uint8_t Is_connected=0x00;//0x00下线 0x01上线成功  0x02上线失败  该变量根据connenct函数返回值判断
uint8_t Is_connecting=0x00;
int  AT_IS_OverTime=0;
uint8_t Signal_Strength=0x99;
extern rt_timer_t timer_2s;

void Send_AT_Command(char flag)
{
    uint8_t at_cpin[] = {0x41, 0x54, 0x2B, 0x43, 0x50, 0x49, 0x4E, 0x3F, 0x0D, 0x0A, 0x00};      // AT+CPIN?
    //uint8_t at_creg[] = {0x41, 0x54, 0x2B, 0x43, 0x52, 0x45, 0x47, 0x3F, 0x0D, 0x0A, 0x00};      // AT+CREG?
		uint8_t at_creg[] = {0x41, 0x54, 0x2B, 0x43, 0x52, 0x45, 0x47, 0x3D, 0x32, 0x0D, 0x0A, 0x00}; // AT+CREG=2
    uint8_t at_cereg[] = {0x41, 0x54, 0x2B, 0x43, 0x45, 0x52, 0x45, 0x47, 0x3F, 0x0D, 0x0A, 0x00}; // AT+CEREG?
    uint8_t at_qicsgp[] = {0x41, 0x54, 0x2B, 0x51, 0x49, 0x43, 0x53, 0x47, 0x50, 0x3D, 0x31, 0x2C, 0x31, 0x2C, 0x22, 0x43, 0x4D, 0x4E, 0x45, 0x54, 0x22, 0x2C, 0x22, 0x22, 0x2C, 0x22, 0x22, 0x2C, 0x30, 0x0D, 0x0A, 0x00}; // AT+QICSGP=1,1,"CMNET","","",0
    //uint8_t at_qiact[] = {0x41, 0x54, 0x2B, 0x51, 0x49, 0x41, 0x43, 0x54, 0x3D, 0x31, 0x0D, 0x0A, 0x00};
		uint8_t at_qiact[] = {0x41, 0x54, 0x2B, 0x51, 0x49, 0x41, 0x43, 0x54, 0x3F, 0x0D, 0x0A, 0x00};
    uint8_t at_qiopen[] = {0x41, 0x54, 0x2B, 0x51, 0x49, 0x4F, 0x50, 0x45, 0x4E, 0x3D, 0x31, 0x2C, 0x30, 0x2C, 0x22, 0x54, 0x43, 0x50, 0x22, 0x2C, 0x22, 0x31, 0x2E, 0x39, 0x34, 0x2E, 0x31, 0x32, 0x35, 0x2E, 0x31, 0x32, 0x34, 0x22, 0x2C, 0x38, 0x38, 0x38, 0x38, 0x2C, 0x30, 0x2C, 0x31, 0x0D, 0x0A, 0x00};
		//uint8_t at_qiopen[] = {0x41, 0x54, 0x2B, 0x51, 0x49, 0x4F, 0x50, 0x45, 0x4E, 0x3D, 0x31, 0x2C, 0x30, 0x2C, 0x22, 0x54, 0x43, 0x50, 0x22, 0x2C, 0x22, 0x31, 0x32, 0x30, 0x2E, 0x32, 0x36, 0x2E, 0x34, 0x30, 0x2E, 0x31, 0x39, 0x32, 0x22, 0x2C, 0x38, 0x38, 0x38, 0x38, 0x2C, 0x30, 0x2C, 0x31, 0x0D, 0x0A, 0x00};
    uint8_t at_qisend[] = {0x41, 0x54, 0x2B, 0x51, 0x49, 0x53, 0x45, 0x4E, 0x44, 0x3D, 0x30, 0x0D, 0x0A,0x00};
    uint8_t at_csq[] = {0x41, 0x54, 0x2B, 0x43, 0x53, 0x51, 0x0D, 0x0A, 0x00};
/*9*/uint8_t hello[] ={0x48, 0x65, 0x6C, 0x6C, 0x6F,0x1A,0x00};
/*10*/uint8_t at_qiclose[] = {0x41, 0x54, 0x2B, 0x51, 0x49, 0x43, 0x4C, 0x4F, 0x53, 0x45, 0x3D, 0x30, 0x0D, 0x0A, 0x00};
		uint8_t at_qideact[]={0x41, 0x54, 0x2B, 0x51, 0x49, 0x44, 0x45, 0x41, 0x43, 0x54, 0x3D, 0x31, 0x0D, 0x0A, 0x00};
		uint8_t at_qccid[] = {0x41, 0x54, 0x2B, 0x51, 0x43, 0x43, 0x49, 0x44, 0x0D, 0x0A, 0x00}; // AT+QCCID


	


    
    switch(flag)
    {
        case '1':
						GPRS_tx_length=sizeof(at_cpin);
						memcpy(GPRS_TX_Buffer,at_cpin,GPRS_tx_length);
            UART4_Send();
            break;
        case '2':
						GPRS_tx_length=sizeof(at_creg);
            memcpy(GPRS_TX_Buffer,at_creg,GPRS_tx_length);
            UART4_Send();
            break;
        case '3':
						GPRS_tx_length=sizeof(at_cereg);
            memcpy(GPRS_TX_Buffer,at_cereg,GPRS_tx_length);
            UART4_Send();
            break;
        case '4':
						GPRS_tx_length=sizeof(at_qicsgp);
            memcpy(GPRS_TX_Buffer,at_qicsgp,GPRS_tx_length);
            UART4_Send();
            break;  
        case '5':
						GPRS_tx_length=sizeof(at_csq);
            memcpy(GPRS_TX_Buffer,at_csq,GPRS_tx_length);
						UART4_Send();
            break;
        case '6':
						GPRS_tx_length=sizeof(at_qiact);
            memcpy(GPRS_TX_Buffer,at_qiact,GPRS_tx_length);
            UART4_Send();
            break; 
        case '7':
						GPRS_tx_length=sizeof(at_qiopen);
            memcpy(GPRS_TX_Buffer,at_qiopen,GPRS_tx_length);
            UART4_Send();
            break; 
        case '8':
						GPRS_tx_length=sizeof(at_qisend);
            memcpy(GPRS_TX_Buffer,at_qisend,GPRS_tx_length);
            UART4_Send();
            break;
        case '9':
						GPRS_tx_length=sizeof(hello);
            memcpy(GPRS_TX_Buffer,hello,GPRS_tx_length);
            UART4_Send();
            break; 
				case 'A':
						GPRS_tx_length=sizeof(at_qiclose);
            memcpy(GPRS_TX_Buffer,at_qiclose,GPRS_tx_length);
            UART4_Send();
            break;
				case 'B':
						GPRS_tx_length=sizeof(at_qideact);
            memcpy(GPRS_TX_Buffer,at_qideact,GPRS_tx_length);
            UART4_Send();
            break;	
				case 'C':
						GPRS_tx_length=sizeof(at_qccid);
            memcpy(GPRS_TX_Buffer,at_qccid,GPRS_tx_length);
            UART4_Send();
    }
}


void Restart()
{
		GPIO_SetBits(SPC_EN_GPIO,SPC_EN_PIN);
		GPIO_SetBits(GP_CON_GPIO,GP_CON_PIN);
		rt_thread_mdelay(2000);
		GPIO_ResetBits(SPC_EN_GPIO,SPC_EN_PIN);
		GPIO_ResetBits(GP_CON_GPIO,GP_CON_PIN);
}


void Disconnect()
{
		AT_IS_OverTime=0;
		Send_AT_Command('A');//close
		BtimerStart(BT1);
		while((strstr((char *)GPRS_RX_Buffer,",OK\r\n")==NULL)&(AT_IS_OverTime!=1))
		{
				
		}
		BtimerStop(BT1);
		memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
		GPRS_recv_lenth=0;
		GPRS_rx_index=0;
		GPIO_SetBits(SPC_EN_GPIO,SPC_EN_PIN);
		GPIO_SetBits(GP_CON_GPIO,GP_CON_PIN);
		GPIO_ResetBits(LED_RED_GPIO,LED_RED_PIN);
		Is_connected=0x00;
		DeepSleep();
		
}



int  Connect()//上线函数，成功返回0，失败返回错误码《只是TCP的上线，其他的呢？》
{
		int Restart_Times=0;
		Is_connecting=0x01;
to_START:	
		//rt_thread_mdelay(1000);//下电和上电的间隔
		GPIO_ResetBits(SPC_EN_GPIO,SPC_EN_PIN);
		GPIO_ResetBits(GP_CON_GPIO,GP_CON_PIN);
		UARTx_ISR_RXBF_Clr(UART4);	//清除接收中断标志
		UARTx_IER_RXBF_IE_Setable(UART4,ENABLE); //接收缓存空且移位寄存器空中断使能
	  GPRS_recv_lenth=0;
		GPRS_rx_index=0;
//		while(strstr((char *)GPRS_RX_Buffer,"RDY\r\n")==NULL)
//		{
//				if(GPRS_rx_index>0)
//				{
//					if(GPRS_RX_Buffer[GPRS_rx_index-1]==0x21)
//					{
//							GPRS_rx_index=0;
//					}
//				}
//		}
    rt_thread_mdelay(3000);
		if(strstr((char *)(GPRS_RX_Buffer+20),"RDY\r\n")==NULL)
		{
				return 999;
		}
		
    memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
    GPRS_recv_lenth=0;
		GPRS_rx_index=0;

to_CPIN:
		AT_IS_OverTime=0;
		BtimerStart(BT1);
    Send_AT_Command('1');	//CPIN,20s内识别不到SIM卡，重启模块
    while((strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)&(!AT_IS_OverTime))
    {
        
    }
		BtimerStop(BT1);
    if(strstr((char *)GPRS_RX_Buffer,"READY\r\n")==NULL)
    {
				//重启模块
				if(Restart_Times<3)
				{	
						Restart();
						Restart_Times++;
						goto to_START;
				}
				else
				{
						return CPIN;
				}
    }
    memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
		GPRS_rx_index=0;
    GPRS_recv_lenth=0;
		
		AT_IS_OverTime=0;
		BtimerStart(BT1);
    Send_AT_Command('C');//CCID
    while((strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)&(AT_IS_OverTime!=1))
    {
        
    }
		BtimerStop(BT1);
    if(strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)
    {
        return CCID;
    }
		//获取ICCID
		memcpy(ICCID,&GPRS_RX_Buffer[19],20);
    memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
    GPRS_recv_lenth=0;
		GPRS_rx_index=0;
		

		AT_IS_OverTime=0;
		BtimerStart(BT1);
    Send_AT_Command('2');//CREG
    while((strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)&(AT_IS_OverTime!=1))
    {
        
    }
		BtimerStop(BT1);
    if(strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)
    {
        return CREG;
    }
    memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
    GPRS_recv_lenth=0;
		GPRS_rx_index=0;
		
		AT_IS_OverTime=0;
		BtimerStart(BT1);
    Send_AT_Command('3');//CEREG
    while((strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)&(AT_IS_OverTime!=1))
    {
        
    }
		BtimerStop(BT1);
    if(strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)
    {
        return CEREG;
    }
    memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
    GPRS_recv_lenth=0;
		GPRS_rx_index=0;
		
		AT_IS_OverTime=0;
    Send_AT_Command('4');//qicsgp
		BtimerStart(BT1);
    while((strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)&(AT_IS_OverTime!=1))
    {
        
    }
		BtimerStop(BT1);
    if(strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)
    {
        return CSGP;
    }
    memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
    GPRS_recv_lenth=0;
		GPRS_rx_index=0;

		AT_IS_OverTime=0;
		BtimerStart(BT1);
    Send_AT_Command('5');//csq

    while((strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)&(AT_IS_OverTime!=1))
    {
        
    }
		BtimerStop(BT1);		
    if(strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)
    {
        return CSQ;
    }
    //读取信号值
		Signal_Strength=0;
		Signal_Strength+=((GPRS_RX_Buffer[15]-0x30)<<4);
		Signal_Strength+=(GPRS_RX_Buffer[16]-0x30);
    memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
    GPRS_recv_lenth=0;
		GPRS_rx_index=0;
	
    Send_AT_Command('6');//act
		AT_IS_OverTime=0;
		BtimerStart(BT1);
    while((strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)&(AT_IS_OverTime!=1))
    {
        
    }
		BtimerStop(BT1);
//    if(strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)
//    {
//        return ACT;
//    }
    memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
    //rt_thread_mdelay(300);

    GPRS_recv_lenth=0;
		GPRS_rx_index=0;
		
		if(AT_IS_OverTime)//如果act失败执行反act
		{
			Send_AT_Command('B');
			AT_IS_OverTime=0;
			BtimerStart(BT1);
			while((strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)&(AT_IS_OverTime!=1))
			{
        
			}
			BtimerStop(BT1);
			if(strstr((char *)GPRS_RX_Buffer,"OK\r\n")==NULL)
			{
        return DEACT;
			}
			memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
			//rt_thread_mdelay(300);
			GPRS_recv_lenth=0;
			GPRS_rx_index=0;
			goto to_CPIN;
		}
		
to_OPEN:		
		AT_IS_OverTime=0;
    Send_AT_Command('7');//open
		BtimerStart(BT1);
    while((strstr((char *)GPRS_RX_Buffer,",0\r\n")==NULL)&(AT_IS_OverTime!=1))
    {
        
    }
		BtimerStop(BT1);
    if(strstr((char *)GPRS_RX_Buffer,"+QIOPEN: 0,0\r\n")==NULL)
    {
				
        //return OPEN;
    }
    memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
    GPRS_recv_lenth=0;
		GPRS_rx_index=0;
		
		if(AT_IS_OverTime)
		{
				AT_IS_OverTime=0;
				Send_AT_Command('A');//close
				BtimerStart(BT1);
				while((strstr((char *)GPRS_RX_Buffer,",OK\r\n")==NULL)&(AT_IS_OverTime!=1))
				{
						
				}
				BtimerStop(BT1);
				if(strstr((char *)GPRS_RX_Buffer,"OK")==NULL)
				{
						return CLOSE;
				}
				memset((char *)GPRS_RX_Buffer,0,sizeof(GPRS_RX_Buffer));
				GPRS_recv_lenth=0;
				GPRS_rx_index=0;
				goto to_OPEN;
		}
		Is_connecting=0x00;
		GPIO_SetBits(LED_RED_GPIO,LED_RED_PIN);
    return 0;
}
