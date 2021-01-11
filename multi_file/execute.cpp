// 类模板中的成员函数不会在执行前创建，导致在链接时找不到函数
// 第一种解决方法：直接包含源文件
#include "person.cpp"

// 第二种解决方法：将.h和.cpp中的内容写到一起,将后缀名改为.hpp

// 模板类内成员函数的类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
    this->m_Name = name;
    this->m_Age = age;
};

template<class T1, class T2>
void Person<T1, T2>::showPerson(){
    cout << "name:" << this->m_Name << " age:" << this->m_Age << endl;
}

void test_1(){
    Person<string, int>p("Jerry", 18);
    p.showPerson();
}

int main(){
    test_1();
}