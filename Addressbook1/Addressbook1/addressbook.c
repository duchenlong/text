#define _CRT_SECURE_NO_WARNINGS 1

#include"addressbook.h"

void AddressBookInit(AddressBook* pbook)
{
	assert(pbook);
	pbook->_size = 0;
	pbook->_capacity = 2;
	pbook->Information = (AddressInfo*)malloc(sizeof(AddressInfo)*(pbook->_capacity));
	assert(pbook->Information);
}

//������ϵ��
void Input(AddressInfo* pinfo)
{
	char name[20], phone[20];
	int i = 0;
	int age = 0;
	printf("��ϵ������-->\n");
	scanf("%s", name);
	strcpy(pinfo->_name, name);
	printf("��ϵ�˵绰����-->");
	scanf("%s", phone);
	strcpy(pinfo->_phone, phone);
	printf("��ϵ������-->");
	scanf("%d", &age);
	pinfo->_age = age;
	printf("��ϵ���Ա���-->man Ů-->woman��-->");
	while (1)
	{
		scanf("%d", &i);
		if (i == 0 || i == 1)
		{
			pinfo->_sex = i;
			break;
		}
		else
		{
			printf("��������ȷ����Ϣ��\n");
		}
	}
	printf("��������ϵ�˵�ַ-->\n");
	scanf("%s", pinfo->_address);
}

//�����ϵ��
void AddressBookAdd(AddressBook* pbook, AddressInfo* pinfo)
{
	assert(pbook&&pinfo);
	if (pbook->_size == pbook->_capacity)
	{
		pbook->Information = realloc(pbook->Information, sizeof(AddressInfo)*(pbook->_capacity) * 2);
		pbook->_capacity *= 2;
	}
	pbook->Information[pbook->_size]._age = pinfo->_age;
	pbook->Information[pbook->_size]._sex = pinfo->_sex;
	strcpy(pbook->Information[pbook->_size]._name, pinfo->_name);
	strcpy(pbook->Information[pbook->_size]._phone, pinfo->_phone);
	strcpy(pbook->Information[pbook->_size]._address, pinfo->_address);
	pbook->_size++;
}

//������ӡ��Ϣ
void According(AddressInfo* pinfo)
{
	printf("%s\t", pinfo->_name);
	printf("%s\t\t", pinfo->_phone);
	printf("%d\t", pinfo->_age);
	switch (pinfo->_sex)
	{
	case man:
		printf("man\t");
		break;
	case woman:
		printf("woman\t");
		break;
	default:
		printf("�޷�ʶ��\t");
		break;
	}
	printf("%s\n", pinfo->_address);
}

//չʾ������ϵ��
void AddressBookShow(AddressBook* pbook)
{
	size_t i = 0;
	printf("����\t�绰����\t����\t�Ա�\tסַ\n");
	for (i = 0; i < pbook->_size; i++)
	{
		According(&pbook->Information[i]);
	}
}

void AddressInfoCopy(AddressInfo* tar, AddressInfo* src)
{
	strcpy(tar->_name, src->_name);
	strcpy(tar->_phone, src->_phone);
	strcpy(tar->_address, src->_address);
	tar->_age = src->_age;
	tar->_sex = src->_sex;
}

//ɾ����ϵ��
void AddressBookDel(AddressBook* pbook, const char* name)
{
	size_t i = 0;
	for (i = 0; i < pbook->_size; i++)
	{
		if (strcmp(pbook->Information[i]._name, name) == 0)
		{
			break;
		}
	}
	if (i == pbook->_size)
	{
		printf("δ�ҵ���ϵ��%s\n\n", name);
		return;
	}
	for (i = i + 1; i < pbook->_size; i++)
	{
		AddressInfoCopy(&pbook->Information[i - 1], &pbook->Information[i]);
	}
	pbook->_size--;
}

//������ϵ��
AddressInfo* AddressBookFind(AddressBook* pbook, const char* name)
{
	AddressInfo* pinfo;
	pinfo = (AddressInfo*)malloc(sizeof(AddressInfo));
	size_t i = 0;
	for (i = 0; i < pbook->_size; i++)
	{
		if (strcmp(pbook->Information[i]._name, name) == 0)
		{
			return &pbook->Information[i];
		}
	}
	printf("û���ҵ���ϵ��%s\n\n", name);
	return NULL;
}

//������ϵ����Ϣ
void AddressBookChange(AddressBook* pbook, const char* name)
{
	AddressInfo* pinfo;
	pinfo = (AddressInfo*)malloc(sizeof(AddressInfo));
	pinfo = AddressBookFind(pbook, name);
	if (pinfo == NULL)
	{
		return;
	}
	printf("��������ϵ���µ���Ϣ\n");
	Input(&pinfo);
}

//���ļ���д����Ϣ
void AddressBookSave(AddressBook* pbook, const char* filename)
{
	assert(pbook&&filename);
	FILE* fp = fopen(filename, "w");
	for (size_t i = 0; i < pbook->_size; i++)
	{
		fwrite(&pbook->Information[i], sizeof(AddressInfo), 1, fp);
	}
	AddressInfo end;
	end._age = -1;
	fwrite(&end, sizeof(AddressInfo), 1, fp);
	fclose(fp);
}

//���ļ��ж�ȡ��Ϣ
void AddressBookLoad(AddressBook* pbook, const char* filename)
{
	assert(pbook&&filename);
	FILE* fp = fopen(filename, "r");
	AddressInfo info;
	while (1)
	{
		fread(&info, sizeof(AddressInfo), 1, fp);
		if (info._age == -1)
		{
			break;
		}
		AddressBookAdd(pbook, &info);
	}
	fclose(fp);
}

//����
void AddressBookSwap(AddressInfo* pInfo1, AddressInfo* pInfo2)
{
	AddressInfo* tmp;
	tmp = (AddressInfo*)malloc(sizeof(AddressInfo));
	AddressInfoCopy(tmp, pInfo1);
	AddressInfoCopy(pInfo1, pInfo2);
	AddressInfoCopy(pInfo2, tmp);
	free(tmp);
}

//ͨѶ¼����
void AddressBookSort(AddressBook* pbook)
{
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < pbook->_size; i++)
	{
		for (j = 0; j < pbook->_size-i - 1; j++)
		{
			if (strcmp(pbook->Information[j]._name, pbook->Information[j + 1]._name)>0)
			{
				AddressBookSwap(&pbook->Information[j], &pbook->Information[j + 1]);
			}
		}
	}
}
