//
//  main.cpp
//  斐波那契数列
//
//  Created by student on 16/1/14.
//  Copyright (c) 2016年 student. All rights reserved.
//

#include <iostream>
using namespace std;
int Fib(int n)
{
    if (n<2) {
        if (n==1) {
            return 1;
        }
        else if(n==0)
        {
            return 0;
        }
    }
    return Fib(n-1)+Fib(n-2);
}
//逆序输出一个字符串，递归是一个神一样的方法；第二个是使用指针，反序输出；第三个是使用c++的stl中的list，迭代器逆序输出，第四个是使用数组进行逆序输出元素
void Print()
{
    char c;
    cin>>c;
    if (c!='#') {
        Print();
    }
    cout<<"rsort";
    if (c!='#') {
        cout<<c;
    }
}
//实现字符串的逆序
void reverse()
{
    char c;
    if((c = getchar()) != '\n')
        reverse();
    if(c != '\n')
        putchar(c);
}
int main(int argc, const char * argv[]) {
    //使用的是递归（使用的是选择结构），这种方式比较耗时耗费内存
//    int num = Fib(5);
//    cout<<"num:"<<num<<endl;
    //模拟斐波那契数列,使用的是迭代（循环结构）
    
//    int a[12];
//    a[0] = 0;
//    a[1] = 1;
//    for (int i = 2; i<=12; i++) {
//        a[i] = a[i-1]+a[i-2];
//        cout<<a[i]<<"  ";
//    }
    //实现逆序输出字符串
    cout<<"输入字符串"<<endl;
    //Print();
    reverse();
    
    cout<<endl;
    return 0;
}
