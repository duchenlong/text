#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
#include "tree.h"


//��ʼ��
void BinaryTreeInit(BTNode* pt)
{
	pt->_left = pt->_right = NULL;
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (n <= *pi || a[*pi] == '#')
	{
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	BinaryTreeInit(root);
	root->_data = a[*pi];

	(*pi)++;
	root->_left = BinaryTreeCreate(a, n,pi);
	(*pi)++;
	root->_right = BinaryTreeCreate(a, n,pi);
	return root;
}

// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}

	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (!root->_left && !root->_right)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL )
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->_data == x)
	{
		return root;
	}
	BTNode* node;
	node = BinaryTreeFind(root->_left, x);
	if (node != NULL)
	{
		return node;
	}
	node = BinaryTreeFind(root->_right, x);
	return node;
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

//�����������
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int lDepth = BinaryTreeDepth(root->_left) + 1;
	int rDepth = BinaryTreeDepth(root->_right) + 1;

	return lDepth > rDepth ? lDepth : rDepth;
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//����һ������
	Queue* qu = (Queue*)malloc(sizeof(Queue));
	QueueInit(qu);
	QueuePush(qu, root);


	while (!QueueEmpty(qu))
	{
		int i = 0;
		//��ȡ��ǰ��ڵ���
		int num = QueueSize(qu);
		for (i = 0; i < num; i++)
		{
			BTNode* node = QueueFront(qu);
			printf("%c ", node->_data);
			//����������Ϊ�� �����
			if (node->_left)
			{
				QueuePush(qu, node->_left);
			}

			if (node->_right)
			{
				QueuePush(qu, node->_right);
			}
			//��ͷԪ�س�����
			QueuePop(qu);
		}
		printf("\n");
	}
}

// �ж϶������Ƿ�����ȫ������
//����ֵΪ 0 --> ������ȫ������
//����ֵΪ 1 --> ����ȫ������ 
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}

	//����һ������
	Queue* qu = (Queue*)malloc(sizeof(Queue));
	QueueInit(qu);
	QueuePush(qu, root);


	while (!QueueEmpty(qu))
	{
		int i = 0;
		//��ȡ��ǰ��ڵ���
		int num = QueueSize(qu);
		for (i = 0; i < num; i++)
		{
			BTNode* node = QueueFront(qu);
			if (node == NULL)
			{
				int j = 0;
				int count = QueueSize(qu);
				for (j = 0; j < count; j++)
				{
					BTNode* cur = QueueFront(qu);
					if (cur)
					{
						return 0;
					}
					QueuePop(qu);
				}
				return 1;
			}
			//����������Ϊ�� �����
			QueuePush(qu, node->_left);

			QueuePush(qu, node->_right);
			//��ͷԪ�س�����
			QueuePop(qu);
		}
	}
	return 1;
}

//int BinaryTreeComplete(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 1;
//	}
//	int flag = 1;
//	int lDepth = BinaryTreeDepth(root->_left);
//	int rDepth = BinaryTreeDepth(root->_right);
//	if (lDepth - rDepth == 0 || lDepth - rDepth == 1)
//	{
//		flag = BinaryTreeComplete(root->_left);
//		if (flag)
//		{
//			flag = BinaryTreeComplete(root->_right);
//		}
//	}
//	else
//	{
//		flag = 0;
//	}
//
//	return flag;
//}



int main()
{
	BTDataType* a = "A#B";
	BTNode* tree = (BTNode*)malloc(sizeof(BTNode));
	BinaryTreeInit(tree);
	int n = 0;
	tree = BinaryTreeCreate(a, strlen(a), &n);
	printf("������� ��");
	BinaryTreePrevOrder(tree);
	printf("\n������� ��");
	BinaryTreeInOrder(tree);
	printf("\n������� ��");
	BinaryTreePostOrder(tree);
	printf("\n�ڵ����Ŀ ��");
	printf("%d",BinaryTreeSize(tree));
	printf("\nҶ�ӽڵ����Ŀ ��");
	printf("%d", BinaryTreeLeafSize(tree));
	printf("\n�� K ��ڵ����Ŀ ��");
	printf("%d", BinaryTreeLevelKSize(tree,3));

	printf("\n����ֵΪ x �Ľڵ� :");
	BTNode* node = BinaryTreeFind(tree, 'B');
	if (node == NULL)
	{
		printf("δ�ҵ�");
	}
	else
	{
		printf("%c", node->_data);
	}

	printf("\n��ȫ�������ж� :");
	printf("%d", BinaryTreeComplete(tree));

	printf("\n�������\n");
	BinaryTreeLevelOrder(tree);

	BinaryTreeDestory(&tree);
	return 0;
}