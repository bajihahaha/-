#include "sleep.h"
#include "define_all.h"  

// DeepSleep
void DeepSleep(void)
{
    PMU_SleepCfg_InitTypeDef SleepCfg_InitStruct;
    CDIF_CR_INTF_EN_Setable(ENABLE);
    /*下电复位配置*/
    //pdr和bor两个下电复位至少要打开一个
    //当电源电压低于下电复位时，芯片会被复位住	
    //pdr电压档位不准但是功耗极低(几乎无测量）
    //bor电压档位准确但是需要增加2uA功耗
    RMU_PDRCR_PDREN_Setable(ENABLE);		//打开PDR
    RMU_PDRCR_PDRCFG_Set(RMU_PDRCR_PDRCFG_1P5V);//pdr电压调整到1.4V
    RMU_BORCR_OFF_BOR_Setable(ENABLE);	//关闭BOR
    VRTC_RCMFCR_EN_Setable(DISABLE);//RCMF关闭
    //VRTC_RCLPCR_RCLP_OFF_Setable(ENABLE);//RCLP关闭

    CDIF_CR_INTF_EN_Setable(DISABLE);
    SleepCfg_InitStruct.PMOD = PMU_CR_PMOD_SLEEP;			//功耗模式配置
    SleepCfg_InitStruct.SLPDP = PMU_CR_SLPDP_DEEPSLEEP;			//deepsleep
    SleepCfg_InitStruct.CVS = DISABLE;							//内核电压降低控制
    SleepCfg_InitStruct.SCR = 0;								//M0系统控制寄存器，一般配置为0即可	
    SleepCfg_InitStruct.TIA = PMU_WKTR_T1A_8US;//可编程额外唤醒延迟8us

    PMU_SleepCfg_Init(&SleepCfg_InitStruct);//休眠配置

    IWDT_Clr();	//首先进行一次喂狗用中文回答

    __WFI();//进入休眠
    IWDT_Clr();	
    RMU_BORCR_OFF_BOR_Setable(DISABLE);
}


// Sleep
void Sleep(void)
{
    PMU_SleepCfg_InitTypeDef SleepCfg_InitStruct;
    CDIF_CR_INTF_EN_Setable(ENABLE);
    /*下电复位配置*/
    //pdr和bor两个下电复位至少要打开一个
    //当电源电压低于下电复位时，芯片会被复位住	
    //pdr电压档位不准但是功耗极低(几乎无测量）
    //bor电压档位准确但是需要增加2uA功耗
    RMU_PDRCR_PDREN_Setable(ENABLE);		//打开PDR
    RMU_PDRCR_PDRCFG_Set(RMU_PDRCR_PDRCFG_1P5V);//pdr电压调整到1.4V
    RMU_BORCR_OFF_BOR_Setable(ENABLE);	//关闭BOR
    VRTC_RCMFCR_EN_Setable(DISABLE);//RCMF关闭
    //VRTC_RCLPCR_RCLP_OFF_Setable(ENABLE);//RCLP关闭

    CDIF_CR_INTF_EN_Setable(DISABLE);
    SleepCfg_InitStruct.PMOD = PMU_CR_PMOD_SLEEP;			//功耗模式配置
    SleepCfg_InitStruct.SLPDP = PMU_CR_SLPDP_SLEEP;			//deepsleep
    SleepCfg_InitStruct.CVS = DISABLE;							//内核电压降低控制
    SleepCfg_InitStruct.SCR = 0;								//M0系统控制寄存器，一般配置为0即可	
    SleepCfg_InitStruct.TIA = PMU_WKTR_T1A_8US;//可编程额外唤醒延迟8us

    PMU_SleepCfg_Init(&SleepCfg_InitStruct);//休眠配置

    IWDT_Clr();	
    __WFI();//进入休眠
    IWDT_Clr();	
    RMU_BORCR_OFF_BOR_Setable(DISABLE);
}

