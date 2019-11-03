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

//初始化通讯录
void AddressBookInit(AddressBook* pbook);
//添加联系人
void AddressBookAdd(AddressBook* pbook, AddressInfo* pinfo);
//删除联系人
void AddressBookDel(AddressBook* pbook, const char* name);
//查找联系人
AddressInfo* AddressBookFind(AddressBook* pbook, const char* name);
//打印通讯录
void AddressBookShow(AddressBook* pbook);
//更改联系人信息
void AddressBookChange(AddressBook* pbook, const char* name);
//输入联系人
void Input(AddressInfo* pinfo);
//单独打印信息
void According(AddressInfo* pinfo);
//在文件中写入信息
void AddressBookSave(AddressBook* pbook, const char* filename);
//从文件中读取信息
void AddressBookLoad(AddressBook* pbook, const char* filename);
//通讯录排序
void AddressBookSort(AddressBook* pbook);


