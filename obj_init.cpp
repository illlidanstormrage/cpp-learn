//
// Created by illlidan on 2021/1/8.
//

#include <iostream>
using namespace std;

// 语法：构造函数():属性1(值1),属性2(值2)...{}

class Person{
public:
//    //传统初始化操作
//    Person(int a, int b, int c){
//        m_A = a;
//        m_B = b;
//        m_C = c;
//    }

    //初始化列表初始化属性
    Person(int a, int b, int c):m_A(a), m_B(c), m_C(c){};

    int m_A;
    int m_B;
    int m_C;
};

void test_1(){
    Person p(10, 20, 30);
    cout << "m_A=" << p.m_A <<  " m_B=" << p.m_B << " m_C=" << p.m_C <<endl;
}

int main(){
    test_1();
}