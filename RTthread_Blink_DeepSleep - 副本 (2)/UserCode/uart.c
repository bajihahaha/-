#include "uart.h"
uint8_t RECV_FLAG=0x3C;//����ҵЭ����ձ�ʶ
uint8_t GPRS_RX_Buffer[BUFFER_SIZE]={0};//���ջ�����
uint8_t GPRS_TX_Buffer[BUFFER_SIZE]={0};//���ͻ�����
volatile uint16_t GPRS_rx_index = 0;//
volatile uint16_t GPRS_recv_lenth;//�������ݵ�Ŀ�곤��
volatile uint8_t GPRS_tx_index = 0;
volatile uint8_t GPRS_tx_length = 0;//�������ݵ�Ŀ�곤��

uint8_t EVC_RX_Buffer[BUFFER_SIZE]={0};//���ջ�����
uint8_t EVC_TX_Buffer[BUFFER_SIZE]={0};//���ͻ�����
volatile uint16_t EVC_rx_index = 0;//
volatile uint16_t EVC_recv_lenth;//�������ݵ�Ŀ�곤��
volatile uint8_t EVC_tx_index = 0;
volatile uint8_t EVC_tx_length = 0;//�������ݵ�Ŀ�곤��

volatile uint8_t GPRS_recv_state = 0; // 0-6 = recv, 7 = ����, 9 = ��������
uint8_t EVC_byte;
rt_sem_t sem_EVC_Uart_Revice;
volatile uint8_t EVC_recv_state = 0; // 0 = �ȴ���־, 1 = �ȴ�������, 2 = �ȴ����ȣ�3=��������
uint8_t ADDR_CODE=0x03;//EVC��ַ��
uint8_t GPRS_byte;//

//UART5�жϴ�����,����EVC��UARTͨ�ţ����յ������ݴ�����EVC_RX_Buffer��
void UART5_IRQHandler(void)
{
		//EVC�����жϴ���
		if((ENABLE == UARTx_IER_RXBF_IE_Getable(UART5))&&(SET == UARTx_ISR_RXBF_Chk(UART5)))
		{
//			EVC_RX_Buffer[EVC_rx_index++]=UARTx_RXBUF_Read(UART5);
				EVC_byte=UARTx_RXBUF_Read(UART5);
				switch(EVC_recv_state)
				{
					case 0://�жϵ�ַ��
							if(EVC_byte==ADDR_CODE)
							{
									EVC_rx_index = 0; // ��������
									EVC_recv_state=1;
									EVC_RX_Buffer[EVC_rx_index++]=EVC_byte;
							}
							break;
					case 1://���չ�����
							EVC_RX_Buffer[EVC_rx_index++]=EVC_byte;
							EVC_recv_state=2;
							break;
					case 2://���ݳ���
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
									EVC_recv_state = 3; // �л�����������״̬
							}
							else
							{
									EVC_recv_state = 0; // ���������µȴ���־�ֽ�
							}
							break;
					case 3://��ͨ����
								if (EVC_rx_index < EVC_recv_lenth)
                {
                    EVC_RX_Buffer[EVC_rx_index++] = EVC_byte;
                }
                if (EVC_rx_index >= EVC_recv_lenth)
                {
										UARTx_IER_RXBF_IE_Setable(UART5,DISABLE);// ���������ѷ��ͣ����ý����ж�   
										EVC_recv_state = 0; // ���µȴ���һ������ 
										rt_sem_release(sem_EVC_Uart_Revice);//�ͷ��ź�����Ҫ�ϱ����̻߳�ȡ
                    
                }
							break;
				}		
		}
		//EVC�����жϴ���
		if((ENABLE == UARTx_IER_TXSE_IE_Getable(UART5))&&(SET == UARTx_ISR_TXSE_Chk(UART5)))
		{
				if (EVC_tx_index < EVC_tx_length)
        {
            UARTx_TXBUF_Write(UART5, EVC_TX_Buffer[EVC_tx_index++]);
        }
        else
        {
						EVC_tx_index=0;
						UARTx_IER_TXSE_IE_Setable(UART5,DISABLE);// ���������ѷ��ͣ����÷����ж�     
        }
				UARTx_ISR_TXSE_Clr(UART5);// ����жϱ�־ 
		}
		
		

}

//UART4�жϴ�����,����GPRS��UARTͨ�ţ����յ������ݴ�����GPRS_RX_Buffer��
void UART4_IRQHandler(void)
{
		//GPRS�����жϴ���
		if((ENABLE == UARTx_IER_RXBF_IE_Getable(UART4))&&(SET == UARTx_ISR_RXBF_Chk(UART4)))
		{
				if(0x01!=Is_connected)//��δ���ߣ�����EC800����ָ��
				{
						GPRS_RX_Buffer[GPRS_rx_index++]=UARTx_RXBUF_Read(UART4);
				}
				else//�����ˣ����������ָ��(ֻ���н��գ���ͨЭ��Ĵ�����GPRS�߳��н���)
				{
						GPRS_byte=UARTx_RXBUF_Read(UART4);
						switch(GPRS_recv_state)//��������������
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
							case 6://������
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
							case 7://���ճ���
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
							case 10://��������
									if(GPRS_rx_index<GPRS_recv_lenth)
									{
											GPRS_RX_Buffer[GPRS_rx_index++]=GPRS_byte;
									}
									else
									{ 
											GPRS_RX_Buffer[GPRS_rx_index++]='\0';
											rt_sem_release(sem_GPRS_Uart_Revice);//�ͷ��ź�����Ҫ�ϱ����̻߳�ȡ
											GPRS_recv_state = 0; // ���µȴ���һ������
									}
									break;
									
						}

				}	
		}
		//GPRS�����жϴ���
		if((ENABLE == UARTx_IER_TXSE_IE_Getable(UART4))&&(SET == UARTx_ISR_TXSE_Chk(UART4)))
		{
				if (GPRS_tx_index < GPRS_tx_length)
        {
            UARTx_TXBUF_Write(UART4, GPRS_TX_Buffer[GPRS_tx_index++]);
        }
        else
        {
						GPRS_tx_index=0;
						UARTx_IER_TXSE_IE_Setable(UART4,DISABLE);// ���������ѷ��ͣ����÷����ж�     
        }
				UARTx_ISR_TXSE_Clr(UART4);// ����жϱ�־ 
		}
}
 
void Uartx_Init(UART_Type* UARTx,uint32_t	BaudRate,UART_DataBitTypeDef DataBit,UART_ParityBitTypeDef ParityBit,UART_StopBitTypeDef StopBit)  //UARTѡ��
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
        tmp08 = ((((uint32_t)UARTx - UART1_BASE)>>10)+1);	//��ȡuart	
    }

    switch(tmp08)
    {		
        case 0:    //����UART0�ĳ�ʼ������			
        UART_para.ClockSrc = CMU_OPCCR1_UART0CKS_APBCLK;							//UART0����ʱ��ѡ��
        /*UART0 IO ����*/
        AltFunIO(GPIOF, GPIO_Pin_3, 0);		//PF3 UART0 RX
        AltFunIO(GPIOF, GPIO_Pin_4, 0);		//PF4 UART0 TX

			AltFunIO(GPIOG, GPIO_Pin_8, 0);		//PG8 UART0 RX
			AltFunIO(GPIOG, GPIO_Pin_9, 0);		//PG9 UART0 TX
      GPIOx_DFS_Setable(GPIOG,GPIO_Pin_8,ENABLE);      
			GPIOx_DFS_Setable(GPIOG,GPIO_Pin_9,ENABLE);      

        /*NVIC�ж�����*/
        NVIC_DisableIRQ(UART0_IRQn);
				NVIC_SetPriority(UART0_IRQn,2);//�ж����ȼ�����
				NVIC_EnableIRQ(UART0_IRQn);	
        break;

        case 1:   //����UART1�ĳ�ʼ������			
        UART_para.ClockSrc = CMU_OPCCR1_UART1CKS_APBCLK;	

        /*UART1 IO ����*/
//		AltFunIO(GPIOB, GPIO_Pin_0, 0);		//PB0 UART1 RX
//		AltFunIO(GPIOB, GPIO_Pin_1, 0);		//PB1 UART1 TX

        AltFunIO(GPIOE, GPIO_Pin_3, 0);		//PE3 UART1 RX
        AltFunIO(GPIOE, GPIO_Pin_4, 0);		//PE4 UART1 TX

        /*NVIC�ж�����*/
        NVIC_DisableIRQ(UART1_IRQn);
//		NVIC_SetPriority(UART1_IRQn,2);//�ж����ȼ�����
//		NVIC_EnableIRQ(UART1_IRQn);	
        break;

        case 2:   //����UART2�ĳ�ʼ������								
        /*UART2 IO ����*/
//		AltFunIO(GPIOB, GPIO_Pin_2, 0);		//PB2 UART2 RX
//		AltFunIO(GPIOB, GPIO_Pin_3, 0);		//PB3 UART2 TX	

        AltFunIO(GPIOB, GPIO_Pin_12, 0);	//PB12 UART2 RX
        AltFunIO(GPIOB, GPIO_Pin_13, 0);	//PB13 UART2 TX			

        /*NVIC�ж�����*/
        NVIC_DisableIRQ(UART2_IRQn);
//		NVIC_SetPriority(UART2_IRQn,2);//�ж����ȼ�����
//		NVIC_EnableIRQ(UART2_IRQn);	
        break;

        case 3:   //����UART3�ĳ�ʼ������					
        /*UART3 IO ����*/
        AltFunIO(GPIOC, GPIO_Pin_10, 0);	//PC10 UART3 RX
        AltFunIO(GPIOC, GPIO_Pin_11, 0);	//PC11 UART3 TX

//		AltFunIO(GPIOB, GPIO_Pin_14, 0);	//PB14 UART3 RX
//		AltFunIO(GPIOB, GPIO_Pin_15, 0);	//PB15 UART3 TX

        /*NVIC�ж�����*/
        NVIC_DisableIRQ(UART3_IRQn);
//		NVIC_SetPriority(UART3_IRQn,2);//�ж����ȼ�����
//		NVIC_EnableIRQ(UART3_IRQn);	
        break;

        case 4:   //����UART4�ĳ�ʼ������								
        /*UART4 IO ����*/
//        AltFunIO(GPIOD, GPIO_Pin_0, 0);		//PD0 UART4 RX
//        AltFunIO(GPIOD, GPIO_Pin_1, 0);		//PD1 UART4 TX
        //��100��
				AltFunIO(GPIOD, GPIO_Pin_9, 0);		//PD9 UART4 RX
				AltFunIO(GPIOD, GPIO_Pin_10, 0);	//PD10 UART4 TX

        /*NVIC�ж�����*/
        NVIC_DisableIRQ(UART4_IRQn);
				NVIC_SetPriority(UART4_IRQn,2);//�ж����ȼ�����
				NVIC_EnableIRQ(UART4_IRQn);	
        break;

        case 5:   //����UART5�ĳ�ʼ������				
        /*UART5 IO ����*/
//        AltFunIO(GPIOC, GPIO_Pin_4, 0);		//PC4 UART5 RX
//        AltFunIO(GPIOC, GPIO_Pin_5, 0);		//PC5 UART5 TX	

		AltFunIO(GPIOA, GPIO_Pin_8, 0);		//PA8 UART5 RX
		AltFunIO(GPIOA, GPIO_Pin_9, 0);		//PA9 UART5 TX	

        /*NVIC�ж�����*/
        NVIC_DisableIRQ(UART5_IRQn);
		NVIC_SetPriority(UART5_IRQn,2);//�ж����ȼ�����
		NVIC_EnableIRQ(UART5_IRQn);	
        break;

        default:
        break;
        }
    //UART��ʼ������
    UART_para.BaudRate = BaudRate;			//������
    UART_para.DataBit = DataBit;	//����λ��
    UART_para.ParityBit = ParityBit;			//��żУ��
    UART_para.StopBit = StopBit;			//ֹͣλ
        
    CMU_GetClocksFreq(&CMU_Clocks);    
    UART_SInit(UARTx, &UART_para,&CMU_Clocks);	//��ʼ��uart
}

void Uartx_Enable(UART_Type* UARTx)//
{
		UARTx_CSR_RXEN_Setable(UARTx, ENABLE);  //�򿪽���ʹ��
		UARTx_CSR_TXEN_Setable(UARTx, ENABLE);  //�򿪷���ʹ��
}
//UART5��ʼ����EVC_TX_Buffer�е�����
void UART5_Send()
{
		EVC_tx_index=0;

		UARTx_IER_RXBF_IE_Setable(UART5,ENABLE); //���ջ��������λ�Ĵ������ж�ʹ��
		UARTx_IER_TXSE_IE_Setable(UART5, ENABLE); //���ͻ��������λ�Ĵ������ж�ʹ��		
		UARTx_ISR_RXBF_Clr(UART5);	//��������жϱ�־
		UARTx_ISR_TXSE_Clr(UART5);	//��������жϱ�־
		UARTx_TXBUF_Write(UART5,EVC_TX_Buffer[EVC_tx_index++]); //���͵�һ��������������
}
//UART4��ʼ����GPRS_TX_Buffer�е�����
void UART4_Send()
{
		GPRS_tx_index=0;
		UARTx_ISR_RXBF_Clr(UART4);	//��������жϱ�־
		UARTx_ISR_TXSE_Clr(UART4);	//��������жϱ�־
		UARTx_IER_RXBF_IE_Setable(UART4,ENABLE); //���ջ��������λ�Ĵ������ж�ʹ��
		UARTx_IER_TXSE_IE_Setable(UART4, ENABLE); //���ͻ��������λ�Ĵ������ж�ʹ��
		UARTx_TXBUF_Write(UART4,GPRS_TX_Buffer[GPRS_tx_index++]); //���͵�һ��������������
}
	




