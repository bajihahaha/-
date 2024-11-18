#include "uart.h"
uint8_t RECV_FLAG=0x3C;//工商业协议接收标识
uint8_t GPRS_RX_Buffer[BUFFER_SIZE]={0};//接收缓冲区
uint8_t GPRS_TX_Buffer[BUFFER_SIZE]={0};//发送缓冲区
volatile uint16_t GPRS_rx_index = 0;//
volatile uint16_t GPRS_recv_lenth;//接收数据的目标长度
volatile uint8_t GPRS_tx_index = 0;
volatile uint8_t GPRS_tx_length = 0;//发送数据的目标长度

uint8_t EVC_RX_Buffer[BUFFER_SIZE]={0};//接收缓冲区
uint8_t EVC_TX_Buffer[BUFFER_SIZE]={0};//发送缓冲区
volatile uint16_t EVC_rx_index = 0;//
volatile uint16_t EVC_recv_lenth;//接收数据的目标长度
volatile uint8_t EVC_tx_index = 0;
volatile uint8_t EVC_tx_length = 0;//发送数据的目标长度

volatile uint8_t GPRS_recv_state = 0; // 0-6 = recv, 7 = 长度, 9 = 接收数据
uint8_t EVC_byte;
rt_sem_t sem_EVC_Uart_Revice;
volatile uint8_t EVC_recv_state = 0; // 0 = 等待标志, 1 = 等待功能码, 2 = 等待长度，3=接收数据
uint8_t ADDR_CODE=0x03;//EVC地址码
uint8_t GPRS_byte;//

//UART5中断处理函数,用于EVC的UART通信，接收到的数据储存在EVC_RX_Buffer中
void UART5_IRQHandler(void)
{
		//EVC接收中断处理
		if((ENABLE == UARTx_IER_RXBF_IE_Getable(UART5))&&(SET == UARTx_ISR_RXBF_Chk(UART5)))
		{
//			EVC_RX_Buffer[EVC_rx_index++]=UARTx_RXBUF_Read(UART5);
				EVC_byte=UARTx_RXBUF_Read(UART5);
				switch(EVC_recv_state)
				{
					case 0://判断地址码
							if(EVC_byte==ADDR_CODE)
							{
									EVC_rx_index = 0; // 重置索引
									EVC_recv_state=1;
									EVC_RX_Buffer[EVC_rx_index++]=EVC_byte;
							}
							break;
					case 1://接收功能码
							EVC_RX_Buffer[EVC_rx_index++]=EVC_byte;
							EVC_recv_state=2;
							break;
					case 2://数据长度
							if(EVC_RX_Buffer[EVC_rx_index-1]==0x10)
							{
									EVC_recv_lenth=8;
							}
							else
							{
									EVC_recv_lenth = EVC_byte+5;
							}
							if (EVC_recv_lenth <= BUFFER_SIZE)
							{
									EVC_RX_Buffer[EVC_rx_index++]=EVC_byte;
									EVC_recv_state = 3; // 切换到接收数据状态
							}
							else
							{
									EVC_recv_state = 0; // 错误处理，重新等待标志字节
							}
							break;
					case 3://普通数据
								if (EVC_rx_index < EVC_recv_lenth)
                {
                    EVC_RX_Buffer[EVC_rx_index++] = EVC_byte;
                }
                if (EVC_rx_index >= EVC_recv_lenth)
                {
										UARTx_IER_RXBF_IE_Setable(UART5,DISABLE);// 所有数据已发送，禁用接收中断   
										EVC_recv_state = 0; // 重新等待下一个报文 
										rt_sem_release(sem_EVC_Uart_Revice);//释放信号量，要上报的线程获取
                    
                }
							break;
				}		
		}
		//EVC发送中断处理
		if((ENABLE == UARTx_IER_TXSE_IE_Getable(UART5))&&(SET == UARTx_ISR_TXSE_Chk(UART5)))
		{
				if (EVC_tx_index < EVC_tx_length)
        {
            UARTx_TXBUF_Write(UART5, EVC_TX_Buffer[EVC_tx_index++]);
        }
        else
        {
						EVC_tx_index=0;
						UARTx_IER_TXSE_IE_Setable(UART5,DISABLE);// 所有数据已发送，禁用发送中断     
        }
				UARTx_ISR_TXSE_Clr(UART5);// 清除中断标志 
		}
		
		

}

//UART4中断处理函数,用于GPRS的UART通信，接收到的数据储存在GPRS_RX_Buffer中
void UART4_IRQHandler(void)
{
		//GPRS接收中断处理
		if((ENABLE == UARTx_IER_RXBF_IE_Getable(UART4))&&(SET == UARTx_ISR_RXBF_Chk(UART4)))
		{
				if(0x01!=Is_connected)//还未上线，处理EC800返回指令
				{
						GPRS_RX_Buffer[GPRS_rx_index++]=UARTx_RXBUF_Read(UART4);
				}
				else//上线了，处理服务器指令(只进行接收，不通协议的处理在GPRS线程中进行)
				{
						GPRS_byte=UARTx_RXBUF_Read(UART4);
						switch(GPRS_recv_state)//《。。。。。》
						{
							case 0://r
									if(GPRS_byte==0x72)
									{
											GPRS_recv_state=1;
									}
									break;
							case 1://e
									if(GPRS_byte==0x65)
									{ 
											GPRS_recv_state=2;
									}
									else
									{
											GPRS_recv_state=0;
									}
									break;
							case 2://c
									if(GPRS_byte==0x63)
									{ 
											GPRS_recv_state=3;
									}
									else
									{
											GPRS_recv_state=0;
									}
									break;
							case 3://v
									if(GPRS_byte==0x76)
									{ 
											GPRS_recv_state=4;
									}
									else
									{
											GPRS_recv_state=0;
									}
									break;
							case 4://0x22
									if(GPRS_byte==0x22)
									{ 
											GPRS_recv_state=5;
									}
									else
									{
											GPRS_recv_state=0;
									}
									break;
							case 5://0x2C
									if(GPRS_byte==0x2C)
									{ 
											GPRS_rx_index=0;
											GPRS_recv_state=6;
									}
									else
									{
											GPRS_recv_state=0;
									}
									break;
							case 6://等俩个
									if(GPRS_rx_index<1)
									{ 
											GPRS_rx_index++;
									}
									else
									{
										GPRS_recv_state=7;
										GPRS_rx_index=0;
									}
									break;
							case 7://接收长度
									GPRS_recv_lenth=GPRS_byte-0x30;
									GPRS_recv_state=8;
									break;
							case 8://
									if(GPRS_byte!=0x0D)
									{
											GPRS_recv_lenth=GPRS_recv_lenth*10+(GPRS_byte-0x30);
									}
									else
									{
											GPRS_recv_state=9;
									}
									break;
							case 9:
									GPRS_rx_index=0;
									GPRS_recv_state=10;
									break;
							case 10://接收数据
									if(GPRS_rx_index<GPRS_recv_lenth)
									{
											GPRS_RX_Buffer[GPRS_rx_index++]=GPRS_byte;
									}
									else
									{ 
											GPRS_RX_Buffer[GPRS_rx_index++]='\0';
											rt_sem_release(sem_GPRS_Uart_Revice);//释放信号量，要上报的线程获取
											GPRS_recv_state = 0; // 重新等待下一个报文
									}
									break;
									
						}

				}	
		}
		//GPRS发送中断处理
		if((ENABLE == UARTx_IER_TXSE_IE_Getable(UART4))&&(SET == UARTx_ISR_TXSE_Chk(UART4)))
		{
				if (GPRS_tx_index < GPRS_tx_length)
        {
            UARTx_TXBUF_Write(UART4, GPRS_TX_Buffer[GPRS_tx_index++]);
        }
        else
        {
						GPRS_tx_index=0;
						UARTx_IER_TXSE_IE_Setable(UART4,DISABLE);// 所有数据已发送，禁用发送中断     
        }
				UARTx_ISR_TXSE_Clr(UART4);// 清除中断标志 
		}
}
 
void Uartx_Init(UART_Type* UARTx,uint32_t	BaudRate,UART_DataBitTypeDef DataBit,UART_ParityBitTypeDef ParityBit,UART_StopBitTypeDef StopBit)  //UART选择
{

    UART_SInitTypeDef UART_para;
    CMU_ClocksType CMU_Clocks;
    volatile uint08 tmp08;
    volatile uint32_t UART_Frequency;

    if (((uint32_t)UARTx - UART0_BASE)== 0)
    {
        tmp08 =0;
    }	
    else		
    {
        tmp08 = ((((uint32_t)UARTx - UART1_BASE)>>10)+1);	//获取uart	
    }

    switch(tmp08)
    {		
        case 0:    //进行UART0的初始化配置			
        UART_para.ClockSrc = CMU_OPCCR1_UART0CKS_APBCLK;							//UART0工作时钟选择
        /*UART0 IO 配置*/
        AltFunIO(GPIOF, GPIO_Pin_3, 0);		//PF3 UART0 RX
        AltFunIO(GPIOF, GPIO_Pin_4, 0);		//PF4 UART0 TX

			AltFunIO(GPIOG, GPIO_Pin_8, 0);		//PG8 UART0 RX
			AltFunIO(GPIOG, GPIO_Pin_9, 0);		//PG9 UART0 TX
      GPIOx_DFS_Setable(GPIOG,GPIO_Pin_8,ENABLE);      
			GPIOx_DFS_Setable(GPIOG,GPIO_Pin_9,ENABLE);      

        /*NVIC中断配置*/
        NVIC_DisableIRQ(UART0_IRQn);
				NVIC_SetPriority(UART0_IRQn,2);//中断优先级配置
				NVIC_EnableIRQ(UART0_IRQn);	
        break;

        case 1:   //进行UART1的初始化配置			
        UART_para.ClockSrc = CMU_OPCCR1_UART1CKS_APBCLK;	

        /*UART1 IO 配置*/
//		AltFunIO(GPIOB, GPIO_Pin_0, 0);		//PB0 UART1 RX
//		AltFunIO(GPIOB, GPIO_Pin_1, 0);		//PB1 UART1 TX

        AltFunIO(GPIOE, GPIO_Pin_3, 0);		//PE3 UART1 RX
        AltFunIO(GPIOE, GPIO_Pin_4, 0);		//PE4 UART1 TX

        /*NVIC中断配置*/
        NVIC_DisableIRQ(UART1_IRQn);
//		NVIC_SetPriority(UART1_IRQn,2);//中断优先级配置
//		NVIC_EnableIRQ(UART1_IRQn);	
        break;

        case 2:   //进行UART2的初始化配置								
        /*UART2 IO 配置*/
//		AltFunIO(GPIOB, GPIO_Pin_2, 0);		//PB2 UART2 RX
//		AltFunIO(GPIOB, GPIO_Pin_3, 0);		//PB3 UART2 TX	

        AltFunIO(GPIOB, GPIO_Pin_12, 0);	//PB12 UART2 RX
        AltFunIO(GPIOB, GPIO_Pin_13, 0);	//PB13 UART2 TX			

        /*NVIC中断配置*/
        NVIC_DisableIRQ(UART2_IRQn);
//		NVIC_SetPriority(UART2_IRQn,2);//中断优先级配置
//		NVIC_EnableIRQ(UART2_IRQn);	
        break;

        case 3:   //进行UART3的初始化配置					
        /*UART3 IO 配置*/
        AltFunIO(GPIOC, GPIO_Pin_10, 0);	//PC10 UART3 RX
        AltFunIO(GPIOC, GPIO_Pin_11, 0);	//PC11 UART3 TX

//		AltFunIO(GPIOB, GPIO_Pin_14, 0);	//PB14 UART3 RX
//		AltFunIO(GPIOB, GPIO_Pin_15, 0);	//PB15 UART3 TX

        /*NVIC中断配置*/
        NVIC_DisableIRQ(UART3_IRQn);
//		NVIC_SetPriority(UART3_IRQn,2);//中断优先级配置
//		NVIC_EnableIRQ(UART3_IRQn);	
        break;

        case 4:   //进行UART4的初始化配置								
        /*UART4 IO 配置*/
//        AltFunIO(GPIOD, GPIO_Pin_0, 0);		//PD0 UART4 RX
//        AltFunIO(GPIOD, GPIO_Pin_1, 0);		//PD1 UART4 TX
        //仅100脚
				AltFunIO(GPIOD, GPIO_Pin_9, 0);		//PD9 UART4 RX
				AltFunIO(GPIOD, GPIO_Pin_10, 0);	//PD10 UART4 TX

        /*NVIC中断配置*/
        NVIC_DisableIRQ(UART4_IRQn);
				NVIC_SetPriority(UART4_IRQn,2);//中断优先级配置
				NVIC_EnableIRQ(UART4_IRQn);	
        break;

        case 5:   //进行UART5的初始化配置				
        /*UART5 IO 配置*/
//        AltFunIO(GPIOC, GPIO_Pin_4, 0);		//PC4 UART5 RX
//        AltFunIO(GPIOC, GPIO_Pin_5, 0);		//PC5 UART5 TX	

		AltFunIO(GPIOA, GPIO_Pin_8, 0);		//PA8 UART5 RX
		AltFunIO(GPIOA, GPIO_Pin_9, 0);		//PA9 UART5 TX	

        /*NVIC中断配置*/
        NVIC_DisableIRQ(UART5_IRQn);
		NVIC_SetPriority(UART5_IRQn,2);//中断优先级配置
		NVIC_EnableIRQ(UART5_IRQn);	
        break;

        default:
        break;
        }
    //UART初始化配置
    UART_para.BaudRate = BaudRate;			//波特率
    UART_para.DataBit = DataBit;	//数据位数
    UART_para.ParityBit = ParityBit;			//奇偶校验
    UART_para.StopBit = StopBit;			//停止位
        
    CMU_GetClocksFreq(&CMU_Clocks);    
    UART_SInit(UARTx, &UART_para,&CMU_Clocks);	//初始化uart
}

void Uartx_Enable(UART_Type* UARTx)//
{
		UARTx_CSR_RXEN_Setable(UARTx, ENABLE);  //打开接收使能
		UARTx_CSR_TXEN_Setable(UARTx, ENABLE);  //打开发送使能
}
//UART5开始发送EVC_TX_Buffer中的数据
void UART5_Send()
{
		EVC_tx_index=0;

		UARTx_IER_RXBF_IE_Setable(UART5,ENABLE); //接收缓存空且移位寄存器空中断使能
		UARTx_IER_TXSE_IE_Setable(UART5, ENABLE); //发送缓存空且移位寄存器空中断使能		
		UARTx_ISR_RXBF_Clr(UART5);	//清除接收中断标志
		UARTx_ISR_TXSE_Clr(UART5);	//清除发送中断标志
		UARTx_TXBUF_Write(UART5,EVC_TX_Buffer[EVC_tx_index++]); //发送第一个数据启动发送
}
//UART4开始发送GPRS_TX_Buffer中的数据
void UART4_Send()
{
		GPRS_tx_index=0;
		UARTx_ISR_RXBF_Clr(UART4);	//清除接收中断标志
		UARTx_ISR_TXSE_Clr(UART4);	//清除发送中断标志
		UARTx_IER_RXBF_IE_Setable(UART4,ENABLE); //接收缓存空且移位寄存器空中断使能
		UARTx_IER_TXSE_IE_Setable(UART4, ENABLE); //发送缓存空且移位寄存器空中断使能
		UARTx_TXBUF_Write(UART4,GPRS_TX_Buffer[GPRS_tx_index++]); //发送第一个数据启动发送
}
	




