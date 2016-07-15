
#include<stdio.h>
#include<stdlib.h>
//����c���� ʵ�ֶ������Ľ����ͱ���'
typedef char ElemType;
//����ÿ���ڵ㣬����child
typedef struct BiTNode
{
	char data;
	struct    BiTNode  *lchild,*rchild; 
} BiTNode ,*BiTree;
//����ʱ��Ҫע��
//����һ��������,
//������������ʱ���Ǵ����Ƚڵ㿪ʼ����
//ʹ�õ���ǰ�������˳����и�ֵ����ģ�Ҷ�ӽڵ�Ĭ�϶��ǿո������ʱ����Ҫע��
//ʹ��ǰ�������ʹ�ÿո��ʾ�ڵ��ǿ�
void CreateBiTree(BiTree *T)//T��һ����άָ��
{
	//С�ļ��ɣ���Ҫʹ��c�������ʽ��������������
	char c;
	scanf("%c",&c);
	//û��������ʱ��ʹ�ÿո��ʾ
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
//���ʶ������ڵ�ľ��������
void visit(char data,int level)
{
	printf("%c�ǵ�%d��\n",data,level);
}

//ǰ�����������
void PreaOrcderTraverse(BiTree T,int level)
{
	if (T)
	{
		visit(T->data,level);
		//�˴��ǵݹ���ã�level��һֱ������ֵ
		PreaOrcderTraverse(T->lchild,level+1);
		PreaOrcderTraverse(T->rchild,level+1);
	}
}
//�������������
void MidorderTraverse(BiTree T, int level)
{
	if (T)
	{
		MidorderTraverse(T->lchild,level+1);
		visit(T->data,level);
		MidorderTraverse(T->rchild,level+1);
	}
}

//�������
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

	printf("\nǰ�������\n");
	PreaOrcderTraverse(T,level);

	printf("\n���������\n");
	MidorderTraverse(T,level);

	printf("\n���������\n");
	AftOrderTraverse(T,level);

	system("pause");
	return 0;
}