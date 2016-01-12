#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 20
#define STACKINCREASE 10
using namespace std;
//ʹ�õ�C���Եķ���
typedef char ElemType;
typedef struct 
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;
//��ʼ��һ��ջ
void InitStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if (!s->base)
	{
		exit(0);
	}
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}
//ѹջ����
void  Push(sqStack *s,ElemType e)
{
	if (s->top-s->base>=s->stackSize)
	{
		s->base = (ElemType *)realloc(s->base,(s->stackSize+STACKINCREASE)*sizeof(ElemType));
		if (!s->base)
		{
			exit(0);
		}
	}
	*(s->top) = e;
	s->top ++;
}
//��ջ����
void Pop(sqStack *s,ElemType * e)
{
	if (s->top == s->base)
	{
		return ;
	}
	*e = *--(s->top);
}
int StackLen(sqStack s)
{
	return (s.top-s.base);
}

int main()
{
	ElemType c;
	sqStack s;
	int len,sum=0;
	InitStack(&s);

	printf("�������������������#���ű�ʾ������\n"); 
    scanf("%c",&c);
	while (c !='#')
	{
		Push(&s,c);
		scanf("%c",&c);
	}//  '\n'  ascii�� 10
	getchar();//�ѻس���\n��  �ӻ�����ȥ��
	len = StackLen(s);

	cout<<"��ǰջ�������ǣ�"<<len<<endl;
	//������ת��Ϊʮ����
	for (int i = 0; i < len; i++)
	{
		Pop(&s,&c);
		sum = sum+(c-48)*pow(2,i);
	}
	//������תΪ�˽���
	
	cout<<"ת����ʮ�������ǣ�"<<sum<<endl;
	




	/*
	char a[]  = {'a','d','l'};
	cout<<&a[0]<<endl;
	cout<<&a[1]<<endl;
	cout<<&a[2]-&a[0]<<endl;
	*/
	getchar();
	getchar();
	return 0;
}