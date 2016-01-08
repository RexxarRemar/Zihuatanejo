#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct node
{
    int data;
    struct node * next;
} node;
//创建一个循环链表,传进来的参数是需要创建的节点的个数。
node *Create(int n)
{
    node *p = nullptr,*head;
    //这是头结点
    head = (node*)malloc(sizeof(node));
    p = head;
    node *s;
    int i =1;
    if (n!=0) {
        while (i<=n) {
            //s是第一个节点
            s = (node*)malloc(sizeof(node));
            s->data = i++;
            p->next = s;//
            p=s;
        }
        //抛弃头结点，最后一个节点指向第一个节点
        s->next = head->next;
    }
    //然后是释放掉头结点
    free(head);
    head = nullptr;
    
    //返回的就是第一个节点
    return s->next;
}
int main()
{
    int n = 41;
    int m = 3;
    node * p = Create(n);
    node * temp;
    n%=m;
    int total = 41;
    //这个条件是当链表是一个空得链表
    //total>2//换成这个条件的话输出的是  16
    while (p!=p->next) {//最后剩下的是 31
        for (int i = 1; i<m-1; i++) {
            p = p->next;
        }
        cout<<"删除的点是:"<<p->next->data<<"   "<<endl;
        
        //这几句的作用是删除第三个节点
        temp = p->next;//temp指向第三个节点
        p->next = temp->next;//p指向第四个节点
        //释放掉第三个节点
        free(temp);
        temp = nullptr;
        total--;
        
        //将p指向想一个节点，上面for中执行一次，所以总共执行了两次，第三个人要杀掉。
        p =  p->next;
        
    }//输出的是 16和31
    cout<<"***"<<p->data<<endl;//
    return  0;
}