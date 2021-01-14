#include <iostream>
using namespace std;

// 基本语法：class 子类（派生类）：继承方式 父类（基类）
// 继承方式有三种：公共继承、保护继承、私有继承
// 父类的private内容子类无论如何都不能访问
// 子类用protected方式继承会将父类中的public也继承为protected
// 子类用public方式继承会保留父类中的权限
class Basic{
public:
    Basic(){
        cout << "father construct" << endl;
    }
    ~Basic(){
        cout << "father destroy" << endl;
    }
    void func(){
        cout << "father func" << endl;
    }
    void func(int a){
        cout << "father func b" << endl;
    }
    int m_A = 10;
protected:
    int m_B;
private:
    int m_C;
};

class Son: public Basic{
public:
    Son(){
        cout << "son construct" << endl;
    }
    ~Son(){
        cout << "son destroy" << endl;
    }
    void func(){
        m_A = 10; //父类中的公共权限成员 到子类中依然是公共权限
        m_B = 10; //父类中的保护权限成员 到子类中依然是保护权限
//        m_C = 10; //父类中的四有权限成员 子类访问不到
    }

    int m_D;
    // 子类中与父类同名成员，访问的时候会调用子类的成员
    int m_A = 20;
};

class Daughter: protected Basic{
public:
    void func(){
        m_A = 10; //父类中的公共权限成员 到子类中变为保护权限
        m_B = 10;
//        m_C = 10;
    }
};

class SonTer: private Basic{
    void func(){

    }
};

void test_1(){
    // 父类中的所有非静态成员属性都会被子类继承下去
    // 父类中私有成员属性 被编译器隐藏，不能访问，但会继承
    cout << "size of Son:" << sizeof(Son) << endl;
    // 继承中构造和析构顺序
    Son son;
    // 先构造父类，再构造子类；析构与构造相反
    cout << "Son m_A=" << son.m_A << endl;
}

void test_2(){
    Son son;
    // 对于同名成员的访问，需要加上作用域才能访问到父类成员
    cout << "Basic m_A=" << son.Basic::m_A << endl;
    son.Basic::func();
    // 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    son.Basic::func(100); //若想访问需要添加作用域
}
// 子类对象可以直接访问子类同名成员
// 子类对象加作用域可以访问父类同名成员
// 当子类与父类拥有同名的成员函数，需要添加作用域才能访问父类的同名成员函数

// 继承中的同名静态成员
class Father{
public:
    static int m_A;
};
int Father::m_A = 100;

class Son_1: public Father{
public:
    static int m_A;
};
int Son_1::m_A = 200;

void test_3(){
    //1、通过对象访问
    cout << "by object:" << endl;
    Son_1 s;
    cout << "Son_1 m_A=" << s.m_A << endl;
    cout << "Father m_A=" << s.Father::m_A << endl;

    //2、通过类名访问
    cout << "by className:" << endl;
    cout << "Son_1 m_A=" << Son_1::m_A << endl;
    cout << "Father m_A=" << Son_1::Father::m_A << endl;
}

// C++允许一个类继承多个类
// 语法 class 子类: 继承方式 父类1, 继承方式 父类2...
// 多继承可能引发父类中有同名成员出现，需要加作用域来区分

// 利用虚继承 可以解决菱形继承的资源浪费问题
class Animal{
public:
    int m_Age = 28;
};

// 继承前加上关键字virtual 变为虚继承
class Sheep: virtual public Animal{};
class Tuo: virtual public Animal{};
class SheepTuo: public Sheep, public Tuo{};

void test_4(){
    SheepTuo st;
    //当菱形继承，两个父类拥有相同数据，需要加以作用于区分
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;
    cout << "m_Age of SheepTuo:" << st.m_Age << endl;
}

int main(){
//    test_1();
//    test_2();
//    test_3();
    test_4();
}