#define _CRT_SECURE_NO_WARNINGS 1

#include"hash.h"

//初始化哈希表
void InitHash(HashTable* ph)
{
	assert(ph);
	ph->_size=0;
	ph->_capacity = DIV;	//初始容量为除留余数法的余数
	ph->_HashArr = (NameNode*)malloc(ph->_capacity*sizeof(NameNode));
	int i = 0;
	//内部初始化哈希表
	for (i = 0; i < ph->_capacity; i++)
	{
		//让内部表信息 改为没有值
		ph->_HashArr[i]._ishave = 0;
	}
}
//输入元素并建立哈希表
void ScanfHash(HashTable* ph)
{
	int num,i;
	char name[MAX_NAME] = { '\0' };
	printf("输入同学信息的个数：-->");
	scanf("%d", &num);
	getchar();//清除scanf函数使用都的回车字符
	for (i = 0; i < num; i++)
	{
		gets(name);
		SetHash(ph, name); //存储
	}
}
//扩容
void AddCapacity(HashTable* ph, int key)
{
	ph->_capacity *= 2;//容量增加一倍
	ph->_HashArr = realloc(ph->_HashArr,sizeof(NameNode)*ph->_capacity);
	int i = 0;
	//初始化增加后部分的存储单元
	for (i = ph->_size; i < ph->_capacity; i++)
	{
		ph->_HashArr[i]._ishave = 0;
	}
	//将改存储位置之前的元素移动到扩容的地方
	for (i = 0; i < key; i++)
	{
		ph->_HashArr[i + ph->_size] = ph->_HashArr[i];
		ph->_HashArr[i]._ishave = 0;//移动之后，将该位置弄成没有值的情况
	}
}

void SetHash(HashTable* ph, char* name)
{
	char Fsex, Fname;  //Fsex ->姓的首字母  Fname ->名的首字母
	int i = 0,key;
	while (name[i] != ' ')  //找到名的首字母
	{
		i++;
	}
	Fsex = name[0];
	Fname = name[i + 1];
	key = (int)(Fsex + Fname)%DIV;	//key 哈希表的存储位置
	if (ph->_size == ph->_capacity)//如果哈希表已满，进行扩容
	{
		AddCapacity(ph, key);
	}
	if (!ph->_HashArr[key]._ishave)	//该位置没值时直接进行赋值
	{
		strcpy(ph->_HashArr[key]._name, name);//字符串的复制用strcpy函数
		ph->_HashArr[key]._key = key;
		ph->_HashArr[key]._ishave = 1;
	}
	else
	{
		i = key+1;
		//采用线性探测再散列的方式处理冲突
		while (i != key) 
		{
			if (!ph->_HashArr[i]._ishave)
			{
				strcpy(ph->_HashArr[i]._name, name);
				ph->_HashArr[i]._key = key;
				ph->_HashArr[i]._ishave = 1;
				break;
			}
			i = (i + 1) % ph->_capacity;	//让哈希表逻辑上连成圈
		} 
	}
	ph->_size++;// 表中元素增加
}
//展示哈希表
void ShowHash(HashTable* ph)
{
	int i = 0,j=0;
	while (i != ph->_size)
	{
		if (ph->_HashArr[j]._ishave)
		{
			puts(ph->_HashArr[j]._name);
			i++;
		}
		j++;
	}
}
