#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

// deque容器功能：双端数组，可以对头端进行插入和删除操作
// deque和vector区别:
// vector对于头部的插入删除效率低，数据量越大，效率越低
// deque相对而言，对头部的插入删除速度比vector快
// vector访问元素时的速度比deque快，这与两者内部实现有关

// deque内部工作原理：
// deque内部有一个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
// 中控器维护的每个缓冲区的地址，使得使用deque时像一片连续的内存空间
// deque的迭代器也支持随机访问

void printDeque(const deque<int>& d){
    for(int it : d){
        cout << it << " ";
    }
    cout << endl;
}

// 构造函数
void test_1(){
    // 默认构造
    deque<int> d1;
    for(int i=0; i<10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    // 构造函数将[beg, end]区间中的元素拷贝给本身
    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    // 构造函数将n个elem拷贝给本身
    deque<int> d3(10, 100);
    printDeque(d3);

    // 拷贝构造函数
    deque<int>d4 = d1;
    printDeque(d4);
}

// 赋值
void test_2(){
    deque<int> d1;
    for(int i=0; i<10; i++){
        d1.push_back(i);
    }
    // 重载=
    deque<int> d2 = d1;
    printDeque(d2);

    // 将[beg, end)区间中的数据拷贝赋值给本身
    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    // 将n个elem拷贝赋值给本身
    deque<int> d4;
    d4.assign(10, 10);
    printDeque(d4);
}

// 大小
void test_3(){
    deque<int> d1;
    for(int i=0; i<10; i++){
        d1.push_back(i);
    }
    // 判断是否为空
    cout << d1.empty() << endl;

    // 返回容器中元素的个数
    cout << d1.size() << endl;

    // 重新指定大小
    d1.resize(100);
    cout << d1.size() << endl;

    // 重新指定大小并将大的部分用x填充
    d1.resize(100, 1);
}

// 插入和删除
void test_4(){
    deque<int> d;
    for(int i=0; i<10; i++){
        // push_back(elem); //在容器尾部添加一个数据
        d.push_back(i);
    }
    printDeque(d);

    // push_front(elem); //在容器头部插入一个数据
    d.push_front(10);
    printDeque(d);

    // pop_back(elem); //删除容器最后一个数据
    d.pop_back();
    printDeque(d);

    // pop_front(elem); //删除容器第一个数据
    d.pop_front();
    printDeque(d);

    // insert(pos, elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置
    d.insert(d.begin(), 3);
    printDeque(d);

    // insert(pos, n, elem); //在pos位置插入n个elem数据，无返回值
    d.insert(d.begin(), 2, 10000);
    printDeque(d);

    // insert(pos, beg, end); //在pos位置插入[beg, end]区间的数据，无返回值
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d.insert(d.begin(), d2.begin(), d2.end());
    printDeque(d);

    // erase(beg, end); //删除[beg, end)区间的数据，无返回值

    // erase(pos); //删除pos位置的数据，返回下一个数据的位置
    auto it = d.begin();
    it++;
    d.erase(it);
    printDeque(d);

    // clear(); //清除容器中的所有数据
}

// deque数据存取
void test_5(){
    deque<int> d;
    for(int i=0; i<10; i++){
        d.push_back(i);
    }
    // at(int idx); //返回索引idx所指的数据
    cout << d.at(1) << endl;

    // operator[]; //返回索引idx所指的数据
    cout << d[2] << endl;

    // front(); //返回容器中第一个数据元素
    cout << d.front() << endl;

    // back(); //返回容器中最后一个数据元素
    cout << d.back() << endl;
}

// deque排序
void test_6(){
    deque<int> d;
    for(int i=0; i<10; i++){
        d.push_back(100-i);
    }
    // sort(iterator beg, iterator end); //对beg和end区间内元素进行排序
    sort(d.begin(), d.end());
    printDeque(d);
}

int main(){
//    test_1();
//    test_2();
//    test_3();
//    test_4();
//    test_5();
    test_6();
}
