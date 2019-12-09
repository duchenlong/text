#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

//睡眠加清屏
void SleepCls()
{
	Sleep(500);//程序在这里暂停0.5秒
	system("cls");//清屏操作
}

//初始化链表
void InitList(InfoNode_List* phead)
{
	assert(phead);

	phead->_next = phead;	//头结点的下一个节点指向自己
	phead->_pre = phead;	//头结点的上一个节点指向自己
}

//节点输入用户信息
void ScanfNode(InfoNode* pnode)
{
	char name[MAX_N] = { '\0' }, telephone[MAX_T] = { '\0' }, address[MAX_A] = { '\0' };
	printf("_______________________________________\n");
	printf("|\n");
	printf("|请输入用户姓名-->");
	scanf("%s", name);
	strcpy(pnode->_name, name);
	printf("|请输入用户电话号码-->");
	scanf("%s",telephone);
	strcpy(pnode->_telephone, telephone);
	printf("|请输入用户地址-->");
	scanf("%s",address);
	strcpy(pnode->_address, address);
	printf("|______________________________________\n");
}

//修改用户信息
void ChangeNode(InfoNode* pnode)
{
	char choose_C;
	char name[MAX_N] = { '\0' }, telephone[MAX_T] = { '\0' }, address[MAX_A] = { '\0' };
	printf("_______________________________________\n");
	printf("|\n");
	printf("|请输入修改后用户姓名-->");
	scanf("%s", name);
	strcpy(pnode->_name, name);
	printf("|请输入修改后用户电话号码-->");
	scanf("%s", telephone);
	strcpy(pnode->_telephone, telephone);
	printf("|是否修改用户的地址(Y或者y)-->");
	getchar();			//吸收电话号码输入后的回车字符
	scanf("%c", &choose_C);
	if (choose_C == 'y' || choose_C == 'Y')
	{
		printf("|请输入用户地址-->");
		scanf("%s", address);
		strcpy(pnode->_address, address);
	}
	else
	{
		printf("|用户地址  -->%s\n", pnode->_address);
	}
	printf("|______________________________________\n");
}

//增加用户信息
void AddList(InfoNode_List* phead)		//采用头插法
{
	assert(phead);						//防止传入野指针

	InfoNode_List* node;
	node = (InfoNode_List*)malloc(sizeof(InfoNode_List));	
	node->_ListInfo = (InfoNode*)malloc(sizeof(InfoNode));	//为用户信息结构体开辟空间
	ScanfNode(node->_ListInfo);			//输入用户信息

	//头插法进行节点的插入
	node->_next = phead->_next;
	phead->_next->_pre = node;

	node->_pre = phead;
	phead->_next = node;

	printf("----------------------------------\n");
	printf("%s的信息增加完毕\n\n", node->_ListInfo->_name);
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
	printf("|\t按用户姓名删除(系统默认)-->1\t|\n");
	printf("-----------------------------------------\n");
	printf("|\t按用户电话号码查找并删除-->0\t|\n");
	printf("-----------------------------------------\n");
	printf("您的选择-->");
	scanf("%d", &option);
	if (option != 0)	//默认按照姓名查询删除
	{
		option = 1;
	}
	getchar();			//吸收scanf函数输入停止时的回车字符
	switch (option)
	{
		case 1:
		{
			  char name[MAX_N] = { '\0' };
			  printf("请输入想要删除联系人的姓名-->");
			  gets(name);
			  pre = FindName(phead, name);			//返回要删除节点
			  break;
		}
		case 0:
		{
			char telephone[MAX_T] = { '\0' };
			printf("请输入想要删除用户的电话号码-->");
			gets(telephone);
			pre = FindTelephone(phead, telephone);	//返回要删除节点
			break; 
		}
	}
	if (pre)			//如果找到该节点，最后确认一次是否删除
	{
		printf("确认删除？y/Y -->");
		scanf("%c", &sure);
		if (sure == 'y' || sure == 'Y')			//确认删除进行链表删除操作
		{
			InfoNode_List* cur = pre;
			cur->_pre->_next = cur->_next;
			cur->_next->_pre = cur->_pre;
			free(cur);							//释放掉要删除的节点空间
			printf("删除成功\n");
		}
		else
		{
			printf("取消删除，返回主页面\n");	//不想删除则返回主页面
		}
	}
}

//姓名查找（删除函数中调用）
InfoNode_List* FindName(InfoNode_List* phead, char* name)
{
	assert(phead  && name);				//防止传入野指针

	InfoNode_List* node = phead->_next;	//保留头结点位置

	//寻找该用户
	//循环结束的条件  链表指针node指向头结点  或  node节点为要删除的节点
	while (node!=phead  &&  strcmp(node->_ListInfo->_name, name) != 0)
	{
		node = node->_next;				//移动指针
	}
	if (node!=phead)
	{
		//找到后进行打印
		printf("该用户已经找到\n");
		ShowOnce(node->_ListInfo);
		return node;		//返回要删除节点
	}
	else
	{
		printf("没有找到该用户,将返回主页面\n");
		return NULL;		//返回为NULL
	}
}

//打印链表中的用户信息
void ShowInfo(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* node = phead->_next;
	if (node==phead)			//防止链表中没有用户信息
	{
		printf("没有用户信息可以打印\n");
		return;
	}
	printf("_________________________________________________________\n");
	printf("\t姓名\t   电话号码\t   地址\n");
	printf("_________________________________________________________\n");
	while (node!=phead)
	{
		printf("%12s\t%11s\t%s\n",	node->_ListInfo->_name, \
									node->_ListInfo->_telephone, \
									node->_ListInfo->_address);
		printf("---------------------------------------------------------\n");
		node = node->_next;
	}
}

//打印一个节点的信息
void ShowOnce(InfoNode* pi)
{
	assert(pi);

	printf(" _________________________________________________\n");
	printf("|\n");
	printf("|姓名：	   %s\n", pi->_name);
	printf("|电话号码：%s\n", pi->_telephone);
	printf("|地址：    %s\n", pi->_address);
	printf("|_________________________________________________\n");
}


//电话号码查找（删除函数中调用）
InfoNode_List* FindTelephone(InfoNode_List* phead, char* telephone)
{
	assert(phead  && telephone);		//防止传入野指针

	InfoNode_List* node = phead->_next;	//保留头结点位置

	//寻找该用户
	//循环结束的条件  链表指针node指向phead  或  node为要删除的节点
	while (node!=phead  &&  strcmp(node->_ListInfo->_telephone, telephone) != 0)
	{
		node = node->_next;				//移动节点
	}
	if (node!=phead)					//如果找到，对要删除节点进行打印
	{
		printf("该用户已经找到\n");
		ShowOnce(node->_ListInfo);
		return node;					//函数返回要删除节点
	}
	else
	{
		printf("没有找到该用户,将返回主页面\n");
		return NULL;					//没有找到则返回NULL
	}
}

//按字符ASCLL比较两个用户信息的大小
int CompareInfo(InfoNode* pi1, InfoNode* pi2)
{
	assert(pi1 && pi2);

	int ans=0;				//记录比较后的结果
	/*ans = strcmp(pi1->_name, pi2->_name);		//先按照姓名比较
	if (ans == 0)			//结果为0，表示名字相等  再比较电话号码
	{
		//电话号码不可能相等，返回比较后的结果
		ans = strcmp(pi1->_telephone, pi2->_telephone);
	}
	return ans;*/

	return (ans = strcmp(pi1->_name, pi2->_name)) != 0 ? \
					ans : strcmp(pi1->_telephone, pi2->_telephone);
}

//排序   --> 循环双链表的插入排序法
void InsertSort(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* cur = phead->_next;	//cur 指针记录当前被比较的节点
	InfoNode_List* node = cur->_next;   //node 指针记录需要比较的节点
	InfoNode_List* nodenext;            //nodenext 指针记录下一个需要比较的节点
	
	while (node!=phead)					//循环退出的条件  node节点不是头结点
	{
		cur = phead->_next;				//每次比较都从头结点的下一个节点开始

		//找到第一个比node节点信息大的节点，这个节点记录为cur
		while (cur != node && \
			CompareInfo(cur->_ListInfo, node->_ListInfo) <= 0)
		{
			cur = cur->_next;
		}

		nodenext = node->_next;			//保存需要比较节点的下一个节点
		//如果cur==node  表示该节点就是前面节点中最大的，不做处理，跳出循环
		if (cur != node)
		{
			//先连接node节点的前后两个节点
			nodenext->_pre = node->_pre;  
			node->_pre->_next = nodenext;

			//再连接node节点和cur节点的前一个节点
			cur->_pre->_next = node;
			node->_pre = cur->_pre;

			//最后把node节点和cur连接，完成在cur节点的前面插入
			node->_next = cur;
			cur->_pre = node;
		}

		//把下一个需要比较的节点给node
		node = nodenext;
		nodenext = node->_next;
	}
	
	char choose_s='\0';
	my_loading(3);
	printf("链表信息的排序已完成\n");
	printf("是否显示排序后的链表(y或Y)-->");
	
	scanf("%c", &choose_s);
	if (choose_s == 'y' || choose_s == 'Y')
	{
		SleepCls();			//睡眠加清屏
		ShowInfo(phead);	//打印信息
	}
}

//模拟加载界面
void my_loading(const int time)
{
	int i = 0;
	for (i = 1; i < time; i++)
	{
		printf("\t%d......\n",i);
		Sleep(500);
	}
}

//将链表的信息写入文件
void WriteFileInfo(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* node = phead->_next;
	if (node==phead)				//防止链表中没有用户信息
	{
		printf("没有需要储存的用户信息\n");
		return;
	}
	int num = 0;					//记录用户数量
	FILE* fp;						//文件指针
	fp = fopen("text.txt", "w");	// 打开写入的文件 
	//文件指针完成的功能是写，打开的文件是 text.txt

	while (node!=phead)
	{
		fprintf(fp, "-%s\t\t%s\t\t%s\n", node->_ListInfo->_name, \
										node->_ListInfo->_telephone,\
										node->_ListInfo->_address);
		node = node->_next;
		num++;			//记录载入用户的数量
	}
	fprintf(fp, "|\t\t共%d个用户信息\t\t|\n",num);
	fclose(fp);			//关闭文件
	my_loading(4);		//模拟加载界面
	printf("用户信息已保存\n");
}

//读取文件中的信息
void ReadFileInfo(InfoNode_List* phead)
{
	assert(phead);

	FILE* fp;			//建立文件指针
	char flag='\0';		//判断文件读取结束的标志
	fp = fopen("text.txt", "r");	//打开文件
	while ((flag = fgetc(fp)) != '|')
	{
		//创建一个节点来存储文件中的用户信息
		InfoNode_List* node;
		node = (InfoNode_List*)malloc(sizeof(InfoNode_List));
		//为用户信息结构体开辟空间
		node->_ListInfo = (InfoNode*)malloc(sizeof(InfoNode));
		fscanf(fp, "%s%s%s", node->_ListInfo->_name, \
							node->_ListInfo->_telephone, \
							node->_ListInfo->_address);
		flag = fgetc(fp);	//处理掉当前行末的换行符

		//节点插入(尾插法)
		//先把node节点和链表的尾连起来
		node->_pre = phead->_pre->_next;
		phead->_pre->_next = node;

		//再把node节点和链表的头连接起来
		node->_next = phead;
		phead->_pre = node;
	}
	fclose(fp);				//关闭文件
	my_loading(4);			//模拟加载界面
	printf("用户电话号码信息载入完毕\n");
}




