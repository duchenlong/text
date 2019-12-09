#pragma once	//预防头文件重复引用

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<assert.h>

#define MAX_N 30  //姓名最大长度
#define MAX_T 15  //电话号码最大长度
#define MAX_A 100 //地址最大长度

//用户信息结构体
typedef struct InfoNode
{
	char _name[MAX_N];		//姓名
	char _telephone[MAX_T];	//电话号码
	char _address[MAX_A];	//地址
}InfoNode;

//输入时以循环双链表存储
typedef struct InfoNode_List
{
	InfoNode* _ListInfo;			//结构体指针来存放用户信息
	struct InfoNode_List* _next;	//指向下一个节点
	struct InfoNode_List* _pre;		//指向上一个节点
}InfoNode_List;

//初始化链表
void InitList(InfoNode_List* pl);

//输入用户信息节点
void ScanfNode(InfoNode* pnode);

//增加链表节点
void AddList(InfoNode_List* pl);

//修改用户信息
void ChangeNode(InfoNode* pnode);

//删除节点
void DeleteListNode(InfoNode_List* pl);

//姓名查找
InfoNode_List* FindName(InfoNode_List* phead, char* name);

//电话号码查找
InfoNode_List* FindTelephone(InfoNode_List* phead, char* telephone);

//打印信息
void ShowInfo(InfoNode_List* phead);

//打印一个用户的信息
void ShowOnce(InfoNode* pi);

//按字符ASCLL比较两个用户信息的大小
int CompareInfo(InfoNode* pi1, InfoNode* pi2);

//排序   --> 插入排序法
void InsertSort(InfoNode_List* phead);

//当前信息写入文件
void WriteFileInfo(InfoNode_List* phead);

//读取把文件信息插入链表 (头插法)
void ReadFileInfo(InfoNode_List* phead);

//模拟加载页面
void my_loading(const int time);

//0.5秒睡眠加清屏
void SleepCls();