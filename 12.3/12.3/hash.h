#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>

#define MAX_NAME 30  //姓名数组的最大长度
#define DIV (19)    //除留余数法的余数

typedef struct NameNode
{
	char _name[MAX_NAME];  
	int _key;		//除留余数法的值
	int _ishave;	//判断该位置是否有值
}NameNode;

typedef struct HashTable
{
	NameNode* _HashArr;	//存放哈希表元素的数组
	int _size;		//哈希表中元素的数量
	int _capacity;	//哈希表当前的容量
}HashTable;

//初始化哈希表
void InitHash(HashTable* ph);
//扩容
void AddCapacity(HashTable* ph,int key);
//输入元素并建立哈希表
void ScanfHash(HashTable* ph);
void SetHash(HashTable* ph, char* name);
//展示哈希表
void ShowHash(HashTable* ph);


