//
//  main.cpp
//  凯撒加密
//
//  Created by student on 16/1/11.
//  Copyright (c) 2016年 student. All rights reserved.
//

#include <iostream>
using namespace std;
int n = 3; //向后移动的位数

string caesarCipher(string str)
{
    string ciphertext;
    int size = (int)str.size();
    for(int i = 0 ; i <size ; ++i)
    {
        int c = (int)str.at(i);//直接把字符变量强制转换为整型就是 ascii值
        if(c > 90)
            c = c- 32;//z转化为大写字母的ascii码值
        
        if((c+n) <= 90)
            ciphertext += (char)(c+n);//重新转换为字符变量
        else//表示的最后  WXYZ
            ciphertext += (char)(65+((c+n)-90) );//
        
    }
    return ciphertext;
}

int main(int argc, const char * argv[]) {
    // insert code here...


    
    
    string str = "WXYZ";//明文
    string ciphertext =  caesarCipher(str);//密文
    cout << ciphertext.c_str()  << endl;
    // cout << (int)'a'<<","<<(int)'z'<<endl;
    cout<<"str.at(1):"<<str.at(1);
    
    return 0;
}
