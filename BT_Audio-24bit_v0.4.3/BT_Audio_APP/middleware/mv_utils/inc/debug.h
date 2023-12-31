////////////////////////////////////////////////////////////////////////////////
//                   Mountain View Silicon Tech. Inc.
//		Copyright 2011, Mountain View Silicon Tech. Inc., ShangHai, China
//                   All rights reserved.
//
//		Filename	:debug.h
//
//		Description	:
//					Define debug ordinary print & debug routine
//
//		Changelog	:
///////////////////////////////////////////////////////////////////////////////

#ifndef __DEBUG_H__
#define __DEBUG_H__

/**
 * @addtogroup mv_utils
 * @{
 * @defgroup debug debug.h
 * @{
 */
 
#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include <stdio.h>
#include "type.h"
#include "gpio.h"


/************************** DEBUG**********************************
*下面为打印调试信息的接口,共有两个:
*1.打印前缀接口 : 
*  1)如果需要在打印时输出模块前缀 ,请调用 APP_DBG(),
*  2)需要关闭某模块的调试信息,可以用注释屏蔽 XXX_MODULE_DEBUG的宏
*	此模块宏,是根据如下规则 来划分的 : 
*	共划分为如下9个模块,
*	其中7个模块在Apps目录:分为media play,bt,hdmi_in,Main_task,usb_audio_mode,waiting_mode模块
*	另外两个模块是:Device模块、Services模块
*	剩下统一放在：DEB模块
*
*2.不打印前缀接口 : 调用 DBG()
*************************************************************/
#define	APP_DBG(format, ...)	printf(format, ##__VA_ARGS__)
#define	DBG(format, ...)		printf(format, ##__VA_ARGS__)
#define	OTG_DBG(format, ...)		//printf(format, ##__VA_ARGS__)
#define	BT_DBG(format, ...)		printf(format, ##__VA_ARGS__)
	
int DbgUartInit(int Which, unsigned int BaudRate, unsigned char DatumBits, unsigned char Parity, unsigned char StopBits);



/************************** TOGGLE DEBUG**********************************
 *
 * 为了方便调试时序，debug文件提供IO toggle功能
 * 1. LED_IO_TOGGLE 端口和序号配置列表是IO，实际api按0~n 需要使用，
 * 2、OS_INT_TOGGLE Os任务和中断时间片 观测，以task名字表为序号，led0~x，中断排在之后，需要先开启LED_IO_TOGGLE
 *
 *************************************************************/

/**OS任务切换和中断 时IO toggle，高电平表征执行时间片**/
//#define OS_INT_TOGGLE

/**需要toggle的task Name,可用部分,建议优先级高的在前；顺序 对应LED 0、LED 1....**/
#define DBG_TASK_LIST	{{"AudioCore"}, {"SysMode"}, {"MainApp"}, {"BtStack"}, {"IDLE"}}
//uint8_t dbgtasklist[][configMAX_TASK_NAME_LEN];
void DbgTaskTGL_set();
void DbgTaskTGL_clr();


/*********************************************
 * 中断toggle入口，需要修缮crt0.S的OS_Trap_Int_Comm 代码如下文

 	 原先语句代码:
 	jral $r1

 	修改为:
 	pushm $r0,$r1
 	jal   OS_dbg_int_in
 	popm $r0,$r1
 	push $r0
	jral $r1
 	pop  $r0
 	jal   OS_dbg_int_out
 ********************************************/
/**中断toggle的IO(LED_PORT_LIST) 排在 OS 序号后面,单列DBG_INT_ID, 其他非OS中断用一个IO**/
#define DBG_INT_ID				18 //Int18为BT INT0为OS 其他参见crt0.S

void OS_dbg_int_in(uint32_t int_num);
void OS_dbg_int_out(uint32_t int_num);



//#define LED_IO_TOGGLE //使用IO toggle调试  led或逻分观测 配合 LedPortInit()


/**测试IO,常用于程序执行时序可视化，标准SDK不使用**/
/**输出高低电平，上升沿，下降沿，翻转等，需配置LedOn有效电平。**/
/**调用LedPortInit初始化端口配置。**/
#define LED_ON_LEVEL	1//灯亮电平 设定。
/**根据需要启动对应端口和序号,led 0~n-1，注意端口复用规避**/
#define LED_PORT_LIST	{{'A', 0}, {'A', 1}, {'A', 2}, {'A', 3}, {'A', 4}, {'A', 5}, {'A', 6}, {'A', 7}, {'A', 8}, {'A', 9}, {'A', 10}, {'A', 11}, {'A', 12}, {'A', 13}, {'A', 14}, {'A', 15}}



#define PORT_IN_REG(X)			(X=='A'? GPIO_A_IN : GPIO_B_IN)
#define PORT_OUT_REG(X)			(X=='A'? GPIO_A_OUT : GPIO_B_OUT)
#define PORT_SET_REG(X)			(X=='A'? GPIO_A_SET : GPIO_B_SET)
#define PORT_CLR_REG(X)			(X=='A'? GPIO_A_CLR : GPIO_B_CLR)
#define PORT_TGL_REG(X)			(X=='A'? GPIO_A_TGL : GPIO_B_TGL)
#define PORT_IE_REG(X)			(X=='A'? GPIO_A_IE : GPIO_B_IE)
#define PORT_OE_REG(X)			(X=='A'? GPIO_A_OE : GPIO_B_OE)
#define PORT_DS_REG(X)			(X=='A'? GPIO_A_DS : GPIO_B_DS)
#define PORT_PU_REG(X)			(X=='A'? GPIO_A_PU : GPIO_B_PU)
#define PORT_PD_REG(X)			(X=='A'? GPIO_A_PD : GPIO_B_PD)
#define PORT_ANA_REG(X)			(X=='A'? GPIO_A_ANA_EN : GPIO_B_ANA_EN)
#define PORT_PULLDOWN_REG(X)	(X=='A'? GPIO_A_PULLDOWN : GPIO_B_PULLDOWN)
#define PORT_CORE_REG(X)		(X=='A'? GPIO_A_CORE_OUT_MASK : GPIO_B_CORE_OUT_MASK)
#define PORT_DMA_REG(X)			(X=='A'? GPIO_A_DMA_OUT_MASK : GPIO_B_DMA_OUT_MASK)
#define SET_MOD_REG(X, I, Mode)			((X)=='A'? (GPIO_PortAModeSet((I), (Mode))) : GPIO_PortBModeSet((I), (Mode)))

void LedPortInit(void);
void LedOn(uint8_t Index);//1~4 是否生效取决于LEDx_PORT是否定义
void LedOff(uint8_t Index);
void LedToggle(uint8_t Index);
void LedPortRise(uint8_t Index);
void LedPortDown(uint8_t Index);
bool LedPortGet(uint8_t Index);//TRUE:高电平，FALSE:低电平，index无效时 默认FALSE

#ifdef __cplusplus
}
#endif//__cplusplus

/**
 * @}
 * @}
 */
 
#endif //__DBG_H__ 

