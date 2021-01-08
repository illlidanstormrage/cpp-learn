//
// Created by illlidan on 2021/1/8.
//

#include <iostream>
using namespace std;

class Person{
public:
    int age;
    int *height;

    Person(){
        cout << "construct without parament" << endl;
    }

    Person(int Age, int Height){
        age = Age;
        height = new int(Height);
        cout << "construct with parament" << endl;
    }
// 浅拷贝的问题利用深拷贝解决
    Person(const Person& person){
        age = person.age;
        height = new int(*person.height);
        cout << "copy construct" << endl;
    }

    ~Person(){
        if(height!=nullptr){
            delete height; //析构函数将堆区开辟数据做释放
            height = nullptr;
        }
        cout << "destroy" << endl;
    }
};

void test_1(){
    Person p1(18, 160);
    cout << "p1 age:" << p1.age << " height:" << *p1.height << endl;
// 编译器提供的拷贝构造为浅拷贝，将对象的所有属性拷贝，调用析构函数时会由于两个对象分配到的堆区地址相同，导致delete重复释放
    Person p2(p1);
    cout << "p2 age:" << p2.age << " height:" << *p2.height << endl;
}

int main(){
    test_1();
}