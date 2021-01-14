// 模板：建立通用的模具，大大提高复用性
#include <iostream>
using namespace std;

// C++另一种编程思想称为 泛型编程，主要利用的技术就是模板
// C++提供两种模板机制：函数模板和类模板

// 函数模板作用：建立一个通用函数，其函数返回值类型和形参类型可以不做具体制定，用一个虚拟的类型来代表
// 语法：
// template<typename T>  // template--声明创建模板  typename--表明其后面的符号是一种数据类型，可以用class代替  T--通用的数据类型，名称可以替换，通常为大写字母

// 函数模板

template<typename T>
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void func(){
    cout << "func" << endl;
}

void test_1(){
    int a = 10;
    int b = 20;
    char c = 'c';
    // 利用函数模板交换
    // 两种方式使用函数模板

    // 1、自动类型推导
    // 自动类型推导，必须推导出一致的数据类型才能使用
//    mySwap(a, c); //推导不出一致的T类型

    // 模板必须要确定T的数据类型才能使用
    func<int>();

    mySwap(a, b);
    cout << "a=" << a << " b=" << b << endl;

    // 2、显示指定类型
    mySwap<int>(a, b);
    cout << "a=" << a << " b=" << b << endl;
}

// 普通函数与函数模板的区别：
//    1、普通函数调用可以发生自动类型转换（隐式类型转换）
//    2、函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//    3、如果利用显示指定类型的方式，可以发生隐式类型转换

int myAdd_1(int a, int b){
    return a+b;
}

template<typename T>
T myAdd_2(T a, T b){
    return a+b;
}

void test_2(){
    int a = 10;
    int b = 20;
    char c = 'c';
    //普通函数调用可以发生自动类型转换（隐式类型转换）
    cout << myAdd_1(a, c) << endl;

    //函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//    cout << myAdd_2(a, c) << endl;

    //如果利用显示指定类型的方式，可以发生隐式类型转换
    cout << myAdd_2<int>(a, c) << endl;
}

// 模板调用规则
void myPrint(int a, int b){
    cout << "using func" << endl;
}

template<typename T>
void myPrint(T a, T b){
    cout << "using template" << endl;
}

template<typename T>
void myPrint(T a, T b, T c){
    cout << "using overloaded template" << endl;
}

void test_3(){
    int a = 10;
    int b = 20;
    int c = 30;
    // 普通函数和函数模板如果都能够实现，则优先调用普通函数
    myPrint(a, b);

    // 可以通过空模板参数列表来强制调用
    myPrint<>(a, b);

    // 函数模板也可以发生函数重载
    myPrint(a, b, c);

    // 如果函数模板可以产生更好的匹配，优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);
}
// 在提供了函数模板后，尽量不要提供普通函数，防止出现二义性

// 有的类型不适合模板调用
// 类模板可以在模板参数列表中有默认参数
template<class AgeType = int, class HeightType = int>
class Person{
public:
    AgeType m_age{};
    HeightType m_height{};
    Person()= default;
    Person(AgeType age, HeightType height){
        m_age = age;
        m_height = height;
    }
};

template<class T>
bool myCompare(T &a, T &b){
    if(a==b){
        return true;
    }
    else{
        return false;
    }
}

// 对某些不适合模板的调用，可以利用具体化的版本实现代码，实现优先调用
template<> bool myCompare(Person<int, int> &p1, Person<int, int> &p2){
    if(p1.m_height==p2.m_height && p1.m_age==p2.m_age){
        return true;
    }
    else{
        return false;
    }
}

void test_4(){
    // 类模板没有自动类型推导的使用方式
    Person<> p(12, 160);
    Person<int, int> p1(12, 160);
    Person<int, int> p2(12, 160);
    cout << myCompare(p1, p2) << endl;
}
// 学习模板的目的是在STL能够运用系统提供的模板

// 类模板中成员函数和普通类成员函数创建时机有区别：
//   普通类中的成员函数一开始就可以创建
//   类模板中的成员函数在调用时才创建


int main(){
//    test_1();
//    test_2();
//    test_3();
//    test_4();
}
