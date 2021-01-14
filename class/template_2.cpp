#include <iostream>
using namespace std;

template<class T1 = string, class T2 = int>
class Person{
public:
    Person() = default;

    Person(T1 name, T2 age){
        m_Name = name;
        m_Age = age;
    }

    T1 m_Name;
    T2 m_Age;

    void showPerson(){
        cout << "name:" << m_Name << " age:" << m_Age << endl;
    }

};

// 类模板对象做函数参数
// 一共有三种传入方式：
// 1、指定传入的类型--直接显示对象的数据类型
void printPerson1(Person<>&p){
    p.showPerson();
}

void test_1(){
    Person<> p("tom", 10);
    printPerson1(p);
}

// 2、参数模板化   --将对象中的参数变为模板进行传递
template<typename T1, typename T2>
void printPerson2(Person<T1, T2>&p){
    p.showPerson();
    cout << "type of T1:" << typeid(T1).name() << " type of T2:" << typeid(T2).name() << endl;
}

void test_2(){
    Person<> p("mike", 12);
    printPerson2(p);
}

// 3、整个类模板化 --将这个对象类型模板化进行传递
template<class T>
void printPerson3(T&p){
    p.showPerson();
    cout << typeid(T).name() << endl;
}

void test_3(){
    Person<> p("kimi", 12);
    printPerson3(p);
}

// 类模板与继承
template<class T>
class Base{
    T m;
};

class Son: public Base<int>{

};

// 如果想灵活的指定父类中T的类型，子类也需要变成类模板
template<class T1, class T2>
class Daughter: public Base<T1>{ //T1的类型为父类中的m的类型
    T1 obj_1;
    T2 obj_2;
};

int main(){
//    test_1();
//    test_2();
//    test_3();
}