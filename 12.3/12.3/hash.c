#define _CRT_SECURE_NO_WARNINGS 1

#include"hash.h"

//��ʼ����ϣ��
void InitHash(HashTable* ph)
{
	assert(ph);
	ph->_size=0;
	ph->_capacity = DIV;	//��ʼ����Ϊ����������������
	ph->_HashArr = (NameNode*)malloc(ph->_capacity*sizeof(NameNode));
	int i = 0;
	//�ڲ���ʼ����ϣ��
	for (i = 0; i < ph->_capacity; i++)
	{
		//���ڲ�����Ϣ ��Ϊû��ֵ
		ph->_HashArr[i]._ishave = 0;
	}
}
//����Ԫ�ز�������ϣ��
void ScanfHash(HashTable* ph)
{
	int num,i;
	char name[MAX_NAME] = { '\0' };
	printf("����ͬѧ��Ϣ�ĸ�����-->");
	scanf("%d", &num);
	getchar();//���scanf����ʹ�ö��Ļس��ַ�
	for (i = 0; i < num; i++)
	{
		gets(name);
		SetHash(ph, name); //�洢
	}
}
//����
void AddCapacity(HashTable* ph, int key)
{
	ph->_capacity *= 2;//��������һ��
	ph->_HashArr = realloc(ph->_HashArr,sizeof(NameNode)*ph->_capacity);
	int i = 0;
	//��ʼ�����Ӻ󲿷ֵĴ洢��Ԫ
	for (i = ph->_size; i < ph->_capacity; i++)
	{
		ph->_HashArr[i]._ishave = 0;
	}
	//���Ĵ洢λ��֮ǰ��Ԫ���ƶ������ݵĵط�
	for (i = 0; i < key; i++)
	{
		ph->_HashArr[i + ph->_size] = ph->_HashArr[i];
		ph->_HashArr[i]._ishave = 0;//�ƶ�֮�󣬽���λ��Ū��û��ֵ�����
	}
}

void SetHash(HashTable* ph, char* name)
{
	char Fsex, Fname;  //Fsex ->�յ�����ĸ  Fname ->��������ĸ
	int i = 0,key;
	while (name[i] != ' ')  //�ҵ���������ĸ
	{
		i++;
	}
	Fsex = name[0];
	Fname = name[i + 1];
	key = (int)(Fsex + Fname)%DIV;	//key ��ϣ��Ĵ洢λ��
	if (ph->_size == ph->_capacity)//�����ϣ����������������
	{
		AddCapacity(ph, key);
	}
	if (!ph->_HashArr[key]._ishave)	//��λ��ûֵʱֱ�ӽ��и�ֵ
	{
		strcpy(ph->_HashArr[key]._name, name);//�ַ����ĸ�����strcpy����
		ph->_HashArr[key]._key = key;
		ph->_HashArr[key]._ishave = 1;
	}
	else
	{
		i = key+1;
		//��������̽����ɢ�еķ�ʽ�����ͻ
		while (i != key) 
		{
			if (!ph->_HashArr[i]._ishave)
			{
				strcpy(ph->_HashArr[i]._name, name);
				ph->_HashArr[i]._key = key;
				ph->_HashArr[i]._ishave = 1;
				break;
			}
			i = (i + 1) % ph->_capacity;	//�ù�ϣ���߼�������Ȧ
		} 
	}
	ph->_size++;// ����Ԫ������
}
//չʾ��ϣ��
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
