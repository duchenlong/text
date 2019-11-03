#define _CRT_SECURE_NO_WARNINGS 1

#include "addressbook.h"

void menu()
{
	printf("******* 欢迎使用通讯录管理系统  **********\n");
	printf("******************************************\n");
	printf("************  1.添加联系人    ************\n");
	printf("************  2.查找联系人    ************\n");
	printf("************  3.删除联系人    ************\n");
	printf("************  4.显示联系人    ************\n");
	printf("************  5.更改联系人信息************\n");
	printf("************  6.读取文件通讯录信息********\n");
	printf("************  7.通讯录信息写入文件********\n");
	printf("************  8.按姓名排序        ********\n");
	printf("************  9.清空联系人        ********\n");
	printf("************  0.退出操作系统  ************\n");
	printf("******************************************\n");
}

void Text()
{
	int input = 1;
	char name[20];
	AddressBook addressbook;
	AddressBookInit(&addressbook);
	while (input)
	{
		AddressInfo* info;
		info = (AddressInfo*)malloc(sizeof(AddressInfo));
		system("color 09");//蓝色
		menu();
		printf("请输入选择的操作-->");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			system("color 0a");//淡绿色
			Input(info);
			AddressBookAdd(&addressbook, info);
			break;
		case 2:
			system("color 0b");//淡浅绿色
			printf("请输入查找的联系人的姓名-->");
			scanf("%s", name);
			info = AddressBookFind(&addressbook, name);
			if (info != NULL)
			{
				According(info);
			}
			break;
		case 3:
			system("color 0c");//淡红色
			printf("请输入删除的联系人的姓名-->");
			scanf("%s", name);
			info = AddressBookFind(&addressbook, name);
			if (info != NULL)
			{
				According(info);
				char i;
				printf("确认删除请输入Y/y：");
				scanf("%s", &i);
				if (i == 'Y' || i == 'y')
				{
					AddressBookDel(&addressbook, name);
					AddressBookSave(&addressbook, "text.txt");
					printf("删除成功\n");
				}
				else
				{
					printf("取消删除\n");
				}
			}
			break;
		case 4:
			AddressBookShow(&addressbook);
			break;
		case 5:
			printf("请输入需要更改的联系人姓名-->");
			scanf("%s", name);
			AddressBookChange(&addressbook, name);
			break;
		case 6:
			AddressBookLoad(&addressbook, "text.txt");
			printf("读取文件通讯录信息成功\n");
			break;
		case 7:
			AddressBookSave(&addressbook, "text.txt");
			printf("通讯录信息写入文件成功\n");
			break;
		case 8:
			AddressBookSort(&addressbook);
			AddressBookSave(&addressbook, "text.txt");
			printf("排序成功~\n");
			break;
		case 9:
			printf("确认清空所有联系人Y/y-->");
			char j;
			scanf("%s", &j);
			if (j == 'Y' || j == 'y')
			{
				addressbook._size = 0;
				printf("联系人已清空\n");
			}
			else
			{
				printf("退出清除操作\n");
			}
			break;
		case 0:
			printf("\n");
			printf("感谢使用~~~\n");
			break;
		default:
			printf("\n");
			printf("请输入正确的操作!!\n");
			break;
		}
		system("pause");
		system("cls");
	}
}

int main()
{

	Text();
	return 0;
}