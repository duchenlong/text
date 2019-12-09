#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"
#include"hashname.h"
#include "hashtele.h"

void menuFind()
{
	printf("-----------------------------------------\n");
	printf("|\t查找用户信息-->1\t\t|\n");
	printf("-----------------------------------------\n");
	printf("|\t修改用户信息-->2\t\t|\n");
	printf("-----------------------------------------\n");
	printf("您的选择-->");
}

void menu()
{
	printf("\t _______________________________________\n");
	printf("\t|\t散列表电话号码查询系统\t\t|\n");
	printf("\t|\t  1.增加用户信息\t\t|\n");
	printf("\t|\t  2.删除用户信息\t\t|\n");
	printf("\t|\t  3.用户名查找和修改用户信息    |\n");
	printf("\t|\t  4.电话号码查找和修改用户信息\t|\n");
	printf("\t|\t  5.用户信息载入文件\t\t|\n");
	printf("\t|\t  6.从文件中读取用户信息\t|\n");
	printf("\t|\t  7.对用户信息进行排序\t\t|\n");
	printf("\t|\t  8.打印所有用户信息\t\t|\n");
	printf("\t|\t  0.退出\t\t\t|\n");
	printf("\t|_______________________________________|\n\n");
}

int main()
{
	int input=1;
	int choose;
	InfoNode_List* head;		 //建立双向循环链表的头结点
	head = (InfoNode_List*)malloc(sizeof(InfoNode_List));
	InitList(head);				//初始化链表
	ReadFileInfo(head);			//读取文件信息  系统开始时自动读取文件中的信息
	SleepCls();					//0.5秒睡眠加清屏
	while (1)
	{
		menu();
		printf("请输入您的选择:--> ");
		scanf("%d", &choose);	//choose表示外部菜单的选项
		getchar();			//处理掉用户输入后的回车字符
		printf("\n即将执行您的选择");
		SleepCls();				//0.5秒睡眠加清屏
		switch (choose)
		{
		case 1:
		{
				 char isagain = 'y';
				 while (isagain == 'y' || isagain == 'Y')
				 {
					 printf("请输入需要增加的用户信息：\n");
					 printf("----------------------------------\n");
					 AddList(head);		 //增加用户信息
					 printf("是否继续输入用户信息(y或者Y)-->"); 
					 getchar();			//处理掉用户输入后的回车字符
					 scanf("%c", &isagain);
					 SleepCls();
				 }
				 break;
		}
		case 2:
			DeleteListNode(head);	//删除用户信息
			break;
		case 3://用户名查找和修改用户信息
		{
				  NameTableH* HTname;
				  HTname = (NameTableH*)malloc(sizeof(NameTableH));
				  InitNameTableH(HTname);		//初始化姓名散列表
				  SetNameTableH(HTname, head);	//建立散列表
				  menuFind();					//打印查找菜单
				  scanf("%d", &input);			//input 内部菜单的选项
				  switch (input)
				  {
				  case 1:						//查找
					  printf("请输入要查寻用户的姓名：");
					  char name[MAX_N] = "\0";
					  scanf("%s", name);
					  FindNameTableH(HTname, name);//姓名查找函数
					  break;
				  case 2:						//修改
					  ChangeNameTableH(HTname);	//先查找再修改
					  break;
				  }
				  break;
		}	
		case 4://电话号码查找和修改用户信息
		{
				  TeleListH* HTTele;			//电话号码哈希表的结构体
				  HTTele = (TeleListH*)malloc(sizeof(TeleListH));
				  InitTeleListH(HTTele);		//初始化
				  SetTeleListH(HTTele, head);	//建立电话号码哈希表
				  menuFind();					//打印查找菜单
				  scanf("%d", &input);			//input 内部菜单的选项
				  switch (input)
				  {
				  case 1:						//查找
					  printf("请输入要查寻用户的电话号码：");
					  char telephone[MAX_T] = { '\0' };
					  scanf("%d", &telephone);
					  FindTeleListH(HTTele, telephone);	//电话号码查找
					  break;
				  case 2:						//修改
					  ChangeTeleListH(HTTele);	//先查找再修改
					  break;
				  }
				  break;
		}
		case 5:
			WriteFileInfo(head);	//写入文件
			break;
		case 6:
			ReadFileInfo(head);		//读取文件信息
			break;
		case 7:
			InsertSort(head);		//插入排序
			break;
		case 8:
			ShowInfo(head);			//打印所有信息
			break;
		default:
			WriteFileInfo(head);	//写入文件  程序结束对输入的信息进行文件保护
			printf("\n感谢使用~\n");
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
//	InitList(phead);	//初始化
//	ReadFileInfo(phead);
//	CreatList(phead);   //增加用户信息
//	DeleteListNode(phead);	//删除用户信息
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
//	InitNameTableH(HTname);//初始化姓名哈希表
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
//	text1(head);	//链表调试测试接口
//	//text2(head);	//姓名为关键字哈希表的测试接口
//	text3(head);
//	return 0;
//}