#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

// 函数对象
// 概念：
//    重载函数调用操作符的类，其对象常称为函数对象
//    函数对象使用重载的()时，行为类似函数调用，也叫仿函数

// 本质：函数对象（仿函数）是一个类，不是一个函数

// 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
class MyAdd{
public:
    int operator()(int v1, int v2){
        return v1+v2;
    }
};

void test_1(){
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}

// 函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint{
public:
    MyPrint(){
        this->count = 0;
    }
    void operator()(const string& test){
        cout << test << endl;
        this->count++;
    }
    int count; //内部自己的状态
};

void test_2(){
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    cout << "count:" << myPrint.count << endl;
}

// 函数对象可以作为参数传递
void doPrint(MyPrint& mp, const string& test){
    mp(test);
}

void test_3(){
    MyPrint myPrint;
    doPrint(myPrint, "hello c++");
}

// 谓词
// 概念：
//    返回bool类型的仿函数称为谓词
//    如果operator()接受一个参数，那么叫做一元谓词
//    如果operator()接受两个参数，那么叫做二元谓词
class GreaterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};

void test01(){
    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }

    // 查找容器中有没有大于5的数字
    auto it = find_if(v.begin(), v.end(), GreaterFive()); //GreaterFive()为匿名函数对象
    if(it == v.end()){
        cout << "not find" << endl;
    }
    else{
        cout << "find:" << *it << endl;
    }
}

int main(){
//    test_1();
//    test_2();
//    test_3();
    test01();
}
