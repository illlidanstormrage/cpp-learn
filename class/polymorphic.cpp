#include <iostream>
#include <utility>
using namespace std;

// 多态是C++面向对象的三大特性之一
// 多态分为两类：
//     静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
//     动态多态：派生类和虚函数实现运行时多态
// 静态多态和动态多态的区别：
//     静态多态的函数地址早绑定-编译阶段确定函数地址
//     动态多态的函数地址晚绑定-运行阶段确定函数地址

// 动态多态的满足条件：
//    1、有继承关系
//    2、子类重写(Override)父类的虚函数    重写：函数返回值类型、函数名、参数列表完全相同

// 动态多态使用
// 父类的指针或者引用 执行子类对象

// 动物类
class Animal{
public:
    //以下speak函数就是虚函数
    virtual void speak(){
        cout << "animal is speaking" << endl;
    }
    //函数前面加上virtual关键字，变成虚函数，那么编译器再编译阶段的时候就不能去确定函数调用
};

class Cat: public Animal{
public:
    void speak(){
        cout << "cat is speaking" << endl;
    }
};

// 地址早绑定 在编译阶段确定了函数的地址，因此调用的时候会调用Animal类,cat继承Animal的动物类型
void doSpeak(Animal &animal){ //Animal &animal = cat;
    animal.speak();
}
// 若想执行Cat.speak(),将Animal的speak()声明为虚函数，地址晚绑定

void test_1(){
    Cat cat;
    doSpeak(cat);
}

// Animal类内部结构
// vfptr(virtual function pointer)->vftable(virtual function pointer)
// vftable内记录虚函数的地址，(&Animal::speak)

// Cat类内部结构
// vftable内：当子类重写了父类的虚函数，子类的虚函数表内部会替换成子类的虚函数地址(&Cat::speak)

// 当父类的指针或者引用指向子类对象的时候，发生多态
// Animal &animal = cat;
// animal.speak()

void test_2(){
    cout << "size of Animal:" << sizeof(Animal) << endl;
    cout << "size of Cat:" << sizeof(Cat) << endl;
    cout << "size of ptr:" << sizeof(int*) << endl;
}

// 案例:计算器类
// 多态的优点：
//    1、代码组织结构清晰
//    2、可读性强
//    3、利于前期和后期的扩展以及维护
// 实际开发中，对扩展进行开发，对修改进行关闭

// 纯虚函数：再虚函数的基础上加=0 virtual 返回值类型 函数名(参数列表) = 0;
// 当类中有了纯虚函数，这个类称为抽象类

// 抽象类特点：
//    1、无法实例化对象
//    2、子类必须重写抽象类的纯虚函数，否则也属于抽象类
class AbstractCalculator{
public:
    virtual int getResult() = 0; //设为纯虚函数
    int m_Num1{};
    int m_Num2{};
};

// 加法
class AddCalculator: public AbstractCalculator{
    int getResult() override{
        return m_Num1 + m_Num2;
    }
};

// 减法
class SubCalculator: public AbstractCalculator{
    int getResult() override{
        return m_Num1 - m_Num2;
    }
};

// 除法
class DivCalculator: public AbstractCalculator{
    int getResult() override{
        return m_Num1 / m_Num2;
    }
};

// 乘法
class MulCalculator: public AbstractCalculator{
    int getResult() override{
        return m_Num1 * m_Num2;
    }
};
void test(){
    // 多态使用条件
    // 父类指针或者引用指向子类对象
    AbstractCalculator *c = new AddCalculator;
    c->m_Num1 = 10;
    c->m_Num2 = 10;
    cout << c->m_Num1 << " + " << c->m_Num2 << " = " << c->getResult() << endl;
    delete c;

    c = new SubCalculator;
    c->m_Num1 = 10;
    c->m_Num2 = 10;
    cout << c->m_Num1 << " - " << c->m_Num2 << " = " << c->getResult() << endl;
    delete c;

    c = new DivCalculator;
    c->m_Num1 = 10;
    c->m_Num2 = 10;
    cout << c->m_Num1 << " / " << c->m_Num2 << " = " << c->getResult() << endl;
    delete c;
}

// 虚析构和纯虚析构
class Animal_{
public:
    Animal_(){
        cout << "Animal construct" << endl;
    }

    explicit Animal_(string){
        cout << "Animal construct" << endl;
    }
    //将父类的析构改为虚析构，才会调用子类的析构函数
    //纯虚析构需要声明也需要实现
    //有了纯虚析构后，该类也为抽象类
    virtual ~Animal_() = 0; //纯虚析构，直接运行会报错，没有虚析构的具体实现

    virtual void speak() = 0;
    string *m_Name{};
};
Animal_::~Animal_(){} //若使用纯虚析构，需要加一行虚析构的实现

class Dog: public Animal_{
public:
    Dog()= default;

    explicit Dog(string name){
        m_Name = new string(name);
        cout << "Dog construct" << endl;
    }

    void speak() override{
        cout << *m_Name << " dog is speaking" << endl;
    }

    ~Dog(){
        if(m_Name != nullptr){
            delete m_Name;
            m_Name = nullptr;
        }
        cout << "Dog destroy" << endl;
    }
};

void test_3(){
    Animal_ *animal = new Dog("tom");
    animal->speak();
    // 父类指针在析构的时候，不会调用子类中的析构函数，导致子类如果有堆区属性，发生内存泄漏
    delete animal;
}

int main(){
//    test_1();
//    test_2();
//    test();
    test_3();
}