#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
#include "tree.h"


//初始化
void BinaryTreeInit(BTNode* pt)
{
	pt->_left = pt->_right = NULL;
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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

// 二叉树销毁
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

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数
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

// 二叉树第k层节点个数
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

// 二叉树查找值为x的节点
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

// 二叉树前序遍历 
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

// 二叉树中序遍历
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

// 二叉树后序遍历
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

//二叉树的深度
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

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//建立一个队列
	Queue* qu = (Queue*)malloc(sizeof(Queue));
	QueueInit(qu);
	QueuePush(qu, root);


	while (!QueueEmpty(qu))
	{
		int i = 0;
		//获取当前层节点数
		int num = QueueSize(qu);
		for (i = 0; i < num; i++)
		{
			BTNode* node = QueueFront(qu);
			printf("%c ", node->_data);
			//左右子树不为空 入队列
			if (node->_left)
			{
				QueuePush(qu, node->_left);
			}

			if (node->_right)
			{
				QueuePush(qu, node->_right);
			}
			//队头元素出队列
			QueuePop(qu);
		}
		printf("\n");
	}
}

// 判断二叉树是否是完全二叉树
//返回值为 0 --> 不是完全二叉树
//返回值为 1 --> 是完全二叉树 
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}

	//建立一个队列
	Queue* qu = (Queue*)malloc(sizeof(Queue));
	QueueInit(qu);
	QueuePush(qu, root);


	while (!QueueEmpty(qu))
	{
		int i = 0;
		//获取当前层节点数
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
			//左右子树不为空 入队列
			QueuePush(qu, node->_left);

			QueuePush(qu, node->_right);
			//队头元素出队列
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
	printf("先序遍历 ：");
	BinaryTreePrevOrder(tree);
	printf("\n中序遍历 ：");
	BinaryTreeInOrder(tree);
	printf("\n后序遍历 ：");
	BinaryTreePostOrder(tree);
	printf("\n节点的数目 ：");
	printf("%d",BinaryTreeSize(tree));
	printf("\n叶子节点的数目 ：");
	printf("%d", BinaryTreeLeafSize(tree));
	printf("\n第 K 层节点的数目 ：");
	printf("%d", BinaryTreeLevelKSize(tree,3));

	printf("\n查找值为 x 的节点 :");
	BTNode* node = BinaryTreeFind(tree, 'B');
	if (node == NULL)
	{
		printf("未找到");
	}
	else
	{
		printf("%c", node->_data);
	}

	printf("\n完全二叉树判断 :");
	printf("%d", BinaryTreeComplete(tree));

	printf("\n层序遍历\n");
	BinaryTreeLevelOrder(tree);

	BinaryTreeDestory(&tree);
	return 0;
}