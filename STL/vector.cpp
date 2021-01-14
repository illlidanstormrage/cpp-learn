#include <vector>
#include <iostream>
using namespace std;

// vector数据结构和数组非常相似，也称为单端数组
// 不同之处：数组是静态控件，vector可以动态扩展
// 动态扩展：并不是在原空间之后续新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间

void printVector(vector<int>& v){
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << "  ";
    }
    cout << endl;
}

// 创建vector容器
void test_1(){
    // vector<T> v; //默认构造函数
    vector<int>v1;
    for(int i=0; i<10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    // vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本容器
    vector<int>v2(v1.begin(), v1.end());
    printVector(v2);

    // vector(n, elem); //构造函数将n个elem拷贝给本身
    vector<int>v3(10, 100);
    printVector(v3);

    // vector(const vector& vec); //拷贝构造
    vector<int>v4(v3);
    printVector(v4);

}

// 给vector容器进行赋值
void test_2(){
    vector<int>v1;
    for(int i=0; i<10; i++){
        v1.push_back(i);
    }
    // vector& operator=(const vector& vec);
    vector<int> v2 = v1;
    printVector(v2);

    // assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身
    vector<int>v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    // assign(n, elem); //将n个elem拷贝赋值给本身
    vector<int>v4;
    v4.assign(10, 1);
    printVector(v4);
}

// vector容量和大小
void test_3(){
    vector<int>v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    // empty(); //判断容器是否为空
    cout << v.empty() << endl;

    // capacity(); //容器的容量
    cout << v.capacity() << endl;

    // size(); //容器中元素的个数
    cout << v.size() << endl;

    // resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置；若容器变短，则末尾超出容器长度的元素被删除
    v.resize(9);
    printVector(v);

    // resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置；若容器变短，则末尾超出容器长度的元素被删除
    v.resize(10, 50);
    printVector(v);
}

// vector插入和删除
void test_4(){
    vector<int> v;
    for(int i=0; i<10; i++){
    // push_back(ele); //尾部插入元素ele
        v.push_back(i);
    }
    printVector(v);

    // pop_back(); //删除最后一个元素
    v.pop_back();
    printVector(v);

    // insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
    v.insert(v.begin(), 10);
    printVector(v);

    // insert(const_iterator pos, int count, ele); //迭代器指向位置pos插入count个元素ele
    v.insert(v.begin(), 3, 0);
    printVector(v);

    // erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
    v.erase(v.begin());
    printVector(v);

    // erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
    v.erase(v.begin(), v.end()-1);
    printVector(v);

    // clear(); //删除容器中所有元素
    v.clear();
    printVector(v);
}

// vector数据存取
void test_5(){
    vector<int>v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    // at(int idx); //返回索引idx所指的数据
    cout << v.at(2) << endl;

    // operator[]; //返回索引idx所指的数据
    cout << v[2] << endl;

    // front(); //返回容器中第一个数据元素
    cout << v.front() << endl;

    // back(); //返回容器中最后一个数据元素
    cout << v.back() << endl;
}

// vector互换容器
void test_6(){
    vector<int>v1;
    for(int i=0; i<10; i++){
        v1.push_back(i);
    }

    vector<int>v2;
    for(int i=0; i<10; i++){
        v2.push_back(10-i);
    }
    printVector(v1);
    printVector(v2);

    // swap(vec);
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

// vector预留空间
void test_7(){
    vector<int> v;
    // reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问
    v.reserve(100);
    cout << v.capacity() << endl;
}


int main(){
//    test_1();
//    test_2();
//    test_3();
//    test_4();
//    test_5();
//    test_6();
//    test_7();
}


