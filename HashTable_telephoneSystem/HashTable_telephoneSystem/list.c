#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

//��ʼ������
void InitList(InfoNode_List* phead)
{
	assert(phead);

	phead->next = NULL;//ͷ������һ���ڵ�ΪNULL
}

//�ڵ������û���Ϣ
void ScanfNode(InfoNode* pnode)
{
	char name[MAX_N] = { '\0' }, telephone[MAX_T] = { '\0' }, address[MAX_A] = { '\0' };
	printf("�������û�����-->");
	gets(name);
	strcpy(pnode->_name, name);
	printf("�������û��绰����-->");
	gets(telephone);
	strcpy(pnode->_telephone, telephone);
	printf("�������û���ַ-->");
	gets(address);
	strcpy(pnode->_address, address);
}

//��������
void CreatList(InfoNode_List* phead)	//����ͷ�巨
{
	assert(phead);	//��ֹ����Ұָ��

	InfoNode_List* node;
	node = (InfoNode_List*)malloc(sizeof(InfoNode_List));	
	node->_ListInfo = (InfoNode*)malloc(sizeof(InfoNode));//Ϊ�û���Ϣ�ṹ�忪�ٿռ�
	ScanfNode(node->_ListInfo);//�����û���Ϣ

	node->next = phead->next;
	phead->next = node;
}

//ɾ���ڵ�
void DeleteListNode(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* pre = (InfoNode_List*)malloc(sizeof(InfoNode_List));
	char sure='\0';
	int option=0;
	//��ӡ�ڲ��˵�
	printf("-----------------------------------------\n");
	printf("|\t���û�����ɾ��-->1\t\t|\n");
	printf("-----------------------------------------\n");
	printf("|\t���û��绰������Ҳ�ɾ��-->0\t|\n");
	printf("-----------------------------------------\n");
	printf("����ѡ��-->");
	scanf("%d", &option);
	getchar();	//����scanf��������ֹͣʱ�Ļس��ַ�
	switch (option)
	{
		case 1:
		{
			  char name[MAX_N] = { '\0' };
			  printf("��������Ҫɾ����ϵ�˵�����-->");
			  gets(name);
			  pre = FindName(phead, name);	////����Ҫɾ���ڵ��ǰһ���ڵ�
			  break;
		}
		case 0:
		{
			char telephone[MAX_T] = { '\0' };
			printf("��������Ҫɾ���û��ĵ绰����-->");
			gets(telephone);
			pre = FindTelephone(phead, telephone);	//����Ҫɾ���ڵ��ǰһ���ڵ�
			break; 
		}
	}
	if (pre)//����ҵ��ýڵ㣬���ȷ��һ���Ƿ�ɾ��
	{
		printf("ȷ��ɾ����y/Y -->");
		scanf("%c", &sure);
		if (sure == 'y' || sure == 'Y')//ȷ��ɾ����������ɾ������
		{
			InfoNode_List* cur = pre->next;
			pre->next = cur->next;
			free(cur);//�ͷŵ�Ҫɾ���Ľڵ�ռ�
			printf("ɾ���ɹ�\n");
		}
		else
		{
			printf("ȡ��ɾ����������ҳ��\n");//����ɾ���򷵻���ҳ��
		}
	}
}

//�������ң�ɾ�������е��ã�
InfoNode_List* FindName(InfoNode_List* phead, char* name)
{
	assert(phead  && name);//��ֹ����Ұָ��

	InfoNode_List* node = phead;//����ͷ���λ��
	//Ѱ�Ҹ��û�
	//ѭ������������  ����ָ��curָ��NULL  ��  cur����һ���ڵ�ΪҪɾ���Ľڵ�
	while (node  &&  strcmp(node->next->_ListInfo->_name, name) != 0)
	{
		node = node->next;//�ƶ�ָ��
	}
	if (node)
	{
		//�ҵ�����д�ӡ
		printf("���û��Ѿ��ҵ�\n");
		printf("����\t\t�绰����\t\t��ַ\n");
		printf("%s\t\t%s\t\t%s\n", node->next->_ListInfo->_name, \
			                       node->next->_ListInfo->_telephone, \
								   node->next->_ListInfo->_address );
		return node;//����Ҫɾ���ڵ����һ���ڵ�
	}
	else
	{
		printf("û���ҵ����û�,��������ҳ��\n");
		return NULL;//����ΪNULL
	}
}

//��ӡ�����е��û���Ϣ
void ShowInfo(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* node = phead->next;
	if (!node)//��ֹ������û���û���Ϣ
	{
		printf("û���û���Ϣ���Դ�ӡ\n");
		return;
	}
	printf("\t����\t   �绰����\t   ��ַ\n");
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


//�绰������ң�ɾ�������е��ã�
InfoNode_List* FindTelephone(InfoNode_List* phead, char* telephone)
{
	assert(phead  && telephone);//��ֹ����Ұָ��

	InfoNode_List* node = phead;//����ͷ���λ��
	//Ѱ�Ҹ��û�
	//ѭ������������  ����ָ��curָ��NULL  ��  cur����һ���ڵ�ΪҪɾ���Ľڵ�
	while (node  &&  strcmp(node->next->_ListInfo->_telephone, telephone) != 0)
	{
		node = node->next;//�ƶ��ڵ�
	}
	if (node)	//����ҵ�����Ҫɾ���ڵ���д�ӡ
	{
		printf("���û��Ѿ��ҵ�\n");
		printf("����\t\t�绰����\t\t��ַ\n");
		printf("%s\t\t%s\t\t%s\n",	node->next->_ListInfo->_name, \
									node->next->_ListInfo->_telephone, \
									node->next->_ListInfo->_address);
		return node;//��������Ҫɾ���ڵ����һ���ڵ�
	}
	else
	{
		printf("û���ҵ����û�,��������ҳ��\n");
		return NULL;//û���ҵ��򷵻�NULL
	}
}

//���������Ϣд���ļ�
void WriteFileInfo(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* node = phead->next;
	if (!node)	//��ֹ������û���û���Ϣ
	{
		printf("û����Ҫ������û���Ϣ\n");
		return;
	}
	int num = 0;//��¼�û�����
	FILE* fp;//�ļ�ָ��
	fp = fopen("text.txt", "w");// ��д����ļ� 
	//�ļ�ָ����ɵĹ�����д���򿪵��ļ��� text.txt
	while (node)
	{
		fprintf(fp, "-%s\t\t%s\t\t%s\n", node->_ListInfo->_name, \
										node->_ListInfo->_telephone,\
										node->_ListInfo->_address);
		node = node->next;
		num++;
	}
	fprintf(fp, "|\t\t��%d���û���Ϣ\t\t|\n",num);
	fclose(fp);//�ر��ļ�
	printf("��Ϣд��ɹ�\n");
}

//��ȡ�ļ��е���Ϣ
void ReadFileInfo(InfoNode_List* phead)
{
	assert(phead);

	FILE* fp;//�����ļ�ָ��
	char flag='\0';//�ж��ļ���ȡ�����ı�־
	fp = fopen("text.txt", "r");//���ļ�
	while ((flag = fgetc(fp)) != '|')
	{
		//����һ���ڵ����洢�ļ��е��û���Ϣ
		InfoNode_List* node;
		node = (InfoNode_List*)malloc(sizeof(InfoNode_List));
		node->_ListInfo = (InfoNode*)malloc(sizeof(InfoNode));//Ϊ�û���Ϣ�ṹ�忪�ٿռ�
		fscanf(fp, "%s%s%s", node->_ListInfo->_name, \
							node->_ListInfo->_telephone, \
							node->_ListInfo->_address);
		flag = fgetc(fp);//�������ǰ��ĩ�Ļ��з�
		//�ڵ����(ͷ�巨)
		node->next = phead->next;
		phead->next = node;
	}
	fclose(fp);//�ر��ļ�
	printf("�û��绰������Ϣ�������\n");
}




