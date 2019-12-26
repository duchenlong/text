#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"
#include "hashtele.h"

//��ʼ����ϣ��
void InitTeleListH(TeleListH* pt)
{
	assert(pt);

	pt->_TeleArr = (HTTele*)malloc(sizeof(HTTele)*MAX_TELEARR);	//���ٴ洢��Ϣ�Ŀռ�
	int i = 0;
	for (i = 0; i < MAX_TELEARR; i++)
	{
		pt->_TeleArr[i].next = NULL;	//ÿһ�����ͷ��nextָ���ʼ��ΪNULL
	}
}

//������ϣ��
void SetTeleListH(TeleListH* pt, InfoNode_List* phead)
{
	assert(pt && phead);

	if (phead==phead->_next)					//�ж���û���û���Ϣ���Բ���
	{
		printf("û���û�����Ϣ��\n");
		return;
	}
	InfoNode_List* node = phead->_next;
	int len = 0;
	while (node!=phead)
	{
		int key = 0;
		len = strlen(node->_ListInfo->_telephone);
		while (len)								//����Ȩֵ
		{
			key += (int)node->_ListInfo->_telephone[len - 1];
			key %=MAX_TELEARR;					//����������  ����Ϊ���ĸ߶�
			len--;
		}

		//����һ���µ����ڵ�
		HTTele* Newnode = (HTTele*)malloc(sizeof(HTTele));
		Newnode->_TeleInfo = node->_ListInfo;	 //�û���Ϣ�ĸ���
		Newnode->next = NULL;

		if (!pt->_TeleArr[key].next)			//�����λ�õ�ͷû�е�ַ
		{
			pt->_TeleArr[key].next = Newnode;
		}
		else
		{
			//�ڵ�ǰ����ͷ���в���
			Newnode->next=pt->_TeleArr[key].next;
			pt->_TeleArr[key].next = Newnode;
		}
		node = node->_next;
	}
	
	my_loading(3);	//ģ�����
	printf("�绰�����ϣ���������\n");
	system("pause");
	SleepCls();		//0.5��˯��+����
}

//�绰��������û�
InfoNode* FindTeleListH(TeleListH* pt, const char* telephone)
{
	assert(pt);

	int key = 0;
	int len = strlen(telephone);
	while (len)				//����Ȩֵ
	{
		key += (int)telephone[len - 1];
		key %= MAX_TELEARR; //����������  ����Ϊ���ĸ߶�
		len--;
	}

	if (!pt->_TeleArr[key].next)
	{
		printf("û���ҵ����û�\n");
		return NULL;
	}
	else
	{
		HTTele* Newnode = pt->_TeleArr[key].next;
		while (Newnode)
		{
			if (strcmp(Newnode->_TeleInfo->_telephone, telephone) == 0)
			{
				ShowOnce(Newnode->_TeleInfo);	//��ӡҪ���ҵĸ��û���Ϣ
				return Newnode->_TeleInfo;		//�������ظ��û�����Ϣ�ڵ�
			}
			Newnode = Newnode->next;
		}
	}
	return NULL;
}

//�޸��û���Ϣ
void ChangeTeleListH(TeleListH* pt)
{
	assert(pt);

	printf("������Ҫ�޸��û��ĵ绰����-->");
	char tele[MAX_T];
	scanf("%s", tele);
	InfoNode* Newnode=FindTeleListH(pt, tele);
	system("pause");					//������ͣ�������������
	if (!Newnode)			//������Һ�������ֵΪNULL,��ʾδ�ҵ���ֱ�ӷ���
	{
		return;
	}
	SleepCls();
	printf("������������û�����Ϣ��\n");
	ChangeNode(Newnode);	//����������û����µ�������Ϣ
}