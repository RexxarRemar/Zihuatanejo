
#include<stdio.h>
#include<stdlib.h>
//基于c语言 实现二叉树的建立和遍历'
typedef char ElemType;
//定义每个节点，左右child
typedef struct BiTNode
{
	char data;
	struct    BiTNode  *lchild,*rchild; 
} BiTNode ,*BiTree;
//输入时需要注意
//创建一个二叉树,
//创建二叉树的时候是从祖先节点开始进行
//使用的是前序遍历的顺序进行赋值输入的，叶子节点默认都是空格，输入的时候需要注意
//使用前序遍历，使用空格表示节点是空
void CreateBiTree(BiTree *T)//T是一个二维指针
{
	//小的技巧，需要使用c的输入格式，否则会出现问题
	char c;
	scanf("%c",&c);
	//没有子树的时候使用空格表示
	if (' ' == c)
	{
		*T = NULL;
	}
	else
	{
		//
	*T = (BiTNode *)malloc(sizeof(BiTNode));
   (*T)->data = c;
   CreateBiTree(&(*T)->lchild);
   CreateBiTree(&(*T)->rchild); 

	}
}
//访问二叉树节点的具体操作，
void visit(char data,int level)
{
	printf("%c是第%d层\n",data,level);
}

//前序遍历二叉树
void PreaOrcderTraverse(BiTree T,int level)
{
	if (T)
	{
		visit(T->data,level);
		//此处是递归调用，level是一直保存着值
		PreaOrcderTraverse(T->lchild,level+1);
		PreaOrcderTraverse(T->rchild,level+1);
	}
}
//中序遍历二叉树
void MidorderTraverse(BiTree T, int level)
{
	if (T)
	{
		MidorderTraverse(T->lchild,level+1);
		visit(T->data,level);
		MidorderTraverse(T->rchild,level+1);
	}
}

//后序遍历
void AftOrderTraverse(BiTree T,int level)
{
	if (T)
	{
		MidorderTraverse(T->lchild,level+1);
		MidorderTraverse(T->rchild,level+1);
		visit(T->data,level);
	}

}
 int main()
{
	int level = 1;
	BiTree T = NULL;
	CreateBiTree(&T);

	printf("\n前序遍历：\n");
	PreaOrcderTraverse(T,level);

	printf("\n中序遍历：\n");
	MidorderTraverse(T,level);

	printf("\n后序遍历：\n");
	AftOrderTraverse(T,level);

	system("pause");
	return 0;
}