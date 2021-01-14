//
// Created by illlidan on 2021/1/8.
//

#include <iostream>
using namespace std;

// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量
class Person_1{
public:
    static void func_1(){ //静态成员函数
        int m_A = 100;
//        m_B = 100; //静态成员函数不能访问非静态成员变量，无法区分是哪个对象的变量
        cout << "public static void func_1" << endl;
    }

    static int m_A; //静态成员变量
    int m_B; //非静态成员变量

    // 静态成员函数也有访问权限
private:
    static void func_2(){
        cout << "private static void func_2" << endl;
    }
};

// 两种访问方式
void test_1(){
    //1、通过类名访问
    Person_1::func_1();

    //2、通过对象访问
    Person_1 p;
    p.func_1();

    // private下的静态成员函数依然受权限控制
//    Person_1::func_2();
}


// C++对象模型和this指针
class Person_2{
public:
    Person_2(){
        m_A = 0;
    }

    // 非静态成员变量占用对象空间
    int m_A;
    //静态成员变量不占用对象空间
    static int m_B;
    // 函数不占用对象空间，所有函数共享一个函数实例
    void func(){
        cout << "m_A:" << this->m_A << endl;
    }
};

class null_Class{

};

void test_2(){
    Person_2 p;
    // p中仅m_A占用对象空间
    cout << "size of p:" << sizeof(p) << endl;

    // 空对象占用内存空间为1
    // C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存空间
    null_Class q;
    cout << "size of null_Class:" << sizeof(q) << endl;
}


// this指针时隐含再每一个非静态成员函数内的指针
// this指针不需要定义，直接使用即可
class Person_3{
public:
    Person_3(){};
    // 当形参和成员变量同名时，可用this指针来区分
    // this指针指向 被调用的成员函数 所属对象
    Person_3(int age){
        this->age = age;
    }

    // 在类的非静态成员函数中返回对象本身，可使用return *this
    Person_3& age_add(Person_3 p){
        this->age += p.age;
        // this是指向p2的指针，*this为对象p2的本体
        return *this;
    }

    int age;
};

void test_3_1(){
    Person_3 p1(18);
    cout << "age of p1:" << p1.age << endl;
}

void test_3_2(){
    Person_3 p1(10);
    Person_3 p2(10);
    // 链式编程
    p2.age_add(p1).age_add(p1);
    cout << "age of p2:" << p2.age << endl;
}

// C++中空指针可以调用成员函数，但要注意有没有用this指针
// 如果用到了this指针，需要加以判断保证代码的健壮
class Person_4{
public:
    void show_class_name(){
        if(this == nullptr){
            return;
        }
        cout << "class Person_4" << endl;
    }

    void show_person_age(){
        if(this == nullptr){
            return;
        }
        cout << "Person age is:" << m_age << endl;
    }

    int m_age;
};

void test_4(){
    Person_4 *p = nullptr;
    p->show_class_name();
    p->show_person_age();
}

// 常函数：
//    const修饰成员函数后我们称该函数为常函数
//    常函数内不可以修改成员属性
//    成员属性声明时加关键字mutable后，在常函数中依然可以修改
// 常对象：
//    声明对象前加const称该对象为常对象
//    常对象只能调用常函数

class Person_5{
public:
    // 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    void show_person() const{
//        this = nullptr; // this指针的本意为 Person_5 * const this; 是指针常量，指针的指向不能修改
//        m_A = 100; // m_A的本质是this->m_A，在该函数中this即为 const Person_5 * const this; this指向的值也不能修改
        m_B = 100; // m_B前面加了mutable 不报错
    }

    void func(){

    }
    int m_A;
    mutable int m_B; //特殊变量，即使在常函数中也能修改这个值
};

void test_5(){
    const Person_5 p{};// 常对象
//    p.m_A = 100; //常对象的值不允许修改
    p.m_B = 100; // m_B在常对象下也能修改
//    p.func(); //常对象只能调用常函数
}

int main(){
//    test_1();
//    test_2();
//    test_3_1();
//    test_3_2();
//    test_4();
}