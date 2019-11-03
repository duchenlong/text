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

//输入联系人
void Input(AddressInfo* pinfo)
{
	char name[20], phone[20];
	int i = 0;
	int age = 0;
	printf("联系人姓名-->\n");
	scanf("%s", name);
	strcpy(pinfo->_name, name);
	printf("联系人电话号码-->");
	scanf("%s", phone);
	strcpy(pinfo->_phone, phone);
	printf("联系人年龄-->");
	scanf("%d", &age);
	pinfo->_age = age;
	printf("联系人性别（男-->man 女-->woman）-->");
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
			printf("请输入正确的信息！\n");
		}
	}
	printf("请输入联系人地址-->\n");
	scanf("%s", pinfo->_address);
}

//添加联系人
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

//单独打印信息
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
		printf("无法识别\t");
		break;
	}
	printf("%s\n", pinfo->_address);
}

//展示所有联系人
void AddressBookShow(AddressBook* pbook)
{
	size_t i = 0;
	printf("姓名\t电话号码\t年龄\t性别\t住址\n");
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

//删除联系人
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
		printf("未找到联系人%s\n\n", name);
		return;
	}
	for (i = i + 1; i < pbook->_size; i++)
	{
		AddressInfoCopy(&pbook->Information[i - 1], &pbook->Information[i]);
	}
	pbook->_size--;
}

//查找联系人
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
	printf("没有找到联系人%s\n\n", name);
	return NULL;
}

//更改联系人信息
void AddressBookChange(AddressBook* pbook, const char* name)
{
	AddressInfo* pinfo;
	pinfo = (AddressInfo*)malloc(sizeof(AddressInfo));
	pinfo = AddressBookFind(pbook, name);
	if (pinfo == NULL)
	{
		return;
	}
	printf("请输入联系人新的信息\n");
	Input(&pinfo);
}

//在文件中写入信息
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

//从文件中读取信息
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

//交换
void AddressBookSwap(AddressInfo* pInfo1, AddressInfo* pInfo2)
{
	AddressInfo* tmp;
	tmp = (AddressInfo*)malloc(sizeof(AddressInfo));
	AddressInfoCopy(tmp, pInfo1);
	AddressInfoCopy(pInfo1, pInfo2);
	AddressInfoCopy(pInfo2, tmp);
	free(tmp);
}

//通讯录排序
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
