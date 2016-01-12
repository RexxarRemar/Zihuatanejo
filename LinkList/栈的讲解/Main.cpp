#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 20
#define STACKINCREASE 10
using namespace std;
//使用的C语言的方法
typedef char ElemType;
typedef struct 
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;
//初始化一个栈
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
//压栈操作
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
//出栈操作
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

	printf("请输入二进制数，输入#符号表示结束！\n"); 
    scanf("%c",&c);
	while (c !='#')
	{
		Push(&s,c);
		scanf("%c",&c);
	}//  '\n'  ascii码 10
	getchar();//把回车‘\n’  从缓冲区去掉
	len = StackLen(s);

	cout<<"当前栈的容量是："<<len<<endl;
	//二进制转换为十进制
	for (int i = 0; i < len; i++)
	{
		Pop(&s,&c);
		sum = sum+(c-48)*pow(2,i);
	}
	//二进制转为八进制
	
	cout<<"转化的十进制数是："<<sum<<endl;
	




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