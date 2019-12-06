#pragma  once

#include"list.h"

//������Ϊ�ؼ��ֽ�����ϣ��
//ȡȨֵ�Ĺ�ʽ  ��������β�ַ�����ٶ�50ȡ��
//�����ͻ�ķ��� ��ɢ�з�

#define DIV (1)	//�����������ĳ���

typedef struct HTName	
{
	InfoNode* _NameInfo;	//�û���Ϣ
	int _key;	//������Ȩֵ
	int _ishave;	//�жϸ�λ����û�������û�
}HTName;

typedef struct NameTableH
{
	HTName* _NameArr;	//��̬��������������û���Ϣ
	int _psize;		//��ǰ�����Ϣ���û�����
	int _capacity;	//���鵱ǰ������
}NameTableH;


//��ʼ����ϣ��
void InitNameTableH(NameTableH* pn);

//��ϣ������
void AddCapacity(NameTableH* pn,const int key);

//������ϣ��
void SetNameTableH(NameTableH* pn, InfoNode_List* phead);

//�����û���Ϣ
void FindNameTableH(NameTableH* pn, const char* name);

//�޸��û���Ϣ
void ChangeNameTableH(NameTableH* pn);

