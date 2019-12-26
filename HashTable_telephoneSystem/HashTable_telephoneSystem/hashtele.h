#pragma  once

#include "list.h"

//���û��ĵ绰����Ϊ�ؼ��ֽ���ɢ�б�
//ȡȨֵ�Ĺ�ʽ  �绰����ÿ�������ַ���� ��50ȡ��
//�����ͻ�ķ��� ����ַ��

#define MAX_TELEARR 50	 //�������߶�

typedef struct HTTele	 //����ַ��ÿ���ڵ�
{
	InfoNode* _TeleInfo; //�û���Ϣ
	struct HTTele* next; //�߼���������һ��ͬȨֵ�Ľڵ�
}HTTele;

typedef struct TeleListH
{
	HTTele* _TeleArr;	 //����ͷ
}TeleListH;

//��ʼ����ϣ��
void InitTeleListH(TeleListH* pt);

//������ϣ��
void SetTeleListH(TeleListH* pt, InfoNode_List* phead);

//�绰��������û�
InfoNode* FindTeleListH(TeleListH* pt, const char* telephone);

//�޸��û���Ϣ
void ChangeTeleListH(TeleListH* pt);