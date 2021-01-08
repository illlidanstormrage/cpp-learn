#include <iostream>
#include <utility>
using namespace std;
#include <string>

// 1、new的基本用法
void test_1(){
    int *p = new int(10);
    int *arr = new int[10]; //10代表数组有10个元素
    for(int i=0; i<10; i++){
        arr[i] = i + 100;
    }
    cout << *p << endl;
    for(int i=0; i<10; i++){
        cout << arr[i] <<endl;
    }
    delete[] arr;
}

// 2、引用：给变量起别名
// 语法：数据类型 &别名 = 原名
void test_2_1(){
    int a = 10;
    int &b = a;
    cout << "a=" << a << " b=" << b << endl;
    b = 20;
    cout << "a=" << a << " b=" << b << endl;
}

// 引用必须初始化、引用在初始化后不可以改变
void test_2_2(){
//    int &b; //错误用法
    int a = 10;
    int &b = a;
    cout << "a=" << a << " b=" << b << endl;
    int c = 20;
    b = c; //赋值操作，不是修改引用
    cout << "a=" << a << " b=" << b << endl;
}

// 函数传参时，可以用引用计数让形参修饰实参，可以简化指针修改实参
void my_swap_1(int a, int b){ //值传递，形参不会修饰实参
    int temp = a;
    a = b;
    b = temp;
}

void my_swap_2(int *a, int *b){ //地址传递，形参会修饰实参
    int temp = *a;
    *a = *b;
    *b = temp;
}

void my_swap_3(int &a, int &b){ //引用传递，形参会修饰实参
    int temp = a;
    a = b;
    b = temp;
}

void test_2_3(){
    int a = 10;
    int b = 20;
    my_swap_1(a, b);
    cout << "a=" << a << " b=" << b << endl;
    my_swap_2(&a, &b);
    cout << "a=" << a << " b=" << b << endl;
    my_swap_3(a, b);
    cout << "a=" << a << " b=" << b << endl;
}

// 引用做函数返回值
// 1、不要返回局部变量的引用
// 2、函数的调用可以作为左值
int& func_test_2_4(){
    static int a = 10;
    return a;
}

void test_2_4(){
    int &ref = func_test_2_4();
    cout << "ref=" << ref << endl;
    func_test_2_4() = 1000;
    cout << "ref=" << ref << endl;
}

// 引用的本质在c++内部实现是一个指针常量
void func_test_2_5(int& ref){
    ref = 100;
}

void test_2_5(){
    int a = 10;
    int& ref = a; //自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
    ref = 20; //内部发现ref是引用，会自动转化为 *ref = 20;
    cout << "a=" << a << " ref=" << ref << endl;
    func_test_2_5(a);
    cout << "a=" << a << " ref=" << ref << endl;
}

// 常量引用
// 使用场景：用来修饰形参，防止误操作
void showValue_1(int& val){
    cout << "val=" << val << endl;
    val = 1000;
    cout << "val=" << val << endl;
}

void showValue_2(const int& val){ //将val变为只读，对val修改时会报错
//    val = 1000;
    cout << "val=" << val << endl;
}

void test_2_6(){
//    const int& ref = 10; //加上const之后，编译器将代码修改为 int temp = 10; const int& ref = temp;
//    ref = 20; //加入const之后变为只读，不可以修改
    int a = 100;
    showValue_1(a);
    showValue_2(a);
}

// 3、函数提高
//函数默认参数
//语法： 返回值类型 函数名（参数=默认值）{}
int func_test_3_1(int a, int b=20, int c=30){
    return a + b + c;
}

void test_3_1(){
    int res_1 = func_test_3_1(10,20, 30);
    int res_2 = func_test_3_1(10,30);
    cout << "res_1=" << res_1 << " res_2=" << res_2 << endl;
}
// 注意事项：
// 1、如果某个位置已经有了默认参数，那么从这个位置往后都必须有默认值
// 2、如果函数声明有默认参数，函数实现就不能有默认参数
int func_test_3_2(int a=10, int b=10);
//int func_test_3_2(int a=10, int b=10){
//    return 0;
//}//会出现二义性，有报错

// 函数占位参数
// 语法：返回值类型 函数名(数据类型){}
// 占位参数可以有默认参数，占位参数必须填补
void func_test_3_3(int a, int){
    cout << "this is func" << endl;
}

void test_3_3(){
    func_test_3_3(10, 10);
}

// 函数重载
// 函数名可以相同，提高复用性
// 条件：在同一个作用域下、函数名称相同、函数参数类型不同或个数不同或顺序不同
void func_test_3_4(int a1){
    cout << "first" << endl;
}

void func_test_3_4(double a2){
    cout << "second" << endl;
}

void func_test_3_4(int a3, int b){
    cout << "third" << endl;
}

void test_3_4(){
    func_test_3_4(1);
    func_test_3_4(1.0);
    func_test_3_4(1, 2);
}
// 重载注意事项
// 1、引用作为重载条件
// 2、函数重载碰到默认参数
void func_test_3_5(int& a1){ //int &a = 10; 不合法
    cout << "first" << endl;
}

void func_test_3_5(const int& a2){ //const int &a = 10; 合法
    cout << "second" << endl;
}

void func_test_3_5(int a1, int b1){
    cout << "int a" << endl;
}

void func_test_3_5(int a2, int b2, int c=10){
    cout << "int a=10" << endl;
}
void test_3_5(){
    int a = 10;
    func_test_3_5(a);
    func_test_3_5(10);
//    func_test_3_5(1,1); //调用的时候会出线二义性，定义函数时不会出错
}

// 4、类和对象
// C++面向对象三大特性：封装、继承、多态
// 例子
const double PI = 3.14;
class Person{
    //访问权限有
    // 公共public      成员  类内可以访问  类外可以访问    子类可以访问
    // 保护protected   成员  类内可以访问  类外不可以访问  子类可以访问
    // 私有private     成员  类内可以访问  类外不可以访问  子类不能访问
public:
    // 类中的属性和行为 统一称为成员
    // 属性 成员属性、成员变量
    string m_name;
    // 行为 成员函数、成员方法
    void func(){
        m_name = "tom";
        m_car = "benz";
        m_password = 123456;
    }
protected:
    string m_car;

private:
    int m_password{};
};

void test_4_1(){
    //通过类创建对象，实例化
    Person tom;
//    tom.m_car; //m_car为protected，类外不能访问
    tom.m_name = "tom";
//    tom.m_password; //m_password为private，类外不能访问

}

// 成员属性设置为私有
class Person_{
public:
    static void set_name(const string& name){
        m_name = name;
    } //设置年龄

    static string get_name(){
        return m_name;
    } //获取年龄

    int get_age() const{
        return m_age;
    } //获取年龄

    void set_lover(const string& lover) {
        m_lover = lover;
    } //设置情人

private:
    static string m_name; //可读可写
    int m_age; //只读
    string m_lover; //只写

};

//

int main(){
//    test_1();
//    test_2_1();
//    test_2_2();
//    test_2_3();
//    test_2_4();
//    test_2_5();
//    test_2_6();
//    test_3_1();
//    test_3_3();
//    test_3_4();
//    test_4_1();

}
