#define _CRT_SECURE_NO_WARNINGS 1

#include "addressbook.h"

void menu()
{
	printf("******* ��ӭʹ��ͨѶ¼����ϵͳ  **********\n");
	printf("******************************************\n");
	printf("************  1.�����ϵ��    ************\n");
	printf("************  2.������ϵ��    ************\n");
	printf("************  3.ɾ����ϵ��    ************\n");
	printf("************  4.��ʾ��ϵ��    ************\n");
	printf("************  5.������ϵ����Ϣ************\n");
	printf("************  6.��ȡ�ļ�ͨѶ¼��Ϣ********\n");
	printf("************  7.ͨѶ¼��Ϣд���ļ�********\n");
	printf("************  8.����������        ********\n");
	printf("************  9.�����ϵ��        ********\n");
	printf("************  0.�˳�����ϵͳ  ************\n");
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
		system("color 09");//��ɫ
		menu();
		printf("������ѡ��Ĳ���-->");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			system("color 0a");//����ɫ
			Input(info);
			AddressBookAdd(&addressbook, info);
			break;
		case 2:
			system("color 0b");//��ǳ��ɫ
			printf("��������ҵ���ϵ�˵�����-->");
			scanf("%s", name);
			info = AddressBookFind(&addressbook, name);
			if (info != NULL)
			{
				According(info);
			}
			break;
		case 3:
			system("color 0c");//����ɫ
			printf("������ɾ������ϵ�˵�����-->");
			scanf("%s", name);
			info = AddressBookFind(&addressbook, name);
			if (info != NULL)
			{
				According(info);
				char i;
				printf("ȷ��ɾ��������Y/y��");
				scanf("%s", &i);
				if (i == 'Y' || i == 'y')
				{
					AddressBookDel(&addressbook, name);
					AddressBookSave(&addressbook, "text.txt");
					printf("ɾ���ɹ�\n");
				}
				else
				{
					printf("ȡ��ɾ��\n");
				}
			}
			break;
		case 4:
			AddressBookShow(&addressbook);
			break;
		case 5:
			printf("��������Ҫ���ĵ���ϵ������-->");
			scanf("%s", name);
			AddressBookChange(&addressbook, name);
			break;
		case 6:
			AddressBookLoad(&addressbook, "text.txt");
			printf("��ȡ�ļ�ͨѶ¼��Ϣ�ɹ�\n");
			break;
		case 7:
			AddressBookSave(&addressbook, "text.txt");
			printf("ͨѶ¼��Ϣд���ļ��ɹ�\n");
			break;
		case 8:
			AddressBookSort(&addressbook);
			AddressBookSave(&addressbook, "text.txt");
			printf("����ɹ�~\n");
			break;
		case 9:
			printf("ȷ�����������ϵ��Y/y-->");
			char j;
			scanf("%s", &j);
			if (j == 'Y' || j == 'y')
			{
				addressbook._size = 0;
				printf("��ϵ�������\n");
			}
			else
			{
				printf("�˳��������\n");
			}
			break;
		case 0:
			printf("\n");
			printf("��лʹ��~~~\n");
			break;
		default:
			printf("\n");
			printf("��������ȷ�Ĳ���!!\n");
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