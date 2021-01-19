#include <map>
#include <iostream>
using namespace std;

// pair对组
// 两种创建方式：
void test(){
    //  pair<type, type> p(value1, value2);
    pair<string, int> p1("tom", 20);
    cout << p1.first << " " << p1.second << endl;

    //  pair<type, type> p = make_pair(value1, value2);
    pair<string, int> p2 = make_pair("jerry", 20);
}

// map容器中的所有元素都是pair
// pair中第一个元素为key，起到索引作用，第二个元素为value
// 所有元素会根据元素的键值自动排序

// 本质: map/multimap属于关联式容器，底层结构用二叉树实现
// 优点：可以根据key值快速找到value值

// map和multimap区别：
//  map不允许容器中有重复的key值
//  multimap允许

void printMap(const map<int, int>& map){
    for(auto it = map.begin(); it!=map.end(); it++){
        cout << "key:" << it->first << "  " << "val:" << it->second << endl;
    }
    cout << endl;
}

// 构造
void test_1(){
    // map<T1, T2> mp;
    map<int, int> mp1;
    mp1.insert(pair<int, int>(1, 10));
    mp1.insert(pair<int, int>(2, 20));
    mp1.insert(pair<int, int>(3, 30));
    printMap(mp1);
    // map(const map &map);
    map<int, int> mp2(mp1);
    // map& operator=(const map &mp);
    map<int, int> mp3 = mp1;
}

// 大小和交换
void test_2(){
    map<int, int> mp1;
    mp1.insert(pair<int, int>(1, 10));
    mp1.insert(pair<int, int>(2, 20));
    mp1.insert(pair<int, int>(3, 30));

    map<int, int> mp2;
    mp2.insert(pair<int, int>(3, 10));
    mp2.insert(pair<int, int>(2, 20));
    mp2.insert(pair<int, int>(1, 30));

    // size(); //返回容器中元素的数目
    cout << mp1.size() << endl;

    // empty(); //判断容器是否为空
    cout << mp1.empty() << endl;

    // swap(st); //交换两个集合容器
    mp1.swap(mp2);
    printMap(mp1);
    printMap(mp2);
}

// 插入和删除
void test_3(){
    map<int, int> mp1;
    // insert(elem); //插入
    mp1.insert(pair<int, int>(1, 10));
    mp1.insert(pair<int, int>(2, 20));
    mp1.insert(pair<int, int>(3, 30));

    // erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器
    mp1.erase(mp1.begin());
    printMap(mp1);

    // erase(beg, end) //删除区间[beg, end)的所有元素，返回下一个元素的迭代器

    // erase(key); //删除容器中值为key的元素
    mp1.erase(2);
    printMap(mp1);

    // clear(); //清除所有元素

}

// map查找和统计
void test_4(){
    map<int, int> mp1;
    mp1.insert(pair<int, int>(1, 10));
    mp1.insert(pair<int, int>(2, 20));
    mp1.insert(pair<int, int>(3, 30));

    // find(key); //查找key是否存在，返回该键的元素迭代器；若不存在，返回set.end()；
    auto pos = mp1.find(4);
    cout << pos->first << endl;
    // count(key); //统计key的元素个数

}

// map容器排序
// map容器默认排序规则为 按照key值进行 从小到大的排序
// 利用仿函数可以改变排序规则
class MyCompare{
public:
    bool operator()(int v1, int v2){
        // 降序
        return v1>v2;
    }
};

void test_5(){
    map<int, int> mp1;
    mp1.insert(pair<int, int>(1, 10));
    mp1.insert(pair<int, int>(2, 30));
    mp1.insert(pair<int, int>(3, 20));
    printMap(mp1);

    // 加入仿函数
    map<int, int, MyCompare> mp2;
    mp2.insert(pair<int, int>(1, 10));
    mp2.insert(pair<int, int>(2, 30));
    mp2.insert(pair<int, int>(3, 20));
    for(auto it = mp2.begin(); it!=mp2.end(); it++){
        cout << "key:" << it->first << "  " << "val:" << it->second << endl;
    }
}


int main() {
//    test_1();
//    test_2();
//    test_3();
//    test_4();
//    test_5();
}