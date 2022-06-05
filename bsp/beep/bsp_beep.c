#include "bsp_beep.h"



/* BEEP初始化*/
void beep_init(void)
{
    //复用
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0);
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0x10B0);
    GPIO5->GDIR |=(1<<1);//设置为输出
    GPIO5->DR &=~(1<<1);  //默认关闭

}

//奉命其控制函数
void beep_switch(int status)
{
    if(status==ON)
    {
        GPIO5->DR |=(1<<1);
    }
    else if(status==OFF)
    {
        GPIO5->DR &=~(1<<1);
    }
    
}