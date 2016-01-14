//
//  main.cpp
//  队列的讲解
//
//  Created by student on 16/1/14.
//  Copyright (c) 2016年 student. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define OK 1
#define  ERROR -1
#define  OVERFLOW 0
typedef int  elemtype;
typedef int  status;
typedef struct QNode
{
    elemtype data;
    QNode *next;
}QNode ,*queuePtr;//定义链表节点中的数据
typedef struct
{
    queuePtr front;//指向链表的头
    queuePtr rear;//指向链表的尾
}LinkQueue;

//对于队列进行初始化,传引用
//创建的是一个节点，使得队列的头指针和尾指针都指向这一片空间
status initQueue(LinkQueue &q)
{
    q.front = q.rear = (queuePtr)malloc(sizeof(QNode));//创建头结点 头指针指向头节点
    if (!q.front) {
        //创建失败
        exit(OVERFLOW);
    }
    q.front->next = nullptr;
    return  OK;
}
//销毁队列
status destoryQueue(LinkQueue &q)
{
    while (q.front) {
        q.rear = q.front->next;  //将头结点的next赋值给尾指针
        free(q.front);  //删除头结点
        q.front = q.rear; //头指针 指向下一个节点，
    }
    cout<<"队列销毁成功\n";
    q.front = nullptr;//最后一个节点的  置空
    return  OK;//
}
//进行元素插入,e表示的需要插入的元素
status enQueue(LinkQueue &q,elemtype e)
{
    //为新的元素分配空间,赋值
    queuePtr p = (queuePtr)(malloc(sizeof(QNode)));
    //申请失败退出
    if (!p) {
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = nullptr;
    
    //
    q.rear->next = p;//为尾指针的nxt重新赋值  将元素插入表位
    q.rear = p; // 重新定位尾指针
    return OK;
}
//删除元素
status deQueue(LinkQueue &q)
{
    if (q.front == q.rear) {
        return ERROR;//此时的队列是空队列
    }
    //队列是从队首进行移除元素，这是和链表不同的地方
    queuePtr p = q.front->next;
    q.front->next = p->next;//使得队首指向第二个节点，实现删除第一个结点
    
    //这是一个判定，若是删除之后只有一个节点，表示是空节点
    if (q.rear == p) {
        q.rear = q.front;
    }
    free(p);//释放刚才删除的节点
    cout<<"元素删除成功！\n";
    return OK;
}
//获取队首元素
status getHead(LinkQueue &q){

    queuePtr p  = q.front->next;
    cout<<"队首元素："<<p->data;
    return OK;
}
//输出队列
status printQueue(LinkQueue &q)
{
    queuePtr p;
    p = q.front->next;
    while (p) {
        cout<<"元素："<<p->data<<endl;
       p =  p->next;
    }
    return OK;
}
int main(int argc, const char * argv[]) {
    
    LinkQueue q;
    int k,m,n;
    initQueue(q);
    cout<<"请输入插入数据的个数："<<endl;
    cin>>n;
    for (int i = 0; i<n; i++) {
        cout<<"请输入第"<<i+1<<"个整数"<<endl;
        cin>>k;
        enQueue(q, k);
    }
    
    
    do {
        cout<<endl<<"*********************"<<endl;
        cout<<"请根据提示进行相应地操作："<<endl;
        cout<<"删除元素选择输入1：\n";
        cout<<"清空队列选择输入2："<<endl;
        cout<<"输出队列选择输入3："<<endl;
        cout<<"退出输入4："<<endl;
        cout<<"********************"<<endl;
        cin>>m;
        switch (m) {
            case 1:
                deQueue(q);
                break;
            case 2 :
                destoryQueue(q);
                break;
            case 3:
                printQueue(q);
                break;
            default:
               // cout<<"请重新输入："<<endl;
                break;
        }
    } while (m!=4);//当输入4的时候退出
    
    return 0;
}
