// STL大体分为六大组件，分别是：容器、算法、迭代器、仿函数、适配器、空间配置器
// 1、容器：各种数据结构，如vector、list、deque、set、map等，用来存放数据
// 容器分为 序列式容器 和 关联式容器两种：
// 序列式容器：强调值的排序，该种容器中的每个元素都有固定的位置
// 关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系

// 2、算法，各种常用的算法，如sort、find、copy、for_each等
// 算法分为：质变算法 和 非质变算法
// 质变算法：运算过程中会更改区间内的元素的内容，如拷贝、替换、删除等
// 非质变算法：是指运算过程中不会更改区间内的元素内容，如查找、计数、遍历等

// 3、迭代器：扮演了容器与算法之间的胶合剂
// 提供一种方法，使之能够依序访问某个容器中所含的各个元素，又无需暴露该容器的内部表示方式

// 4、仿函数：行为类似函数，可作为算法的某种策略
// 5、适配器（配接器）：一种用来修饰容器或迭代器接口的东西
// 6、空间适配器：负责空间的配置和管理

#include <iostream>
using namespace std;
#include <algorithm> //标准算法头文件

// vector容器存放内置数据类型
#include <vector>

void myPrint(int &a){
    cout << a << endl;
}

void test_1(){
    // 创建一个vector容器，数组
    vector<int> v;

    // 向容器插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // 通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin(); //起始迭代器 指向容器中第一个元素的位置
    vector<int>::iterator itEnd = v.end(); //指向容器中最后一个元素的下一个位置

    // 第一种遍历方式
    while(itBegin != itEnd){
        cout << *itBegin << endl;
        itBegin++;
    }

    // 第二种遍历方式
    for(auto it = v.begin(); it!=v.end(); it++){
        cout << *it << endl;
    }

    for(int &it : v){
        cout << it << endl;
    }

    // 第三种遍历方式
    for_each(v.begin(), v.end(), myPrint); //最后一个参数为callback
}

// vector容器中存放自定义数据类型
class Person{
public:
    Person() = default;
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void test_2(){
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 10);
    Person p3("ccc", 10);
    Person p4("ddd", 10);
    Person p5("eee", 10);

    // 向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍历容器中的数据
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << "name:" << it->m_Name << "  age:" << it->m_Age << endl;
    }


}

// vector容器中存放指针
void test_3(){
    vector<Person*> v;
    Person p1("aaa", 10);
    Person p2("bbb", 10);
    Person p3("ccc", 10);
    Person p4("ddd", 10);
    Person p5("eee", 10);

    // 向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    // 遍历容器中的数据
    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++){
        cout << "name:" << (*it)->m_Name << "  age:" << (*it)->m_Age << endl;
    }
}

// vector容器嵌套
void test_4(){
    vector<vector<int>> V;
    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    // 向小容器添加数据
    for(int i=0; i<4; i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    // 将小容器插入到大容器中
    V.push_back(v1);
    V.push_back(v2);
    V.push_back(v3);
    V.push_back(v4);

    // 通过大容器遍历所有数据
    for(vector<vector<int>>::iterator it = V.begin(); it != V.end(); it++){
        // (*it)是V里的一个容器
        for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++){
            cout << *vit << " ";
        }
        cout << endl;
    }
}



int main(){
//    test_1();
//    test_2();
//    test_3();
    test_4();
}