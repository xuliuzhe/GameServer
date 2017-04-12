#ifndef _MESSAGE_DOUNIU_H
#define _MESSAGE_DOUNIU_H

#include "message.h"

struct MSG_C2S_NEXT_AROUND:
	public BASE_PROTOCAL_MSG
{
	 MSG_C2S_NEXT_AROUND():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_C2S_NEXT_AROUND)
	 {

	 }
};

struct MSG_S2C_NEXT_AROUND:
	public BASE_PROTOCAL_MSG
{
	MSG_S2C_NEXT_AROUND():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_S2C_NEXT_AROUND)
	{
		initializeParam(6, JSON_PLAYER_UID, JSON_PLAYER_KEY, 
			JSON_PLAYER_GAMESTATUS, JSON_ROOM_GAMESTATUS,
			JSON_FLAG,
			JSON_ROOM_PLAYERSINFO_DATA
			);
	}
};

//////////////////////////////////////////////////////////////////////////
struct MSG_C2S_APPLICATE_LEAVE:
	public BASE_PROTOCAL_MSG
{
	MSG_C2S_APPLICATE_LEAVE():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_C2S_APPLICATE_LEAVE)
	{

	}
};

struct MSG_S2C_ALL_APPLICATE_LEAVE:
	public BASE_PROTOCAL_MSG
{
	MSG_S2C_ALL_APPLICATE_LEAVE():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_S2C_ALL_APPLICATE_LEAVE)
	{
		initializeParam(1, JSON_EX_DATA);
	}
};

struct MSG_C2S_AGREE_APPLICATE_LEAVE:
	public BASE_PROTOCAL_MSG
{
	MSG_C2S_AGREE_APPLICATE_LEAVE():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_C2S_AGREE_APPLICATE_LEAVE)
	{
		initializeParam(1, JSON_FLAG);
	}
};

struct MSG_S2C_ALL_AGREE_RESULT:
	public BASE_PROTOCAL_MSG
{
	MSG_S2C_ALL_AGREE_RESULT():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_S2C_ALL_AGREE_RESULT)
	{
		initializeParam(1, JSON_EX_DATA);
	}
};

//////////////////////////////////////////////////////////////////////////
struct  MSG_C2S_READYGAME:
	public BASE_PROTOCAL_MSG
{
	MSG_C2S_READYGAME():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_C2S_READYGAME)
	{

	}
};

struct  MSG_S2C_ALL_READYGAME:
	public BASE_PROTOCAL_MSG
{
	MSG_S2C_ALL_READYGAME():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_S2C_ALL_READYGAME)
	{
		initializeParam(7, JSON_PLAYER_UID, JSON_PLAYER_KEY, JSON_PLAYER_INDEXINROOM, 
			JSON_PLAYER_GAMESTATUS, JSON_ROOM_GAMESTATUS,
			JSON_ROOM_CURRENT_AROUND, JSON_ROOM_MAX_AROUND
			);
	}
};

//////////////////////////////////////////////////////////////////////////
struct MSG_C2S_CANCELREADY:
	public BASE_PROTOCAL_MSG
{
	MSG_C2S_CANCELREADY():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_C2S_CANCELREADY)
	{

	}
};

struct MSG_S2C_ALL_CANCELREADY:
	public BASE_PROTOCAL_MSG
{
	MSG_S2C_ALL_CANCELREADY():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_S2C_ALL_CANCELREADY)
	{
		initializeParam(5, JSON_PLAYER_UID, JSON_PLAYER_KEY, JSON_PLAYER_INDEXINROOM, 
			JSON_PLAYER_GAMESTATUS, JSON_ROOM_GAMESTATUS);
	}
};

//////////////////////////////////////////////////////////////////////////
struct MSG_C2S_FIGHT_ZHUANG:
	public BASE_PROTOCAL_MSG
{
	MSG_C2S_FIGHT_ZHUANG():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_C2S_FIGHT_ZHUANG)
	{
		initializeParam(1, JSON_ZHUANG_VALUE);
	}
};

struct MSG_S2C_ALL_FIGHT_ZHUANG:
	public BASE_PROTOCAL_MSG
{
	MSG_S2C_ALL_FIGHT_ZHUANG():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_S2C_ALL_FIGHT_ZHUANG)
	{
		initializeParam(7, JSON_PLAYER_UID, JSON_PLAYER_KEY, 
			JSON_PLAYER_GAMESTATUS, JSON_ROOM_GAMESTATUS,
			JSON_ZHUANG_VALUE,
			JSON_EX_DATA,
			JSON_POKECARD
			);
	}
};

//////////////////////////////////////////////////////////////////////////
struct MSG_C2S_ADD_DOUBLE:
	public BASE_PROTOCAL_MSG
{
	MSG_C2S_ADD_DOUBLE():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_C2S_ADD_DOUBLE)
	{
		initializeParam(1, JSON_DOUBLE);
	}
};

struct MSG_S2C_ALL_ADD_DOUBLE:
	public BASE_PROTOCAL_MSG
{
	MSG_S2C_ALL_ADD_DOUBLE():BASE_PROTOCAL_MSG(ENUM_GAME_PROTOCAL::EGP_S2C_ALL_ADD_DOUBLE)
	{
		initializeParam(7, JSON_PLAYER_UID, JSON_PLAYER_KEY, 
			JSON_PLAYER_GAMESTATUS, JSON_ROOM_GAMESTATUS,
			JSON_DOUBLE, 
			JSON_EX_DATA,
			JSON_FLAG //标识是否为最后一局，若是最后一局则退出
			);
	}
};


#endif