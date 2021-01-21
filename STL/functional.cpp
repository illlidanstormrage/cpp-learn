#include <iostream>
using namespace std;
#include <functional>
#include <vector>
#include <algorithm>

// STL内建了一些函数对象
// 分类：算数仿函数、关系仿函数、逻辑仿函数
// 这些仿函数产生的对象，用法和一般函数完全相同

// 算数仿函数
void test_1(){
    // template<class T> T plus<T> //加法仿函数
    plus<int> p;
    cout << p(10, 10) << endl;
    // template<class T> T minus<T> //减法仿函数

    // template<class T> T multiplies<T> //乘法仿函数

    // template<class T> T divide<T> //除法仿函数

    // template<class T> T modulus<T> //取模仿函数

    // template<class T> T negate<T> //取反仿函数，为一元运算
    negate<int> n;
    cout << n(50) << endl;
}

// 关系仿函数
class MyCompare{
public:
    bool operator()(int a, int b){
        return a>b;
    }
};

void test_2(){
    // template<class T> bool equal_to<T> //等于

    // template<class T> bool not_equal_to<T> //不等于

    // template<class T> bool greater<T> //大于
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);
    for(int& it : v){
        cout << it << " ";
    }cout << endl;
//    sort(v.begin(), v.end(), MyCompare());
    sort(v.begin(), v.end(), greater<int>());
    for(int& it : v){
        cout << it << " ";
    }
    cout << endl;
    // template<class T> bool greater_equal<T> //大于等于

    // template<class T> bool less<T> //小于

    // template<class T> bool less_equal<T> //小于等于

}

// 逻辑仿函数
void test_3(){
    vector<bool> v;
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    for(bool&& it : v){
        cout << it << " ";
    }cout << endl;
    // template<class T> bool logical_and<T> //与

    // template<class T> bool logical_or<T> //或

    // template<class T> bool logical_not<T> //非
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for(bool&& it: v2){
        cout << it << " ";
    }cout << endl;
}

int main(){
//    test_1();
//    test_2();
    test_3();
}
