#pragma once	//Ԥ��ͷ�ļ��ظ�����

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<assert.h>

#define MAX_N 30  //������󳤶�
#define MAX_T 15  //�绰������󳤶�
#define MAX_A 100 //��ַ��󳤶�

//�û���Ϣ�ṹ��
typedef struct InfoNode
{
	char _name[MAX_N];		//����
	char _telephone[MAX_T];	//�绰����
	char _address[MAX_A];	//��ַ
}InfoNode;

//����ʱ��ѭ��˫����洢
typedef struct InfoNode_List
{
	InfoNode* _ListInfo;			//�ṹ��ָ��������û���Ϣ
	struct InfoNode_List* _next;	//ָ����һ���ڵ�
	struct InfoNode_List* _pre;		//ָ����һ���ڵ�
}InfoNode_List;

//��ʼ������
void InitList(InfoNode_List* pl);

//�����û���Ϣ�ڵ�
void ScanfNode(InfoNode* pnode);

//��������ڵ�
void AddList(InfoNode_List* pl);

//�޸��û���Ϣ
void ChangeNode(InfoNode* pnode);

//ɾ���ڵ�
void DeleteListNode(InfoNode_List* pl);

//��������
InfoNode_List* FindName(InfoNode_List* phead, char* name);

//�绰�������
InfoNode_List* FindTelephone(InfoNode_List* phead, char* telephone);

//��ӡ��Ϣ
void ShowInfo(InfoNode_List* phead);

//��ӡһ���û�����Ϣ
void ShowOnce(InfoNode* pi);

//���ַ�ASCLL�Ƚ������û���Ϣ�Ĵ�С
int CompareInfo(InfoNode* pi1, InfoNode* pi2);

//����   --> ��������
void InsertSort(InfoNode_List* phead);

//��ǰ��Ϣд���ļ�
void WriteFileInfo(InfoNode_List* phead);

//��ȡ���ļ���Ϣ�������� (ͷ�巨)
void ReadFileInfo(InfoNode_List* phead);

//ģ�����ҳ��
void my_loading(const int time);

//0.5��˯�߼�����
void SleepCls();