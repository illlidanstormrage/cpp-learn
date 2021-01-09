// 运算符重载：对已有的运算符重新进行定义，赋予一种功能，以适应不同的数据类型
// 内置操作符不可重载
#include <iostream>
using namespace std;

// 运算符重载
class Person{
public:
    Person()= default;
    Person(int a, int b){
        this->m_A = a;
        this->m_B = b;
    }
    // 通过成员函数重载+号
    Person operator+(Person &p) const{
        Person temp{};
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
    // 不能利用成员函数重载<<运算符，不能实现cout在左侧

    int m_A;
    int m_B;
};

// 全局函数重载+号
Person operator+(Person &p1, Person &p2){
    Person temp{};
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

// 全局函数重载左移符号<<
ostream &operator<<(ostream &out, Person &p){
    out << "m_A=" << p.m_A << " m_B=" << p.m_B;
    return out;
}

// 运算符函数重载
Person operator+(Person &p1, int p2){
    Person temp{};
    temp.m_A = p1.m_A + p2;
    temp.m_B = p1.m_B;
    return temp;
}

void test_1(){
    Person p1(10, 10);
    Person p2(10, 10);
    // 全局函数本质调用: Person p3 = operator+(p1, p2);
    // 成员函数本质调用: Person p3 = p1.operator+(p2);
    Person p3 = p1 + p2;
    // 运算符重载 也可以发生函数重载
    Person p4 = p1 + 10;
    cout << "p3.m_A=" << p3.m_A << " p3.m_B=" << p3.m_B << endl;
    cout << "p4.m_A=" << p4.m_A << " p4.m_B=" << p4.m_B << endl;
    cout << p4 << endl;
}

// 重载递增运算符++
// 自定义整型
class My_integer{
    friend ostream &operator<<(ostream &out, My_integer &p);
public:
    My_integer(){
        m_num = 0;
    }
    explicit My_integer(int a){
        m_num = a;
    }

    //重置前置++
    My_integer& operator++(){
        // 先+1运算
        m_num++;
        // 再将自身返回
        return *this;
    }

    //重置后置++
    const My_integer operator++(int){//int为占位参数，用于区分前置和后置递增
        // 先记录结果
        My_integer temp = *this;
        // 再做+1运算
        m_num++;
        return temp;
    }
private:
    int m_num;
};

// 重载<<运算符
ostream &operator<<(ostream &out, My_integer &p){
    out << "m_A=" << p.m_num << endl;
    return out;
}

void test_2(){
    My_integer my_int(10);
    cout << ++my_int << endl;
}

// 重载赋值运算符
// c++编译器会默认提供operator=
class Person_2{
public:
    Person_2(){}

    explicit Person_2(int age){
        m_age = new int(age);
    }

    // 利用深拷贝
    Person_2(const Person_2 &p){
        m_age = new int(*p.m_age);
    }
    ~Person_2(){
        if(m_age != nullptr){
            delete m_age;
            m_age = nullptr;
        }
    }

    // 重载=
    Person_2& operator=(Person_2 &p){
        if(m_age != nullptr){
            delete m_age;
            m_age = nullptr;
        }
        // 深拷贝
        m_age = new int(*p.m_age);
        return *this;
    }

    // 关系运算符重载 !=、==
    bool operator!=(Person_2 &p){
        if(*m_age == *p.m_age){
            return false;
        }
        return true;
    }

    bool operator==(Person_2 &p){
        if(*m_age == *p.m_age){
            return true;
        }
        return false;
    }

    int *m_age;
};

void test_3(){
    Person_2 p1(18);
    Person_2 p2(20);
    Person_2 p3;
    p3 = p2 = p1;
    cout << "p1:" << *p1.m_age << endl;
    cout << "p2:" << *p2.m_age << endl;
    cout << "p3:" << *p3.m_age << endl;
}

void test_4(){
    Person_2 p1(18);
    Person_2 p2(20);
    Person_2 p3(18);
    if(p1==p2){
        cout << "p1=p2" << endl;
    }
    else {
        cout << "p1!=p2" << endl;
    }
    if(p1==p3){
        cout << "p1=p3" << endl;
    }
    else{
        cout << "p1!=p3" << endl;
    }
}


// 函数调用运算符()也能重载
class My_print{
public:
    //重载函数调用运算符
    void operator()(string test){
        cout << test << endl;
    }

};

// 仿函数没有固定写法，非常灵活
class My_add{
public:
    int operator()(int num1, int num2){
        return num1 + num2;
    }
};

void test_5(){
    My_print my_print;
    my_print("hello world"); // 由于重载后使用的方式非常像函数的调用，因此称为仿函数

    My_add my_add;
    int ret = my_add(100, 100);
    cout << "ret=" << ret << endl;
    // 匿名函数对象
    cout << My_add()(100, 100) << endl;
}

int main(){
//    test_1();
//    test_2();
//    test_3();
//    test_4();
    test_5();
}
