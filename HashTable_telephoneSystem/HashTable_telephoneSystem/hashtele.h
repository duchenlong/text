#pragma  once

#include "list.h"

//以用户的电话号码为关键字建立散列表
//取权值的公式  电话号码每个数字字符相加 对50取余
//处理冲突的方法 链地址法

#define MAX_TELEARR 50	 //链的最大高度

typedef struct HTTele	 //链地址法每个节点
{
	InfoNode* _TeleInfo; //用户信息
	struct HTTele* next; //逻辑上连接下一个同权值的节点
}HTTele;

typedef struct TeleListH
{
	HTTele* _TeleArr;	 //链的头
}TeleListH;

//初始化哈希链
void InitTeleListH(TeleListH* pt);

//建立哈希链
void SetTeleListH(TeleListH* pt, InfoNode_List* phead);

//电话号码查找用户
InfoNode* FindTeleListH(TeleListH* pt, const char* telephone);

//修改用户信息
void ChangeTeleListH(TeleListH* pt);