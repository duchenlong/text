#define _CRT_SECURE_NO_WARNINGS 1

#include "hashname.h"

//初始化哈希表
void InitNameTableH(NameTableH* pn)
{
	assert(pn);

	pn->_psize = 0;			//数组中没有成员
	pn->_capacity = DIV;	//数组当前的容量为除留余数法的除数
	pn->_NameArr = (HTName*)malloc(sizeof(HTName)*pn->_capacity);
	//为数组开辟当前容量的空间

	int i = 0;
	for (i = 0; i < pn->_capacity; i++)
	{
		//将数组每个位置初始化为0
		//0表示该位置没有存放成员信息
		pn->_NameArr[i]._ishave = 0;	
	}
}

//哈希表扩容
void AddCapacity(NameTableH* pn, const int key)
{
	assert(pn && key < pn->_capacity);

	pn->_capacity *= 2;
	pn->_NameArr = realloc(pn->_NameArr, sizeof(HTName)*pn->_capacity);
	//realloc函数进行扩容，不会改变数组原来空间内容的信息
	//每次扩容的大小为当前容量的2倍

	int i = 0;
	for (i = pn->_psize;i< pn->_capacity; i++)
	{
		pn->_NameArr[i]._ishave = 0;					//初始化新增加的空间有无用户的情况
	}

	//为了不改变哈希表查找时候的顺序
	//扩容完毕后，将数组中当前权值前面的信息都依次移动到新开辟的地方后面
	for (i = 0; i < key; i++)
	{
		pn->_NameArr[i + pn->_psize]._NameInfo = pn->_NameArr[i]._NameInfo;	//用户信息移动
		pn->_NameArr[i + pn->_psize]._key = pn->_NameArr[i]._key;			//权值移动
		pn->_NameArr[i]._ishave = 0;					//当前位置置为无值
		pn->_NameArr[i + pn->_psize]._ishave = 1;		//移动后的位置置为有值
	}
}

//建立哈希表
void SetNameTableH(NameTableH* pn, InfoNode_List* phead)
{
	assert(pn && phead);

	if (phead==phead->_next)
	{
		printf("没有用户的信息！\n");
		return;
	}
	InfoNode_List* node = phead->_next;
	char Fname, Lname;	//一个表示姓名的首字符，一个表示尾字符
	int len;			//表示姓名的长度
	int key;			//表示计算后的权值
	while (node!=phead)
	{
		Fname = node->_ListInfo->_name[0];
		len = strlen(node->_ListInfo->_name);
		Lname = node->_ListInfo->_name[len-1];
		key = (int)(Fname + Lname) % DIV;	//计算权值

		if (pn->_psize == pn->_capacity)	//判断是否需要扩容
		{
			AddCapacity(pn,key);
		}

		if (!pn->_NameArr[key]._ishave)//该位置没有出现冲突
		{
			//将该节点中用户信息节点 赋值给 哈希表中该位置用户信息节点
			pn->_NameArr[key]._NameInfo = node->_ListInfo;
			//记录该位置权值
			pn->_NameArr[key]._key = key;
			//修改该位置为有值
			pn->_NameArr[key]._ishave = 1;
		}
		else //出现冲突，用再散列法解决冲突
		{
			int i = key+1;
			while (pn->_NameArr[i]._ishave)//找到第一个不冲突的节点
			{
				i = (i + 1) % pn->_capacity;//让该位置在逻辑上动态连接起来
			}

			//将该节点中用户信息节点 赋值给 哈希表中该位置用户信息节点
			pn->_NameArr[i]._NameInfo = node->_ListInfo;
			//记录该位置权值
			pn->_NameArr[i]._key = key;
			//修改该位置为有值
			pn->_NameArr[i]._ishave = 1;
		}

		node = node->_next;
		pn->_psize++;
	}

	my_loading(3);	//模拟加载
	printf("\t姓名哈希表建立完毕\n");
	system("pause"); 
	SleepCls();		//0.5秒睡眠+清屏
}

//查找用户信息
int FindNameTableH(NameTableH* pn, const char* name)
{
	assert(pn && name);

	char Fname, Lname;
	Fname = name[0];
	int len = strlen(name);
	Lname = name[len - 1];  //取首字符和尾字符

	int key = (int)(Fname + Lname) % DIV;	//计算权值
	int i = key;
	int count = 0;
	//查找时循环跳出的条件
	//1.当前位置没有存放用户信息
	//2.如果数组可以存放的用户已经满了，并且没有需要查找的人
	//即循环走了当前容量的步骤  ---> count==pn->_capacity
	//3.权值相同
	while (		pn->_NameArr[i]._ishave  \
			&& (count++)<pn->_capacity	 \
		   &&   pn->_NameArr[i]._key != key)
	{
		i++;
	}
	//判断是哪种条件跳出循环
	//如果是1 2 ，则表示没有找到，退出函数
	if (pn->_capacity == count || !pn->_NameArr[i]._ishave)
	{
		printf("没有找到该用户\n");
		return -1;
	}
	//3 表示找到，进行打印
	ShowOnce(pn->_NameArr[i]._NameInfo);
	return i;
}

//修改用户信息
void ChangeNameTableH(NameTableH* pn)
{
	assert(pn);

	char name[MAX_N] = { '\0' };
	printf("请输入需要修改的用户的姓名-->");
	scanf("%s", name);
	int i = FindNameTableH(pn,name);	//调用函数先来查找用户
	system("pause");					//程序暂停，按任意键继续
	if (i != -1)						//表示找到该用户
	{
		SleepCls();
		printf("请重新输入该用户的信息：\n");
		ChangeNode(pn->_NameArr[i]._NameInfo);//重新输入该用户的信息,选择性输入地址
	}
}