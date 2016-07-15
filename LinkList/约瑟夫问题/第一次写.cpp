//
//  main.cpp
//  约瑟夫问题
//
//  Created by student on 16/1/8.
//  Copyright (c) 2016年 student. All rights reserved.
//
/*
    约瑟夫问题：
     41个人围城一个环，从第一个人开始，编号是3的倍数的被pass掉，直到这个环只剩下两个人。
    
 使用的是单循环链表进行模拟约瑟夫问题。
 
 */
#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    node * next;
    
}Node ;
/*
    在这个单循环链表中头结点没有在环中，是在循环之外，头结点的指针域的指针是指向第一个结点（或者说是循环中的任意一个节点）
 */
int main(int argc, const char * argv[]) {
    //创建一个循环链表
    //此处需要定义一个  头结点
    node * HeadNode = (node *)malloc(sizeof(node));
    //此处的head不是头指针，而是指向第一个节点的指针,在这个地方可以使用头结点代替
    Node * head = NULL;
    node *p1 = (node * )malloc(sizeof(node));
    node *p2 = p1;
    HeadNode->next = p1;
    int total = 0;
    for (int i = 1; i <42; i++) {
        if (head == NULL) {
            //指向头结点，而不是第一个结点
            head = p1;
        }
        else
        {
            p2->next = p1;
        }
        p2 = p1;
        p1->data  = i;
        p1 = (node *)malloc(sizeof(node));
        total ++;
        
    }
    //将p2的指针域的指针指向第一个节点，不让头结点参与到循环中,形成一个单循环链表
    cout<<"total = "<<total<<endl;
    p2->next = head;
   // cout<<"p2->data="<<p2->data<<endl;
    free(p1);
    p1 = NULL;
    
    //输出链表
    //临时指针是指向第一个节点的
    cout<<"模拟约瑟夫问题之前："<<endl;
    node  *temp = head;
    while (temp->next!=head){
        cout<<" "<<temp->data<<"  ";
         temp = temp->next;
        if (temp->next==head) {
            cout<<" "<<temp->data<<"  ";
        }
        
    }
   // cout<<"*****"<<temp->data<<endl;//41
  
    //模拟约瑟夫问题,就是通过链表实现链表的中间元素的删除
    cout<<"实现模拟约瑟夫问题："<<endl;
    //默认是从1开始进行报数
    int num =1;
//    while (num<) {
//
//    }
    node  *tempHead = head;
    while (total>0){
        node * tempnode = head;
        for (int i =1; i<3; i++) {
            tempnode = head;
            head= head->next;
        }//此时，head是第三个节点,Head是第四个节点
        head = head->next;
        tempnode->next = head->next;
       
        
       
    }
    
    head = tempHead;
    while (head->next!=head){
        cout<<" "<<head->data<<"  ";
        head = head->next;
        if (head->next==head) {
            cout<<" "<<head->data<<"  ";
        }
        
    }

   
    
return 0;
}
