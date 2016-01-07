//
//  main.cpp
//  c++中的链表的讲解
//
//  Created by student on 16/1/5.
//  Copyright (c) 2016年 student. All rights reserved.
//
/*
 list的讲解：
 一、单链表的讲解
    1、头指针是指链表指向第一个结点的指针，若链表有头结点，则是指向头结点的指针。
    2、头指针具有标识作用，所以常用头指针冠以链表的名字（指针变量的名字）
   3、无论链表是否是空，头指针均不为空。
   4、头指针的数据域一般是无意义的
   5、头结点的数据域一般写的是链表的长度，或者不写东西，或者也是不用写头结点的
 
 一个算法：怎样时限
 
 */
#include <iostream>
#include <time.h>
#define  LEN  sizeof(Student)
//#include <stdio.h>
using namespace std;
//定义一个节点，声明一个整型变量 表示链表的长度
static int ListLen = 0;
struct Student  {
    int num;
    float score;//数据域
    
    Student * next;//指针域
}  ;
//初始化一个链表
struct Student * Create();
//输出一个链表
void Print(Student * head);
int main(int argc, const char * argv[]) {
    //定义一个结构体指针，接收链表的头指针，最好定义为结构体指针，这样方便链式操作
    Student * aClass;
    aClass = Create();
    cout<<"Output the LinkList"<<endl;
    Print(aClass);
    return 0;
}

//以下是实现的是链表的基本的操作
//链表的初始化
struct Student * Create()
{
    Student * head =NULL;//创建一个头结点
    Student * p1 = NULL;
    Student * p2 = NULL;//创建一个节点进行保存p1指向的内存的地址
    /*
        创建两个指针的作用：p2保存p1的开辟的堆上的地址，方便p2->next(上一个p1在堆上开辟的节点的指针域指针指向p1新开辟的结点。)；依次循环，
     */
    
    
    p1 = (Student*)malloc(LEN);
    p2 = p1;//p2保存p1的地址
    if (p1==NULL) {
        cout<<"\nCan't create ,try it again!"<<endl;
        return  NULL;
    }
    else
    {
        cout<<"iPlease input the num and score of a student:"<<endl;
        cout<<"num of a student:";
        cin>>p1->num;
        cout<<"score of a student:";
        cin>>p1->score;
    }
    while (p1->num!=0) {
        ListLen+=1;
        //当是一个节点的时候需要把head指向p1(第一个节点)，只是在ListLen ==1的时候进行把头指针进行指向第一个节点
        if (ListLen ==1) {
            head = p1;
            p2->next = NULL;
        }
        //当ListLen>1的时候，使得上一个结点的指针域指针指向下一个节点
        else
        {
            p2->next = p1;
        }
        
        //以下的代码的意义是对开辟的结点的数据域进行赋值
        
        p2 = p1;//这是一个循环，所以需要p2重复的保存 p1的地址
        //以下就是表示的是重复的输入学生的分数和学号，当学号是“0”的时候跳出
        p1 = (Student *)malloc(LEN);
        cout<<"Please input the num and score of a student:"<<endl;
        cout<<"num of a student:";
        cin>>p1->num;
        //这个语句的判断的是当学号是“0”的时候需要立即跳出循环，不需要接着输入学生的分数。
        if (p1->num==0) {
            ListLen--;
            break;
        }
        cout<<"score of a student:";
        cin>>p1->score;
        
        
    }
    //尾节点的指针域指针指向null
    p2->next = NULL;
    //当输入的最后一个节点的  "num" 为“0”，所以需要释放这块开辟的内存，此时的p2指向上一个p1开辟的内存
    free(p1);
    p1= NULL;
    return  head;
}
//输出函数
void Print(Student * head)
{
    //Student * point = head;
    cout<<"***************************"<<endl;
    cout<<"number"<<"\t"<<"score"<<endl;
    while (head!=NULL) {//思考为何是这个条件
        cout<<head->num<<"\t\t"<<head->score<<endl;
        head = head->next;
    }
    cout<<"the total number of students is "<<ListLen<<endl;
   // head = point;

}


