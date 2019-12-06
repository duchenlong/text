#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

//初始化链表
void InitList(InfoNode_List* phead)
{
	assert(phead);

	phead->next = NULL;//头结点的下一个节点为NULL
}

//节点输入用户信息
void ScanfNode(InfoNode* pnode)
{
	char name[MAX_N] = { '\0' }, telephone[MAX_T] = { '\0' }, address[MAX_A] = { '\0' };
	printf("请输入用户姓名-->");
	gets(name);
	strcpy(pnode->_name, name);
	printf("请输入用户电话号码-->");
	gets(telephone);
	strcpy(pnode->_telephone, telephone);
	printf("请输入用户地址-->");
	gets(address);
	strcpy(pnode->_address, address);
}

//创建链表
void CreatList(InfoNode_List* phead)	//采用头插法
{
	assert(phead);	//防止传入野指针

	InfoNode_List* node;
	node = (InfoNode_List*)malloc(sizeof(InfoNode_List));	
	node->_ListInfo = (InfoNode*)malloc(sizeof(InfoNode));//为用户信息结构体开辟空间
	ScanfNode(node->_ListInfo);//输入用户信息

	node->next = phead->next;
	phead->next = node;
}

//删除节点
void DeleteListNode(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* pre = (InfoNode_List*)malloc(sizeof(InfoNode_List));
	char sure='\0';
	int option=0;
	//打印内部菜单
	printf("-----------------------------------------\n");
	printf("|\t按用户姓名删除-->1\t\t|\n");
	printf("-----------------------------------------\n");
	printf("|\t按用户电话号码查找并删除-->0\t|\n");
	printf("-----------------------------------------\n");
	printf("您的选择-->");
	scanf("%d", &option);
	getchar();	//吸收scanf函数输入停止时的回车字符
	switch (option)
	{
		case 1:
		{
			  char name[MAX_N] = { '\0' };
			  printf("请输入想要删除联系人的姓名-->");
			  gets(name);
			  pre = FindName(phead, name);	////返回要删除节点的前一个节点
			  break;
		}
		case 0:
		{
			char telephone[MAX_T] = { '\0' };
			printf("请输入想要删除用户的电话号码-->");
			gets(telephone);
			pre = FindTelephone(phead, telephone);	//返回要删除节点的前一个节点
			break; 
		}
	}
	if (pre)//如果找到该节点，最后确认一次是否删除
	{
		printf("确认删除？y/Y -->");
		scanf("%c", &sure);
		if (sure == 'y' || sure == 'Y')//确认删除进行链表删除操作
		{
			InfoNode_List* cur = pre->next;
			pre->next = cur->next;
			free(cur);//释放掉要删除的节点空间
			printf("删除成功\n");
		}
		else
		{
			printf("取消删除，返回主页面\n");//不想删除则返回主页面
		}
	}
}

//姓名查找（删除函数中调用）
InfoNode_List* FindName(InfoNode_List* phead, char* name)
{
	assert(phead  && name);//防止传入野指针

	InfoNode_List* node = phead;//保留头结点位置
	//寻找该用户
	//循环结束的条件  链表指针cur指向NULL  或  cur的下一个节点为要删除的节点
	while (node  &&  strcmp(node->next->_ListInfo->_name, name) != 0)
	{
		node = node->next;//移动指针
	}
	if (node)
	{
		//找到后进行打印
		printf("该用户已经找到\n");
		printf("姓名\t\t电话号码\t\t地址\n");
		printf("%s\t\t%s\t\t%s\n", node->next->_ListInfo->_name, \
			                       node->next->_ListInfo->_telephone, \
								   node->next->_ListInfo->_address );
		return node;//返回要删除节点的上一个节点
	}
	else
	{
		printf("没有找到该用户,将返回主页面\n");
		return NULL;//返回为NULL
	}
}

//打印链表中的用户信息
void ShowInfo(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* node = phead->next;
	if (!node)//防止链表中没有用户信息
	{
		printf("没有用户信息可以打印\n");
		return;
	}
	printf("\t姓名\t   电话号码\t   地址\n");
	printf("---------------------------------------------------------\n");
	while (node)
	{
		printf("%12s\t%11s\t%s\n",	node->_ListInfo->_name, \
										node->_ListInfo->_telephone, \
										node->_ListInfo->_address);
		printf("---------------------------------------------------------\n");
		node = node->next;
	}
	printf("---------------------------------------------------------\n");
}


//电话号码查找（删除函数中调用）
InfoNode_List* FindTelephone(InfoNode_List* phead, char* telephone)
{
	assert(phead  && telephone);//防止传入野指针

	InfoNode_List* node = phead;//保留头结点位置
	//寻找该用户
	//循环结束的条件  链表指针cur指向NULL  或  cur的下一个节点为要删除的节点
	while (node  &&  strcmp(node->next->_ListInfo->_telephone, telephone) != 0)
	{
		node = node->next;//移动节点
	}
	if (node)	//如果找到，对要删除节点进行打印
	{
		printf("该用户已经找到\n");
		printf("姓名\t\t电话号码\t\t地址\n");
		printf("%s\t\t%s\t\t%s\n",	node->next->_ListInfo->_name, \
									node->next->_ListInfo->_telephone, \
									node->next->_ListInfo->_address);
		return node;//函数返回要删除节点的上一个节点
	}
	else
	{
		printf("没有找到该用户,将返回主页面\n");
		return NULL;//没有找到则返回NULL
	}
}

//将链表的信息写入文件
void WriteFileInfo(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* node = phead->next;
	if (!node)	//防止链表中没有用户信息
	{
		printf("没有需要储存的用户信息\n");
		return;
	}
	int num = 0;//记录用户数量
	FILE* fp;//文件指针
	fp = fopen("text.txt", "w");// 打开写入的文件 
	//文件指针完成的功能是写，打开的文件是 text.txt
	while (node)
	{
		fprintf(fp, "-%s\t\t%s\t\t%s\n", node->_ListInfo->_name, \
										node->_ListInfo->_telephone,\
										node->_ListInfo->_address);
		node = node->next;
		num++;
	}
	fprintf(fp, "|\t\t共%d个用户信息\t\t|\n",num);
	fclose(fp);//关闭文件
	printf("信息写入成功\n");
}

//读取文件中的信息
void ReadFileInfo(InfoNode_List* phead)
{
	assert(phead);

	FILE* fp;//建立文件指针
	char flag='\0';//判断文件读取结束的标志
	fp = fopen("text.txt", "r");//打开文件
	while ((flag = fgetc(fp)) != '|')
	{
		//创建一个节点来存储文件中的用户信息
		InfoNode_List* node;
		node = (InfoNode_List*)malloc(sizeof(InfoNode_List));
		node->_ListInfo = (InfoNode*)malloc(sizeof(InfoNode));//为用户信息结构体开辟空间
		fscanf(fp, "%s%s%s", node->_ListInfo->_name, \
							node->_ListInfo->_telephone, \
							node->_ListInfo->_address);
		flag = fgetc(fp);//处理掉当前行末的换行符
		//节点插入(头插法)
		node->next = phead->next;
		phead->next = node;
	}
	fclose(fp);//关闭文件
	printf("用户电话号码信息载入完毕\n");
}




