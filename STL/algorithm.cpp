#include <iostream>
#include <numeric>
#include <functional>
#include <algorithm>
using namespace std;
#include <vector>

// 常用遍历算法
void print_1(int val){
    cout << val << " ";
}

class Transform{
public:
    int operator()(int val){
        return val+10;
    }
};

void test_1(){
    vector<int> v;
    v.reserve(10);
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    // 搬运容器到另一个容器中 transform(iterator beg1, iterator end1, iterator beg2, func);
    vector<int> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), Transform());

    // 遍历容器 for_each(iterator beg, iterator end, _func);
    for_each(v2.begin(), v2.end(), print_1);
}

// 常用查找算法
class Person{
public:
    Person(const string &name, const int &age){
        this->m_Name = name;
        this->m_Age = age;
    }

    // 重载==号让底层知道如何对比Person数据类型
    bool operator==(const Person& p) const{
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age){
            return true;
        }
        else{
            return false;
        }
    }
    string m_Name;
    int m_Age;
};

void test_2(){
    vector<int> v;
    v.reserve(10);
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    // 查找元素 find(iterator beg, iterator end, value); 返回指定元素的迭代器，找不到返回end()
    auto it = find(v.begin(), v.end(), 50);
    if(it == v.end()){
        cout << "not find" << endl;
    }
    else{
        cout << "find: " << *it << endl;
    }

    // 查找自定义数据类型
    vector<Person> v2;
    Person p1("tom", 10);
    Person p2("jerry", 40);
    Person p3("x", 20);
    Person p4("kimi", 30);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    auto it2 = find(v2.begin(), v2.end(), p2);
    if(it2 == v2.end()){
        cout << "not find" << endl;
    }
    else{
        cout << "name:" << it2->m_Name << " age:" <<  it2->m_Age <<endl;
    }
}

// 按条件查找 find_if(iterator beg, iterator end, _Pred); 按值查找元素，找到返回位置迭代器，找不到返回结束迭代器位置。pred为谓词
class Greater20{
public:
    bool operator()(Person &p){
        return p.m_Age>20;
    }
};

void test_3(){
    vector<Person> v2;
    Person p1("tom", 10);
    Person p2("jerry", 40);
    Person p3("x", 20);
    Person p4("kimi", 30);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);

    auto it = find_if(v2.begin(), v2.end(), Greater20());
    if(it == v2.end()){
        cout << "not find" << endl;
    }
    else{
        cout << "name:" << it->m_Name << " age:" <<  it->m_Age <<endl;
    }
}


int main(){
//    test_1();
//    test_2();
    test_3();

}