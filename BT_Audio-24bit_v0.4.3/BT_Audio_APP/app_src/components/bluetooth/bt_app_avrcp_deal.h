/**
 **************************************************************************************
 * @file    bluetooth_avrcp_deal.h
 * @brief   
 *
 * @author  KK
 * @version V1.0.0
 *
 * $Created: 2021-4-18 18:00:00$
 *
 * @Copyright (C) Shanghai Mountain View Silicon Co.,Ltd. All rights reserved.
 **************************************************************************************
 */
	
#ifndef _BLUETOOTH_AVRCP_DEAL_H_
#define _BLUETOOTH_AVRCP_DEAL_H_

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include "bt_avrcp_api.h"


/*****************************************************************************************
* AVRCP连接成功
****************************************************************************************/
void BtAvrcpConnectedDev(BT_AVRCP_CALLBACK_PARAMS * param);

/*****************************************************************************************
* AVRCP断开连接
****************************************************************************************/
void BtAvrcpDisconnectedDev(BT_AVRCP_CALLBACK_PARAMS * param);

/*****************************************************************************************
* AVRCP 播放状态改变处理流程
****************************************************************************************/
void BtAvrcpPlayStatusChanged(BT_AVRCP_CALLBACK_PARAMS * param);

/*****************************************************************************************
* AVRCP 播放状态反馈
****************************************************************************************/
void BtAvrcpPlayStatus(BT_AVRCP_CALLBACK_PARAMS * param);

/*****************************************************************************************
* AVRCP断开连接
****************************************************************************************/
void TimerStart_BtPlayStatus(void);
void TimerStop_BtPlayStatus(void);
uint8_t CheckTimerStart_BtPlayStatus(void);

/*****************************************************************************************
* AVRCP 同步音量改变
****************************************************************************************/
void BtAvrcpVolumeChanged(BT_AVRCP_CALLBACK_PARAMS * param);

/*****************************************************************************************
* 设置/获取 音量同步值
****************************************************************************************/
void SetBtSyncVolume(uint8_t volume);
uint8_t GetBtSyncVolume(void);

/***********************************************************************************
 * 获取歌曲信息函数
 **********************************************************************************/
void GetBtMediaInfo(void *params);

#ifdef __cplusplus
}
#endif//__cplusplus

#endif //_BLUETOOTH_AVRCP_DEAL_H_



