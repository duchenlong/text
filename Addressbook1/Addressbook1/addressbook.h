#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

typedef enum SEX
{
	man,
	woman,
}SEX;

typedef struct AddressInfo
{
	char _name[20];
	char _phone[20];
	char _address[50];
	int _age;
	SEX _sex;
}AddressInfo;

typedef struct AddressBook
{
	AddressInfo* Information;
	size_t _size;
	size_t _capacity;
}AddressBook;

//��ʼ��ͨѶ¼
void AddressBookInit(AddressBook* pbook);
//�����ϵ��
void AddressBookAdd(AddressBook* pbook, AddressInfo* pinfo);
//ɾ����ϵ��
void AddressBookDel(AddressBook* pbook, const char* name);
//������ϵ��
AddressInfo* AddressBookFind(AddressBook* pbook, const char* name);
//��ӡͨѶ¼
void AddressBookShow(AddressBook* pbook);
//������ϵ����Ϣ
void AddressBookChange(AddressBook* pbook, const char* name);
//������ϵ��
void Input(AddressInfo* pinfo);
//������ӡ��Ϣ
void According(AddressInfo* pinfo);
//���ļ���д����Ϣ
void AddressBookSave(AddressBook* pbook, const char* filename);
//���ļ��ж�ȡ��Ϣ
void AddressBookLoad(AddressBook* pbook, const char* filename);
//ͨѶ¼����
void AddressBookSort(AddressBook* pbook);


