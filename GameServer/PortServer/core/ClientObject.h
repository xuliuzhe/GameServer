#ifndef _CLIENTOBJECT_H
#define _CLIENTOBJECT_H
#include "WebSocketCommon.h"
#include "JackBase64.h"

#include <map>
#include "MemAllocPool.h"
#include "./../network/NetworkSystem.h"

//////////////////////////////////////////////////////////////////////////
#define MAX_OBJ_LOAD_DATA 1024 * 2
#define MAX_BIG_BUFF      1024

//Websocket数据包数据头信息  
struct WebSocketStreamHeader {  
	unsigned char  fin;                                 //帧标记  
	unsigned char  res[3];                     
	unsigned char  opcode;                              //操作码  
	unsigned char  masked;                              //掩码  
	unsigned char  payload_size;                        //数据大小  
	unsigned char  header_size;                         //数据包头大小  
	unsigned char  mask_offset;                         //掩码偏移  
	unsigned short extended_size;                       //扩充数据大小
};  

//
enum WS_FrameType  
{  
	WS_CONTINUATION_FRAME = 0x00,
	WS_EMPTY_FRAME        = 0xF0,  
	WS_ERROR_FRAME        = 0xF1,  
	WS_TEXT_FRAME         = 0x01,  
	WS_BINARY_FRAME       = 0x02,  
	WS_PING_FRAME         = 0x09,  
	WS_PONG_FRAME         = 0x0A,  
	WS_OPENING_FRAME      = 0xF3,  
	WS_CLOSING_FRAME      = 0x08  
}; 

//////////////////////////////////////////////////////////////////////////
struct BIG_BUFF
{
	char _buff[BUFFER_BIG_SIZE];

	inline void reset()
	{
		memset(_buff, 0, sizeof(_buff));
	}
};

typedef MemAllocPool<BIG_BUFF> ALLOC_BIG_BUFF;
//extern ALLOC_BIG_BUFF _ALLOC_BIG_BUFF;

typedef std::list<std::string> STRING_LIST;

struct PER_HANDLE_DATA;
struct PER_IO_DATA;

struct BASE_OBJECT
{
	/************************************************************************/
	/* DATA                                                                 */
	/************************************************************************/
	unsigned short         _UID;

	/************************************************************************/
	/* Network                                                              */
	/************************************************************************/
	//////////////////////////////////////////////////////////////////////////
	char                   _BUFF1[BUFFER_SIZE];
	char                   _BUFF2[BUFFER_SIZE];

	//////////////////////////////////////////////////////////////////////////
	__BRIDGE               _bridge_client;   //connnect to client
	__BRIDGE               _bridge_server;   //connect to gameserver

	PER_HANDLE_DATA*       _pPerHandle;
	PER_IO_DATA*           _pPerIo;

	//////////////////////////////////////////////////////////////////////////
	WebSocketStreamHeader  _WebSocketheader;
	STRING_LIST            _MSG_LIST;
	Locker                 _MSG_LIST_Lock;

	bool                   _bHandshake;      //握手成功

	/************************************************************************/
	/* Method                                                               */
	/************************************************************************/
	//////////////////////////////////////////////////////////////////////////
	BASE_OBJECT();
	~BASE_OBJECT();
	void reset();
	void release();

	//////////////////////////////////////////////////////////////////////////
	int  parse_buff(char* _buff_from, size_t _len);
	int  packet_buff(std::string inMessage, char* _OUT_BUFF);

	//////////////////////////////////////////////////////////////////////////
	int  ReadHeader(const unsigned char* cData);
	bool ReadHeaderEx(const unsigned char* cData);

	bool DecodeRawData(BYTE cbSrcData[], WORD wSrcLen, BYTE cbTagData[]);
	bool sendMSG(std::string _msg, ENUM_OP_TYPE _sendtype);

	//////////////////////////////////////////////////////////////////////////
	void lockMSGList();
	void unlockMSGList();
	bool popMessage();
};

typedef MemAllocPool<BASE_OBJECT> BASE_OBJECT_ALLOC;
typedef std::map<__BRIDGE, BASE_OBJECT*> ACCOUNT_MAP;

template<class Message>
bool SEND_MSG(Message msg, BASE_OBJECT* client, ENUM_OP_TYPE _sendtype = OP_WRITE)
{
	//////////////////////////////////////////////////////////////////////////
	Message& _Msg = msg;
	std::string _output;
	_Msg.package(_output);

	//////////////////////////////////////////////////////////////////////////
	std::string _OUT = _output;//JackBase64::base64_encode((const unsigned char*)_output.c_str(), _output.size());

	//////////////////////////////////////////////////////////////////////////
	return client->sendMSG(_OUT, _sendtype);
}

template<class Message>
void PUSH_MSG(Message msg, BASE_OBJECT* client)
{
	//////////////////////////////////////////////////////////////////////////
	Message& _Msg = msg;
	std::string _output;
	_Msg.package(_output);

	//////////////////////////////////////////////////////////////////////////
	std::string _OUT = _output;

	//////////////////////////////////////////////////////////////////////////
	client->lockMSGList();
	client->_MSG_LIST.push_back(_OUT);
	client->unlockMSGList();
}

#endif // !_CLIENTOBJECT_H



