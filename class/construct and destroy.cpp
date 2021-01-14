#include <iostream>
using namespace std;

// 构造函数：主要作用在创建对象时为对象的成员属性赋值，构造函数由编译器自动实现，无须手动调用
// 析构函数：主要作用在对象销毁前系统自动调用，执行一些清理工作

// 构造函数语法：类名(){}
// 1、构造函数没有返回值也不写void
// 2、构造函数名称与类名相同
// 3、构造函数可以有参数，因此可以重载
// 4、程序在调用对象的时候会自动调用构造，无须手动调用，而且只会调用一次

// 析构函数语法：~类名(){}
// 1、析构函数没有返回值也不写void
// 2、函数名称与类名相同，在名称前加上符号~
// 3、析构函数不能有参数，因此不能发生重载
// 4、程序在对象销毁前会自动调用析构，无须手动调用，而且只会调用一次

// 对象的初始化和清理
// 构造函数的分类及调用
class Person{
public:
// 1、构造函数 进行创建的操作
// 构造函数的分类
//    按照参数分类  无参构造（默认构造）  有参构造
//    按照类型分类  普通构造  拷贝构造
    Person(){ //无参构造
        cout << "construct without parament" << endl;
    }

    explicit Person(int a){ //有参构造
        age = a;
        cout << "construct with parament" << endl;
    }

    Person(const Person& p){ //拷贝构造
        age = p.age;
        cout << "copy construct" << endl;
    }

// 2、析构函数 进行清理的操作
    ~Person(){
        cout << "destroy" << endl;
    }

    int age{};
};

// 调用
void test_1(){
    // 括号法
    Person p1{}; //在栈上的数据，test_1()执行完毕后，释放这个对象 //无参构造
    Person p2(10); //有参构造
    Person p3(p2); //拷贝构造
    // 注意事项1    调用无参构造函数的时候，不要加()

    // 显式法
    Person p_1{}; //无参构造
    Person p_2 = Person(10); //有参构造
    Person p_3 = Person(p_2); //拷贝构造
    // Person(10)是一个匿名对象，当前行执行结束后，系统会立即回收掉匿名对象
    // 注意事项2    不要利用拷贝构造函数初始化匿名对象,编译器会认为Person(p_3) === Person p_3;
    // Person(p_3); //会报错

    // 隐式法
//    Person p4 = 10; //相当于 Person p4 = Person(10); ?? 存疑
//    Person p5 = p4; //拷贝构造
}

// 拷贝构造函数调用时机
// 1、使用一个已经创建完毕的对象来初始化一个新对象
void test_2(){
    Person p1(20);
    Person p2(p1);
    cout << "P2的年龄为：" << p2.age << endl;
}

// 2、值传递的方式给函数参数传值
void func_test_3(Person p){ //在此处会调用一次构造、析构

}

void test_3(){
    Person p; //调用构造析构
    func_test_3(p);
} //共会调用两次构造函数

// 3、值返回局部对象
Person func_test_4(){
    Person p1; //调用构造函数
    cout << "p1:" << &p1 << endl;
    return p1;
}

void test_4(){
    Person p2;
    p2 = func_test_4();
    cout << "p2:" << &p2 << endl;
}

// 默认情况下，c++编译器会给一个类提供添加3个函数：
// 默认无参构造函数、默认析构函数、默认拷贝构造函数（值拷贝）
// 如果用户自己提供无参构造，则编译器不再提供无参；如果用户自己提供有参构造，则编译器不再提供无参；如果用户自己提供拷贝构造，则编译器不再提供其他普通构造


// 4、类对象作为类成员的构造与析构
// 先调用对象成员的构造，再调用本类构造
// 析构顺序与构造相反
class Phone{
public:
    string p_name;
    Phone(){
        cout << "Phone construct" << endl;
    };

    Phone(string name){
        p_name = name;
        cout << "Phone construct" << endl;
    }

    ~Phone(){
        cout << "Phone destroy" << endl;
    }
};

class Person_{
public:
    Phone phone;
    string name;

    Person_(string p, string Name){
        phone.p_name = p;
        name = Name;
        cout << "Person construct" << endl;
    }

    ~Person_(){
        cout << "Person destroy" << endl;
    }
};

void test_5(){
    Person_ tom("iphone", "tom");
}

int main(){
//    test_1();
//    test_2();
//    test_3();
//    test_4();
//    test_5();
}
