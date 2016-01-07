//http://blog.csdn.net/pf4919501/article/details/38818335
//  main.cpp
//  链表的插入和删除
//
//  Created by student on 16/1/6.
//  Copyright (c) 2016年 student. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;
struct node {
    int data;
    node * next;
};
//输出
void Print(node * head)
{
    //输出
    node * temp1=head;
    while (head!=NULL) {
        
        cout<<"data="<<head->data<<endl;
        head = head->next;
    }//此处需要重新把链表的头指针重新指向第一个节点
    head = temp1;

}

 //进行插入元素
void InsertBegin(node * head,int n,int number)
{
   cout<<"插入头结点"<<endl;
    node * n1 = (node *)malloc(sizeof(node));
    n1->data = number;
	
	int j = 1;
	while (head!=nullptr)
	{
		  j++;
		  node * temp = head;     
		  head = head->next;
		  if (j==n)
		  {
			  //在2 、3中间插入一个节点
			    temp->next = n1;
				n1->next = head;

		  }
	}
}
//尾部插入法,传入的是最后一个元素
void InsertEnd(node * end)
{

    //尾部插入法，插入元素
    node * temp = (node *)malloc(sizeof(node));
    temp->data = 10110101;
    end->next = temp;
    temp->next = NULL;
}
//尾部删除元素
void  RemoveEnd(node * head )
{
      //尾部删除
	//如果不是在函数中调用，而是在主函数中进行使用，需要把头指针重新指向第一个头结点
        node * temp=head;
        while (1) {
    
            if (head->data == 9) {
                head->next = NULL;
                break;
            }
            //这句代码放在if之后前和之后是有差别的
            head = head->next;
        }//头指针重新指向第一个节点
		
    head = temp;
}
//中间进行删除
void RemoveEle(node * head)
{
	    //中间删除 5这个元素
 while (1) {
        node * temp = head;
        head = head->next;
       if (head->data==5) {
            temp->next= head->next;
           free(head);
           head = NULL;
		   break;
       }
       
    }
}
//删除整个链表
void RemoveAll(node * head)
{
	 //最会进行删除整个链表，否则会内存泄露的
	cout<<"删除整个链表"<<endl;
    node *p,*q;
    p=head;
    while (p->next!=NULL) {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    free(p);
}


int main(int argc, const char * argv[]) {
    
    //初始化一个链表，可以封装为程一个函数
    node * head=NULL;
    node *  p1 = (node *)malloc(sizeof(node));
    node * p2  = p1;
	node * tempEnd;
    for (int i = 0; i<10; i++) {
        
        if (head ==NULL) {
            head = p1;
        }
        else
        {
            p2->next = p1;
        }
        p2  = p1;
        p1->data = i;
        p1 = (node *)malloc(sizeof(node));
		
        
    }
  // p2->next =NULL;
	
	//在尾部进行插入
  // InsertEnd(p2);
	node * end = (node * )malloc(sizeof(node));
	end ->data = 10101010;
	end->next = NULL;
	p2->next = end;
	end->next=nullptr;
	 //此时p1进行了第十一块空间的申请，所以需要进行空间的释放；p2仍然指向的是第十块空间！！！
    free(p1);    
    p1 = NULL;

 //在头部进行插入  ok
   node * n1 = (node *)malloc(sizeof(node));
    n1->data = 11111;
	n1->next = head;
	head = n1;
	//在中间进行插入  ok
  InsertBegin(head,5,1000);
  //尾部的删除
  //  RemoveEnd(head);
	//中间进行删除  和中间插入类似
  RemoveEle(head);

    //outPut
    Print(head);
    //删除整个链表，防止内存泄露  ok
    RemoveAll(head);
	getchar();
	getchar();
    return 0;
}
