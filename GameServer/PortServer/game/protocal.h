#ifndef _PROTOCAL_H
#define _PROTOCAL_H

#define  EGP_START__LOGIN 2000
#define  EGP_START__GAME  3000

enum ENUM_GAME_PROTOCAL
{
	//////////////////////////////////////////////////////////////////////////
	EGP_NONE = 1001,

	//////////////////////////////////////////////////////////////////////////
	EGP_C2S_HEART           = 1000,
	EGP_S2C_HEART           = 1001,


	//////////////////////////////////////////////////////////////////////////
	EGP_C2S_LOGIN           = EGP_START__LOGIN + 10,
	EGP_S2C_LOGIN           = EGP_START__LOGIN + 11,

	EGP_S2C_RECONNECT_HALL  = EGP_START__LOGIN + 12,
	EGP_S2C_RECONNECT_READY = EGP_START__LOGIN + 13,
	EGP_S2C_RECONNECT_ROOM  = EGP_START__LOGIN + 14,

	EGP_C2S_GETPLAYERDATA   = EGP_START__LOGIN + 15,
	EGP_S2C_GETPLAYERDATA   = EGP_START__LOGIN + 16,

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	//////////////////////////////////////////////////////////////////////////
	EGP_C2S_CREATE_ROOM    = EGP_START__LOGIN + 20,
	EGP_S2C_CREATE_ROOM    = EGP_START__LOGIN + 21,

	EGP_C2S_ENTER_ROOM     = EGP_START__LOGIN + 22,
	EGP_S2C_ALL_ENTER_ROOM = EGP_START__LOGIN + 23,

	EGP_C2S_LEAVE_ROOM     = EGP_START__LOGIN + 24,
	EGP_S2C_ALL_LEAVE_ROOM = EGP_START__LOGIN + 25,

	////
	EGP_C2S_DISBAND_ROOM           = EGP_START__LOGIN + 26,         //解散房间请求
	EPG_S2C_ALL_DISBAND_ROOM       = EGP_START__LOGIN + 27,         //

	EGP_C2S_DISBAND_RESPONSE       = EGP_START__LOGIN + 28,         //解散房间响应
	EGP_S2C_ALL_DISBAND_RESPONSE   = EGP_START__LOGIN + 29,

	////
	EGP_C2S_DISBAND_ROOM_BY_OWNER  = EGP_START__LOGIN + 30,
	EGP_S2C_DISBAND_ROOM_BY_OWNER  = EGP_START__LOGIN + 31,

	////
	EGP_C2S_REQUEST_ROOMLIST       = EGP_START__LOGIN + 40,         //房主获取所开房间信息
	EGP_S2C_REQUEST_ROOMLIST       = EGP_START__LOGIN + 41,

	////
	EGP_C2S_REQUEST_PLAYERSINROOM  = EGP_START__LOGIN + 50,         //获取房间内所有玩家信息
	EGP_S2C_REQUEST_PLAYERSINROOM  = EGP_START__LOGIN + 51,      

	////
	EGP_C2S_PAY_VIP                = EGP_START__LOGIN + 100,
	EGP_S2C_PAY_VIP                = EGP_START__LOGIN + 101,

	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	//////////////////////////////////////////////////////////////////////////
	EGP_C2S_APPLICATE_LEAVE        = EGP_START__GAME + 4,            //申请离开房间
	EGP_S2C_ALL_APPLICATE_LEAVE    = EGP_START__GAME + 5,            //

	//////////////////////////////////////////////////////////////////////////
	EGP_C2S_NEXT_AROUND            = EGP_START__GAME + 8,            //开始下一盘游戏
	EGP_S2C_NEXT_AROUND            = EGP_START__GAME + 9, 

	//////////////////////////////////////////////////////////////////////////
	EGP_C2S_READYGAME              = EGP_START__GAME + 10,           //准备好了游戏
	EGP_S2C_ALL_READYGAME          = EGP_START__GAME + 11,           //

	EGP_C2S_CANCELREADY            = EGP_START__GAME + 12,           //取消了准备
	EGP_S2C_ALL_CANCELREADY        = EGP_START__GAME + 13,           //

	EGP_C2S_FIGHT_ZHUANG           = EGP_START__GAME + 14,           //抢庄
	EGP_S2C_ALL_FIGHT_ZHUANG       = EGP_START__GAME + 15,

	EGP_C2S_ADD_DOUBLE             = EGP_START__GAME + 16,           //押分加倍
	EGP_S2C_ALL_ADD_DOUBLE         = EGP_START__GAME + 17,

	/*
	EGP_C2S_STARTGAME              = EGP_START__GAME + 10,           //开始游戏,则玩家加入当前房间的游戏列表中
	EGP_S2C_ALL_STARTGAME          = EGP_START__GAME + 11, 

	EGP_C2S_FIGHT_ZHUANG           = EGP_START__GAME + 20,           //抢庄协议，抢庄后不可再抢
	EGP_S2C_FIGHT_ZHUANG           = EGP_START__GAME + 21,

	EGP_C2S_ADD_DOUBLE_SCORE       = EGP_START__GAME + 22,           //加倍

	EGP_S2C_GAME_SEND_POKECARD_3   = EGP_START__GAME + 31,           //发牌
	EGP_S2C_GAME_SEND_POKECARD_4   = EGP_START__GAME + 32,
	EGP_S2C_GAME_SEND_POKECARD_5   = EGP_START__GAME + 32,

	EGP_S2C_GAME_RESULT            = EGP_START__GAME + 41,           //结果
	*/

};

#endif