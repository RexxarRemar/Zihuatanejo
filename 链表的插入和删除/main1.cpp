//
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

 //头插法进行插入元素
void InsertBegin(node * head)
{
   
    node * n1 = (node *)malloc(sizeof(node));
    n1->data = 100;
    n1->next = head;
    head = n1;
}
//尾部插入法,传入的是最后一个元素
void InsertEnd(node * end)
{
    //尾部插入法，插入元素
    node * temp = (node *)malloc(sizeof(node));
    temp->data = 101;
    end->next = temp;
    temp->next = NULL;
}
//尾部删除元素
void  RemoveEnd(node *)
{
      //尾部删除
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
int main(int argc, const char * argv[]) {
    
    //初始化一个链表
    node * head=NULL;
    node *  p1 = (node *)malloc(sizeof(node));
    node * p2  = p1;
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
    
    //此时p1进行了第十一块空间的申请，所以需要进行空间的释放；p2仍然指向的是第十块空间！！！
    free(p1);
    p1 = NULL;
   
    InsertEnd(p2);
    InsertBegin(head);
    
    
   

    
//    //中间删除
//    while ((head->data!=5)&&(head->next!=NULL)) {
//        node * temp = head;
//        head = head->next;
//        if (head->data==5) {
//            temp->next= head->next;
//            free(head);
//            head = NULL;
//        }
//        
//    }
    
    //outPut
    Print(head);
    
    
    
    
    
    
    //最会进行删除整个链表，否则会内存泄露的
    node *p,*q;
    p=head;
    while (p->next!=NULL) {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    free(p);
    return 0;
}
