//
// Created by illlidan on 2021/1/8.
//

#include <iostream>
using namespace std;
#include <string>

// 友元的目的是让一个函数或者类访问另一个类中的私有成员
// 友元的关键字为friend

// 友元的三种实现：
//    全局函数做友元
//    类做友元
//    成员函数做友元

class Building{
    friend void good_friend(Building *building); //good_friend()是Building的好友，能够访问其私有成员
    friend class Friend; //将Friend类作为好友
public:
    Building();
    string m_sittingroom; //客厅
private:
    string m_bedroom; //卧室
};

// 类外写成员函数
Building::Building(){
    m_sittingroom = "sittingroom";
    m_bedroom = "bedroom";
}

// 全局函数
void good_friend(Building *building){
    cout << "friend is visiting " << building->m_sittingroom << endl;
    cout << "friend is visiting " << building->m_bedroom << endl;
}

void test_1(){
    Building My_friend;
    good_friend(&My_friend);
}

// 类
class Friend{
public:
    Friend(){
        // 创建Building对象
        building = new Building;
    }

    void visit() const{ //参观函数，访问Building中的属性
        cout  << "a friend is visiting " << building->m_sittingroom << endl;
        cout  << "a friend is visiting " << building->m_bedroom << endl;
    }

    Building *building;
};

void test_2(){
    Friend My_friend{};
    My_friend.visit();
}

int main(){
//    test_1();
//    test_2();
}