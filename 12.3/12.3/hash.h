#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>

#define MAX_NAME 30  //�����������󳤶�
#define DIV (19)    //����������������

typedef struct NameNode
{
	char _name[MAX_NAME];  
	int _key;		//������������ֵ
	int _ishave;	//�жϸ�λ���Ƿ���ֵ
}NameNode;

typedef struct HashTable
{
	NameNode* _HashArr;	//��Ź�ϣ��Ԫ�ص�����
	int _size;		//��ϣ����Ԫ�ص�����
	int _capacity;	//��ϣ��ǰ������
}HashTable;

//��ʼ����ϣ��
void InitHash(HashTable* ph);
//����
void AddCapacity(HashTable* ph,int key);
//����Ԫ�ز�������ϣ��
void ScanfHash(HashTable* ph);
void SetHash(HashTable* ph, char* name);
//չʾ��ϣ��
void ShowHash(HashTable* ph);


