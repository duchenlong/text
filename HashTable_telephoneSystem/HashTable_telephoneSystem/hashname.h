#pragma  once

#include"list.h"

//用姓名为关键字建立哈希表
//取权值的公式  姓名的首尾字符相加再对50取余
//处理冲突的方法 再散列法

#define DIV (1)	//除留余数法的除数

typedef struct HTName	
{
	InfoNode* _NameInfo;	//用户信息
	int _key;	//建表后的权值
	int _ishave;	//判断该位置有没有填入用户
}HTName;

typedef struct NameTableH
{
	HTName* _NameArr;	//动态开辟数组来存放用户信息
	int _psize;		//当前存放信息的用户数量
	int _capacity;	//数组当前的容量
}NameTableH;


//初始化哈希表
void InitNameTableH(NameTableH* pn);

//哈希表扩容
void AddCapacity(NameTableH* pn,const int key);

//建立哈希表
void SetNameTableH(NameTableH* pn, InfoNode_List* phead);

//查找用户信息
void FindNameTableH(NameTableH* pn, const char* name);

//修改用户信息
void ChangeNameTableH(NameTableH* pn);

