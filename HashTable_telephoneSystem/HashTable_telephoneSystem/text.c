#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"
#include"hashname.h"
#include "hashtele.h"

void menuFind()
{
	printf("-----------------------------------------\n");
	printf("|\t�����û���Ϣ-->1\t\t|\n");
	printf("-----------------------------------------\n");
	printf("|\t�޸��û���Ϣ-->2\t\t|\n");
	printf("-----------------------------------------\n");
	printf("����ѡ��-->");
}

void menu()
{
	printf("\t _______________________________________\n");
	printf("\t|\tɢ�б�绰�����ѯϵͳ\t\t|\n");
	printf("\t|\t  1.�����û���Ϣ\t\t|\n");
	printf("\t|\t  2.ɾ���û���Ϣ\t\t|\n");
	printf("\t|\t  3.�û������Һ��޸��û���Ϣ    |\n");
	printf("\t|\t  4.�绰������Һ��޸��û���Ϣ\t|\n");
	printf("\t|\t  5.�û���Ϣ�����ļ�\t\t|\n");
	printf("\t|\t  6.���ļ��ж�ȡ�û���Ϣ\t|\n");
	printf("\t|\t  7.���û���Ϣ��������\t\t|\n");
	printf("\t|\t  8.��ӡ�����û���Ϣ\t\t|\n");
	printf("\t|\t  0.�˳�\t\t\t|\n");
	printf("\t|_______________________________________|\n\n");
}

int main()
{
	int input=1;
	int choose;
	InfoNode_List* head;		 //����˫��ѭ�������ͷ���
	head = (InfoNode_List*)malloc(sizeof(InfoNode_List));
	InitList(head);				//��ʼ������
	ReadFileInfo(head);			//��ȡ�ļ���Ϣ  ϵͳ��ʼʱ�Զ���ȡ�ļ��е���Ϣ
	SleepCls();					//0.5��˯�߼�����
	while (1)
	{
		menu();
		printf("����������ѡ��:--> ");
		scanf("%d", &choose);	//choose��ʾ�ⲿ�˵���ѡ��
		getchar();			//������û������Ļس��ַ�
		printf("\n����ִ������ѡ��");
		SleepCls();				//0.5��˯�߼�����
		switch (choose)
		{
		case 1:
		{
				 char isagain = 'y';
				 while (isagain == 'y' || isagain == 'Y')
				 {
					 printf("��������Ҫ���ӵ��û���Ϣ��\n");
					 printf("----------------------------------\n");
					 AddList(head);		 //�����û���Ϣ
					 printf("�Ƿ���������û���Ϣ(y����Y)-->"); 
					 getchar();			//������û������Ļس��ַ�
					 scanf("%c", &isagain);
					 SleepCls();
				 }
				 break;
		}
		case 2:
			DeleteListNode(head);	//ɾ���û���Ϣ
			break;
		case 3://�û������Һ��޸��û���Ϣ
		{
				  NameTableH* HTname;
				  HTname = (NameTableH*)malloc(sizeof(NameTableH));
				  InitNameTableH(HTname);		//��ʼ������ɢ�б�
				  SetNameTableH(HTname, head);	//����ɢ�б�
				  menuFind();					//��ӡ���Ҳ˵�
				  scanf("%d", &input);			//input �ڲ��˵���ѡ��
				  switch (input)
				  {
				  case 1:						//����
					  printf("������Ҫ��Ѱ�û���������");
					  char name[MAX_N] = "\0";
					  scanf("%s", name);
					  FindNameTableH(HTname, name);//�������Һ���
					  break;
				  case 2:						//�޸�
					  ChangeNameTableH(HTname);	//�Ȳ������޸�
					  break;
				  }
				  break;
		}	
		case 4://�绰������Һ��޸��û���Ϣ
		{
				  TeleListH* HTTele;			//�绰�����ϣ��Ľṹ��
				  HTTele = (TeleListH*)malloc(sizeof(TeleListH));
				  InitTeleListH(HTTele);		//��ʼ��
				  SetTeleListH(HTTele, head);	//�����绰�����ϣ��
				  menuFind();					//��ӡ���Ҳ˵�
				  scanf("%d", &input);			//input �ڲ��˵���ѡ��
				  switch (input)
				  {
				  case 1:						//����
					  printf("������Ҫ��Ѱ�û��ĵ绰���룺");
					  char telephone[MAX_T] = { '\0' };
					  scanf("%d", &telephone);
					  FindTeleListH(HTTele, telephone);	//�绰�������
					  break;
				  case 2:						//�޸�
					  ChangeTeleListH(HTTele);	//�Ȳ������޸�
					  break;
				  }
				  break;
		}
		case 5:
			WriteFileInfo(head);	//д���ļ�
			break;
		case 6:
			ReadFileInfo(head);		//��ȡ�ļ���Ϣ
			break;
		case 7:
			InsertSort(head);		//��������
			break;
		case 8:
			ShowInfo(head);			//��ӡ������Ϣ
			break;
		default:
			WriteFileInfo(head);	//д���ļ�  ����������������Ϣ�����ļ�����
			printf("\n��лʹ��~\n");
			return 0;
		}
		if (choose != 1)
		{
			system("pause");
			SleepCls();
		}
	}
}

//void text1(InfoNode_List* phead)
//{
//	InitList(phead);	//��ʼ��
//	ReadFileInfo(phead);
//	CreatList(phead);   //�����û���Ϣ
//	DeleteListNode(phead);	//ɾ���û���Ϣ
//	BubbleSort(phead);
//	WriteFileInfo(phead);
//	ShowInfo(phead);
//}
//
//void text2(InfoNode_List* phead)
//{
//	NameTableH* HTname;
//	HTname = (NameTableH*)malloc(sizeof(NameTableH));
//
//	InitNameTableH(HTname);//��ʼ��������ϣ��
//	SetNameTableH(HTname, phead);
//	char name[MAX_N] = "duchenlong";
//	FindNameTableH(HTname, name);
//	ChangeNameTableH(HTname);
//}
//
//void text3(InfoNode_List* phead)
//{
//	TeleListH* HTTele;
//	HTTele = (TeleListH*)malloc(sizeof(TeleListH));
//	InitTeleListH(HTTele);
//	SetTeleListH(HTTele,phead);
//	char telephone[MAX_T] = "13325430774";
//	FindTeleListH(HTTele,telephone);
//	ChangeTeleListH(HTTele);
//}
////int main()
//{
//	InfoNode_List* head;
//	head = (InfoNode_List*)malloc(sizeof(InfoNode_List));
//	text1(head);	//������Բ��Խӿ�
//	//text2(head);	//����Ϊ�ؼ��ֹ�ϣ��Ĳ��Խӿ�
//	text3(head);
//	return 0;
//}