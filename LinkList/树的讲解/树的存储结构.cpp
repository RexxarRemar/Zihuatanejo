#include<iostream>
using namespace std;
#define MAX_TREE_SIZE 100
typedef  char  ElemType;
//���ӽڵ�
typedef struct  CTNode 
{
	int child;//���ӽڵ���±�
	struct  CTNode * next;//ָ����һ�����ӽڵ��ָ��
} *ChildPtr;
//��ͷ�ṹ
typedef struct 
{
	ElemType  data;  //������еĽڵ������
	int parent;//���˫�׽ڵ���±�
	ChildPtr firstchild;//ָ���һ�����ӵ�ָ��
} CTBox;
//���ṹ
typedef struct 
{
	CTBox nodes[MAX_TREE_SIZE];//�ڵ�����
};

int main()
{
	getchar();
	getchar();
	return 0;
}