#define _CRT_SECURE_NO_WARNINGS 1

#include "hashname.h"

//��ʼ����ϣ��
void InitNameTableH(NameTableH* pn)
{
	assert(pn);

	pn->_psize = 0;			//������û�г�Ա
	pn->_capacity = DIV;	//���鵱ǰ������Ϊ�����������ĳ���
	pn->_NameArr = (HTName*)malloc(sizeof(HTName)*pn->_capacity);
	//Ϊ���鿪�ٵ�ǰ�����Ŀռ�

	int i = 0;
	for (i = 0; i < pn->_capacity; i++)
	{
		//������ÿ��λ�ó�ʼ��Ϊ0
		//0��ʾ��λ��û�д�ų�Ա��Ϣ
		pn->_NameArr[i]._ishave = 0;	
	}
}

//��ϣ������
void AddCapacity(NameTableH* pn, const int key)
{
	assert(pn && key < pn->_capacity);

	pn->_capacity *= 2;
	pn->_NameArr = realloc(pn->_NameArr, sizeof(HTName)*pn->_capacity);
	//realloc�����������ݣ�����ı�����ԭ���ռ����ݵ���Ϣ
	//ÿ�����ݵĴ�СΪ��ǰ������2��

	int i = 0;
	for (i = pn->_psize;i< pn->_capacity; i++)
	{
		pn->_NameArr[i]._ishave = 0;					//��ʼ�������ӵĿռ������û������
	}

	//Ϊ�˲��ı��ϣ�����ʱ���˳��
	//������Ϻ󣬽������е�ǰȨֵǰ�����Ϣ�������ƶ����¿��ٵĵط�����
	for (i = 0; i < key; i++)
	{
		pn->_NameArr[i + pn->_psize]._NameInfo = pn->_NameArr[i]._NameInfo;	//�û���Ϣ�ƶ�
		pn->_NameArr[i + pn->_psize]._key = pn->_NameArr[i]._key;			//Ȩֵ�ƶ�
		pn->_NameArr[i]._ishave = 0;					//��ǰλ����Ϊ��ֵ
		pn->_NameArr[i + pn->_psize]._ishave = 1;		//�ƶ����λ����Ϊ��ֵ
	}
}

//������ϣ��
void SetNameTableH(NameTableH* pn, InfoNode_List* phead)
{
	assert(pn && phead);

	if (phead==phead->_next)
	{
		printf("û���û�����Ϣ��\n");
		return;
	}
	InfoNode_List* node = phead->_next;
	char Fname, Lname;	//һ����ʾ���������ַ���һ����ʾβ�ַ�
	int len;			//��ʾ�����ĳ���
	int key;			//��ʾ������Ȩֵ
	while (node!=phead)
	{
		Fname = node->_ListInfo->_name[0];
		len = strlen(node->_ListInfo->_name);
		Lname = node->_ListInfo->_name[len-1];
		key = (int)(Fname + Lname) % DIV;	//����Ȩֵ

		if (pn->_psize == pn->_capacity)	//�ж��Ƿ���Ҫ����
		{
			AddCapacity(pn,key);
		}

		if (!pn->_NameArr[key]._ishave)//��λ��û�г��ֳ�ͻ
		{
			//���ýڵ����û���Ϣ�ڵ� ��ֵ�� ��ϣ���и�λ���û���Ϣ�ڵ�
			pn->_NameArr[key]._NameInfo = node->_ListInfo;
			//��¼��λ��Ȩֵ
			pn->_NameArr[key]._key = key;
			//�޸ĸ�λ��Ϊ��ֵ
			pn->_NameArr[key]._ishave = 1;
		}
		else //���ֳ�ͻ������ɢ�з������ͻ
		{
			int i = key+1;
			while (pn->_NameArr[i]._ishave)//�ҵ���һ������ͻ�Ľڵ�
			{
				i = (i + 1) % pn->_capacity;//�ø�λ�����߼��϶�̬��������
			}

			//���ýڵ����û���Ϣ�ڵ� ��ֵ�� ��ϣ���и�λ���û���Ϣ�ڵ�
			pn->_NameArr[i]._NameInfo = node->_ListInfo;
			//��¼��λ��Ȩֵ
			pn->_NameArr[i]._key = key;
			//�޸ĸ�λ��Ϊ��ֵ
			pn->_NameArr[i]._ishave = 1;
		}

		node = node->_next;
		pn->_psize++;
	}

	my_loading(3);	//ģ�����
	printf("\t������ϣ�������\n");
	system("pause"); 
	SleepCls();		//0.5��˯��+����
}

//�����û���Ϣ
int FindNameTableH(NameTableH* pn, const char* name)
{
	assert(pn && name);

	char Fname, Lname;
	Fname = name[0];
	int len = strlen(name);
	Lname = name[len - 1];  //ȡ���ַ���β�ַ�

	int key = (int)(Fname + Lname) % DIV;	//����Ȩֵ
	int i = key;
	int count = 0;
	//����ʱѭ������������
	//1.��ǰλ��û�д���û���Ϣ
	//2.���������Դ�ŵ��û��Ѿ����ˣ�����û����Ҫ���ҵ���
	//��ѭ�����˵�ǰ�����Ĳ���  ---> count==pn->_capacity
	//3.Ȩֵ��ͬ
	while (		pn->_NameArr[i]._ishave  \
			&& (count++)<pn->_capacity	 \
		   &&   pn->_NameArr[i]._key != key)
	{
		i++;
	}
	//�ж���������������ѭ��
	//�����1 2 �����ʾû���ҵ����˳�����
	if (pn->_capacity == count || !pn->_NameArr[i]._ishave)
	{
		printf("û���ҵ����û�\n");
		return -1;
	}
	//3 ��ʾ�ҵ������д�ӡ
	ShowOnce(pn->_NameArr[i]._NameInfo);
	return i;
}

//�޸��û���Ϣ
void ChangeNameTableH(NameTableH* pn)
{
	assert(pn);

	char name[MAX_N] = { '\0' };
	printf("��������Ҫ�޸ĵ��û�������-->");
	scanf("%s", name);
	int i = FindNameTableH(pn,name);	//���ú������������û�
	system("pause");					//������ͣ�������������
	if (i != -1)						//��ʾ�ҵ����û�
	{
		SleepCls();
		printf("������������û�����Ϣ��\n");
		ChangeNode(pn->_NameArr[i]._NameInfo);//����������û�����Ϣ,ѡ���������ַ
	}
}