#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

//˯�߼�����
void SleepCls()
{
	Sleep(500);//������������ͣ0.5��
	system("cls");//��������
}

//��ʼ������
void InitList(InfoNode_List* phead)
{
	assert(phead);

	phead->_next = phead;	//ͷ������һ���ڵ�ָ���Լ�
	phead->_pre = phead;	//ͷ������һ���ڵ�ָ���Լ�
}

//�ڵ������û���Ϣ
void ScanfNode(InfoNode* pnode)
{
	char name[MAX_N] = { '\0' }, telephone[MAX_T] = { '\0' }, address[MAX_A] = { '\0' };
	printf("_______________________________________\n");
	printf("|\n");
	printf("|�������û�����-->");
	scanf("%s", name);
	strcpy(pnode->_name, name);
	printf("|�������û��绰����-->");
	scanf("%s",telephone);
	strcpy(pnode->_telephone, telephone);
	printf("|�������û���ַ-->");
	scanf("%s",address);
	strcpy(pnode->_address, address);
	printf("|______________________________________\n");
}

//�޸��û���Ϣ
void ChangeNode(InfoNode* pnode)
{
	char choose_C;
	char name[MAX_N] = { '\0' }, telephone[MAX_T] = { '\0' }, address[MAX_A] = { '\0' };
	printf("_______________________________________\n");
	printf("|\n");
	printf("|�������޸ĺ��û�����-->");
	scanf("%s", name);
	strcpy(pnode->_name, name);
	printf("|�������޸ĺ��û��绰����-->");
	scanf("%s", telephone);
	strcpy(pnode->_telephone, telephone);
	printf("|�Ƿ��޸��û��ĵ�ַ(Y����y)-->");
	getchar();			//���յ绰���������Ļس��ַ�
	scanf("%c", &choose_C);
	if (choose_C == 'y' || choose_C == 'Y')
	{
		printf("|�������û���ַ-->");
		scanf("%s", address);
		strcpy(pnode->_address, address);
	}
	else
	{
		printf("|�û���ַ  -->%s\n", pnode->_address);
	}
	printf("|______________________________________\n");
}

//�����û���Ϣ
void AddList(InfoNode_List* phead)		//����ͷ�巨
{
	assert(phead);						//��ֹ����Ұָ��

	InfoNode_List* node;
	node = (InfoNode_List*)malloc(sizeof(InfoNode_List));	
	node->_ListInfo = (InfoNode*)malloc(sizeof(InfoNode));	//Ϊ�û���Ϣ�ṹ�忪�ٿռ�
	ScanfNode(node->_ListInfo);			//�����û���Ϣ

	//ͷ�巨���нڵ�Ĳ���
	node->_next = phead->_next;
	phead->_next->_pre = node;

	node->_pre = phead;
	phead->_next = node;

	printf("----------------------------------\n");
	printf("%s����Ϣ�������\n\n", node->_ListInfo->_name);
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
	printf("|\t���û�����ɾ��(ϵͳĬ��)-->1\t|\n");
	printf("-----------------------------------------\n");
	printf("|\t���û��绰������Ҳ�ɾ��-->0\t|\n");
	printf("-----------------------------------------\n");
	printf("����ѡ��-->");
	scanf("%d", &option);
	if (option != 0)	//Ĭ�ϰ���������ѯɾ��
	{
		option = 1;
	}
	getchar();			//����scanf��������ֹͣʱ�Ļس��ַ�
	switch (option)
	{
		case 1:
		{
			  char name[MAX_N] = { '\0' };
			  printf("��������Ҫɾ����ϵ�˵�����-->");
			  gets(name);
			  pre = FindName(phead, name);			//����Ҫɾ���ڵ�
			  break;
		}
		case 0:
		{
			char telephone[MAX_T] = { '\0' };
			printf("��������Ҫɾ���û��ĵ绰����-->");
			gets(telephone);
			pre = FindTelephone(phead, telephone);	//����Ҫɾ���ڵ�
			break; 
		}
	}
	if (pre)			//����ҵ��ýڵ㣬���ȷ��һ���Ƿ�ɾ��
	{
		printf("ȷ��ɾ����y/Y -->");
		scanf("%c", &sure);
		if (sure == 'y' || sure == 'Y')			//ȷ��ɾ����������ɾ������
		{
			InfoNode_List* cur = pre;
			cur->_pre->_next = cur->_next;
			cur->_next->_pre = cur->_pre;
			free(cur);							//�ͷŵ�Ҫɾ���Ľڵ�ռ�
			printf("ɾ���ɹ�\n");
		}
		else
		{
			printf("ȡ��ɾ����������ҳ��\n");	//����ɾ���򷵻���ҳ��
		}
	}
}

//�������ң�ɾ�������е��ã�
InfoNode_List* FindName(InfoNode_List* phead, char* name)
{
	assert(phead  && name);				//��ֹ����Ұָ��

	InfoNode_List* node = phead->_next;	//����ͷ���λ��

	//Ѱ�Ҹ��û�
	//ѭ������������  ����ָ��nodeָ��ͷ���  ��  node�ڵ�ΪҪɾ���Ľڵ�
	while (node!=phead  &&  strcmp(node->_ListInfo->_name, name) != 0)
	{
		node = node->_next;				//�ƶ�ָ��
	}
	if (node!=phead)
	{
		//�ҵ�����д�ӡ
		printf("���û��Ѿ��ҵ�\n");
		ShowOnce(node->_ListInfo);
		return node;		//����Ҫɾ���ڵ�
	}
	else
	{
		printf("û���ҵ����û�,��������ҳ��\n");
		return NULL;		//����ΪNULL
	}
}

//��ӡ�����е��û���Ϣ
void ShowInfo(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* node = phead->_next;
	if (node==phead)			//��ֹ������û���û���Ϣ
	{
		printf("û���û���Ϣ���Դ�ӡ\n");
		return;
	}
	printf("_________________________________________________________\n");
	printf("\t����\t   �绰����\t   ��ַ\n");
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

//��ӡһ���ڵ����Ϣ
void ShowOnce(InfoNode* pi)
{
	assert(pi);

	printf(" _________________________________________________\n");
	printf("|\n");
	printf("|������	   %s\n", pi->_name);
	printf("|�绰���룺%s\n", pi->_telephone);
	printf("|��ַ��    %s\n", pi->_address);
	printf("|_________________________________________________\n");
}


//�绰������ң�ɾ�������е��ã�
InfoNode_List* FindTelephone(InfoNode_List* phead, char* telephone)
{
	assert(phead  && telephone);		//��ֹ����Ұָ��

	InfoNode_List* node = phead->_next;	//����ͷ���λ��

	//Ѱ�Ҹ��û�
	//ѭ������������  ����ָ��nodeָ��phead  ��  nodeΪҪɾ���Ľڵ�
	while (node!=phead  &&  strcmp(node->_ListInfo->_telephone, telephone) != 0)
	{
		node = node->_next;				//�ƶ��ڵ�
	}
	if (node!=phead)					//����ҵ�����Ҫɾ���ڵ���д�ӡ
	{
		printf("���û��Ѿ��ҵ�\n");
		ShowOnce(node->_ListInfo);
		return node;					//��������Ҫɾ���ڵ�
	}
	else
	{
		printf("û���ҵ����û�,��������ҳ��\n");
		return NULL;					//û���ҵ��򷵻�NULL
	}
}

//���ַ�ASCLL�Ƚ������û���Ϣ�Ĵ�С
int CompareInfo(InfoNode* pi1, InfoNode* pi2)
{
	assert(pi1 && pi2);

	int ans=0;				//��¼�ȽϺ�Ľ��
	/*ans = strcmp(pi1->_name, pi2->_name);		//�Ȱ��������Ƚ�
	if (ans == 0)			//���Ϊ0����ʾ�������  �ٱȽϵ绰����
	{
		//�绰���벻������ȣ����رȽϺ�Ľ��
		ans = strcmp(pi1->_telephone, pi2->_telephone);
	}
	return ans;*/

	return (ans = strcmp(pi1->_name, pi2->_name)) != 0 ? \
					ans : strcmp(pi1->_telephone, pi2->_telephone);
}

//����   --> ѭ��˫����Ĳ�������
void InsertSort(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* cur = phead->_next;	//cur ָ���¼��ǰ���ȽϵĽڵ�
	InfoNode_List* node = cur->_next;   //node ָ���¼��Ҫ�ȽϵĽڵ�
	InfoNode_List* nodenext;            //nodenext ָ���¼��һ����Ҫ�ȽϵĽڵ�
	
	while (node!=phead)					//ѭ���˳�������  node�ڵ㲻��ͷ���
	{
		cur = phead->_next;				//ÿ�αȽ϶���ͷ������һ���ڵ㿪ʼ

		//�ҵ���һ����node�ڵ���Ϣ��Ľڵ㣬����ڵ��¼Ϊcur
		while (cur != node && \
			CompareInfo(cur->_ListInfo, node->_ListInfo) <= 0)
		{
			cur = cur->_next;
		}

		nodenext = node->_next;			//������Ҫ�ȽϽڵ����һ���ڵ�
		//���cur==node  ��ʾ�ýڵ����ǰ��ڵ������ģ�������������ѭ��
		if (cur != node)
		{
			//������node�ڵ��ǰ�������ڵ�
			nodenext->_pre = node->_pre;  
			node->_pre->_next = nodenext;

			//������node�ڵ��cur�ڵ��ǰһ���ڵ�
			cur->_pre->_next = node;
			node->_pre = cur->_pre;

			//����node�ڵ��cur���ӣ������cur�ڵ��ǰ�����
			node->_next = cur;
			cur->_pre = node;
		}

		//����һ����Ҫ�ȽϵĽڵ��node
		node = nodenext;
		nodenext = node->_next;
	}
	
	char choose_s='\0';
	my_loading(3);
	printf("������Ϣ�����������\n");
	printf("�Ƿ���ʾ����������(y��Y)-->");
	
	scanf("%c", &choose_s);
	if (choose_s == 'y' || choose_s == 'Y')
	{
		SleepCls();			//˯�߼�����
		ShowInfo(phead);	//��ӡ��Ϣ
	}
}

//ģ����ؽ���
void my_loading(const int time)
{
	int i = 0;
	for (i = 1; i < time; i++)
	{
		printf("\t%d......\n",i);
		Sleep(500);
	}
}

//���������Ϣд���ļ�
void WriteFileInfo(InfoNode_List* phead)
{
	assert(phead);

	InfoNode_List* node = phead->_next;
	if (node==phead)				//��ֹ������û���û���Ϣ
	{
		printf("û����Ҫ������û���Ϣ\n");
		return;
	}
	int num = 0;					//��¼�û�����
	FILE* fp;						//�ļ�ָ��
	fp = fopen("text.txt", "w");	// ��д����ļ� 
	//�ļ�ָ����ɵĹ�����д���򿪵��ļ��� text.txt

	while (node!=phead)
	{
		fprintf(fp, "-%s\t\t%s\t\t%s\n", node->_ListInfo->_name, \
										node->_ListInfo->_telephone,\
										node->_ListInfo->_address);
		node = node->_next;
		num++;			//��¼�����û�������
	}
	fprintf(fp, "|\t\t��%d���û���Ϣ\t\t|\n",num);
	fclose(fp);			//�ر��ļ�
	my_loading(4);		//ģ����ؽ���
	printf("�û���Ϣ�ѱ���\n");
}

//��ȡ�ļ��е���Ϣ
void ReadFileInfo(InfoNode_List* phead)
{
	assert(phead);

	FILE* fp;			//�����ļ�ָ��
	char flag='\0';		//�ж��ļ���ȡ�����ı�־
	fp = fopen("text.txt", "r");	//���ļ�
	while ((flag = fgetc(fp)) != '|')
	{
		//����һ���ڵ����洢�ļ��е��û���Ϣ
		InfoNode_List* node;
		node = (InfoNode_List*)malloc(sizeof(InfoNode_List));
		//Ϊ�û���Ϣ�ṹ�忪�ٿռ�
		node->_ListInfo = (InfoNode*)malloc(sizeof(InfoNode));
		fscanf(fp, "%s%s%s", node->_ListInfo->_name, \
							node->_ListInfo->_telephone, \
							node->_ListInfo->_address);
		flag = fgetc(fp);	//�������ǰ��ĩ�Ļ��з�

		//�ڵ����(β�巨)
		//�Ȱ�node�ڵ�������β������
		node->_pre = phead->_pre->_next;
		phead->_pre->_next = node;

		//�ٰ�node�ڵ�������ͷ��������
		node->_next = phead;
		phead->_pre = node;
	}
	fclose(fp);				//�ر��ļ�
	my_loading(4);			//ģ����ؽ���
	printf("�û��绰������Ϣ�������\n");
}




