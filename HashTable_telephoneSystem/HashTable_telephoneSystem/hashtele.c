#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"
#include "hashtele.h"

//初始化哈希链
void InitTeleListH(TeleListH* pt)
{
	assert(pt);

	pt->_TeleArr = (HTTele*)malloc(sizeof(HTTele)*MAX_TELEARR);	//开辟存储信息的空间
	int i = 0;
	for (i = 0; i < MAX_TELEARR; i++)
	{
		pt->_TeleArr[i].next = NULL;	//每一层的链头的next指针初始化为NULL
	}
}

//建立哈希链
void SetTeleListH(TeleListH* pt, InfoNode_List* phead)
{
	assert(pt && phead);

	if (phead==phead->_next)					//判断有没有用户信息可以查找
	{
		printf("没有用户的信息！\n");
		return;
	}
	InfoNode_List* node = phead->_next;
	int len = 0;
	while (node!=phead)
	{
		int key = 0;
		len = strlen(node->_ListInfo->_telephone);
		while (len)								//计算权值
		{
			key += (int)node->_ListInfo->_telephone[len - 1];
			key %=MAX_TELEARR;					//除留余数法  除数为链的高度
			len--;
		}

		//建立一个新的链节点
		HTTele* Newnode = (HTTele*)malloc(sizeof(HTTele));
		Newnode->_TeleInfo = node->_ListInfo;	 //用户信息的复制
		Newnode->next = NULL;

		if (!pt->_TeleArr[key].next)			//如果该位置的头没有地址
		{
			pt->_TeleArr[key].next = Newnode;
		}
		else
		{
			//在当前链的头进行插入
			Newnode->next=pt->_TeleArr[key].next;
			pt->_TeleArr[key].next = Newnode;
		}
		node = node->_next;
	}
	
	my_loading(3);	//模拟加载
	printf("电话号码哈希链建立完毕\n");
	system("pause");
	SleepCls();		//0.5秒睡眠+清屏
}

//电话号码查找用户
InfoNode* FindTeleListH(TeleListH* pt, const char* telephone)
{
	assert(pt);

	int key = 0;
	int len = strlen(telephone);
	while (len)				//计算权值
	{
		key += (int)telephone[len - 1];
		key %= MAX_TELEARR; //除留余数法  除数为链的高度
		len--;
	}

	if (!pt->_TeleArr[key].next)
	{
		printf("没有找到该用户\n");
		return NULL;
	}
	else
	{
		HTTele* Newnode = pt->_TeleArr[key].next;
		while (Newnode)
		{
			if (strcmp(Newnode->_TeleInfo->_telephone, telephone) == 0)
			{
				ShowOnce(Newnode->_TeleInfo);	//打印要查找的该用户信息
				return Newnode->_TeleInfo;		//函数返回该用户的信息节点
			}
			Newnode = Newnode->next;
		}
	}
	return NULL;
}

//修改用户信息
void ChangeTeleListH(TeleListH* pt)
{
	assert(pt);

	printf("请输入要修改用户的电话号码-->");
	char tele[MAX_T];
	scanf("%s", tele);
	InfoNode* Newnode=FindTeleListH(pt, tele);
	system("pause");					//程序暂停，按任意键继续
	if (!Newnode)			//如果查找函数返回值为NULL,表示未找到，直接返回
	{
		return;
	}
	SleepCls();
	printf("请重新输入该用户的信息：\n");
	ChangeNode(Newnode);	//重新输入该用户的新的所有信息
}