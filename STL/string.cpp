// string是C++风格的字符串，本质上是一个类

// string 和 char* 的区别
// char*是一个指针
// string是一个类，类内部封装了char*来管理这个字符串，是一个char*的容器

#include <string>
#include <iostream>
using namespace std;

// string构造函数
void test_1(){
    // string() //创建一个空的字符串 如：string str;
    string s1;
    const char *str = "hello world";

    // string(const char* s) //使用字符串s初始化
    string s2(str);
    cout << "s2=" << s2 << endl;

    // string(const string& str) //使用一个string对象初始化另一个string对象
    string s3(s2);
    cout << "s3=" << s3 << endl;

    // string(int n, char c) //用n个字符c初始化
    string s4(10, 'a');
    cout << "s4=" << s4 << endl;
}

// 赋值函数
void test_2(){
    // string& operator=(const char* s); //char*类型字符串赋值给当前字符串
    string str1;
    str1 = "hello world";
    cout << "str1=" << str1 << endl;

    // string& operator=(const string &s); //把字符串s赋给当前的字符串
    string str2;
    str2 = str1;
    cout << "str2=" << str2 << endl;

    // string& operator=(char c); //字符赋值给当前字符串
    string str3;
    str3 = '3';
    cout << "str3=" << str3 << endl;

    // string& assign(const char* s); //把字符串s赋给当前的字符串
    string str4;
    char *s4 = "4";
    str4.assign(s4);
    cout << "str4=" << str4 << endl;

    // string& assign(const char*s, int n) //把字符串s的前n个字符赋给当前的字符串
    string str5;
    str5.assign("hello world", 5);
    cout << "str5=" << str5 << endl;

    // string& assign(const string &s); //把字符串s赋给当前字符串
    string str6;
    str6.assign(str5);
    cout << "str6=" << str6 << endl;

    // string& assign(int n, char c); //用n个字符c赋给当前字符串
    string str7;
    str7.assign(10, 'w');
    cout << "str7=" << str7 << endl;
}

// string字符串拼接
void test_3(){
    // string& operator+=(const char* str); //重载+=操作符
    string str1 = "I ";
    str1 += "like to play 1";
    cout << "str1=" << str1 << endl;

    // string& operator+=(const char c); //重载+=操作符
    string str2 = str1;
    str2 += 'c';
    cout << "str2=" << str2 << endl;

    // string& operator+=(const string& str);
    string str3 = str2;
    str3 += str2;
    cout << "str3=" << str3 << endl;

    // string& append(const char *s); //把字符串s连接到当前字符串结尾
    string str4 = str3;
    char *s4 = "hehe";
    str4.append(s4);
    cout << "str4=" << str4 << endl;

    // string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾
    string str5 = str4;
    str5.append(s4, 2);
    cout << "str5=" << str5 << endl;

    // string& append(const string& s); //同operator+=(const string& str);
    string str6 = str5;
    str6.append(str5);
    cout << "str6=" << str6 << endl;

    // string& append(const string& s, int pos, int n); //字符串s中从pos到n的字符连接到字符串结尾
    string str7 = str6;
    str7.append(str6, 2, 6);
    cout << "str7=" << str7 << endl;
}

// string查找和替换
// 查找：查找指定字符串是否存在
// 替换：在指定的位置替换字符串
void test_4(){
    // int find(const string& str, int pos = 0) const; //查找str第一次出现的位置，从pos开始查找
    string str = "abcdedefg";
    int pos1 = str.find("de");
    cout << pos1 << endl;

    // int find(const char* s, int pos = 0) const; //查找s第一次出现的位置，从pos开始查找

    // int find(const char* s, int pos, int n) const //从pos位置查找s的前n个字符第一次位置

    // int find(const char c, int pos = 0) const; //查找字符c第一次出现的位置

    // int rfind(const string& str, int pos = npos) const; //查找str最后一次出现的位置，从pos开始查找
    int pos2 = str.rfind("de");
    cout << pos2 << endl;

    // int rfind(const char* s, int pos = npos) const; //查找s最后一次出现的位置，从pos开始查找

    // int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置

    // int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现的位置

    // string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
    str.replace(1, 3, "1111");
    cout << str << endl;
    // string& replace(int pos, int n, const char*s); //替换从pos开始的n个字符串为字符串s

}

// string字符串比较
void test_5(){
    string str1 = "abcdefg";
    string str2 = "abcdefga";
    char *s = "abcdefgb";
    // int compare(const string& s) const; //与字符串s比较
    cout << str2.compare(str1) << endl;

    // int compare(const char *s) const;
    cout << str2.compare(s) << endl;

}

// string字符存取
void test_6(){
    string str = "abcdefg";
    // char& operator[](int n); //通过[]方式取字符
    cout << str[2] << endl;

    // char& at(int n); //通过at方法获取字符
    cout << str.at(2) << endl;

}

// string插入和删除
void test_7(){
    string str = "abcdefg";
    // string& insert(int pos, const char* s); //插入字符串
    char* s = "11";
    str.insert(0, s);
    cout << str << endl;

    // string& insert(int pos, const string& str);
    string str2 = "12";
    str.insert(0, str2);
    cout << str << endl;

    // string& insert(int pos, int n, char c); //在指定位置插入n个字符c
    str.insert(0, 2, 'n');
    cout << str << endl;

    // string& erase(int pos, int n = npos); //删除从pos开始的n个字符
    str.erase(0, 2);
    cout << str << endl;
}

// string子串
void test_8(){
    string str = "abcdefg";
    // string substr(int pos = 0; int n = npos) const; //返回由pos开始的n个字符
    string sub = str.substr(1, 3);
    cout << sub << endl;
}

int main(){
//    test_1();
//    test_2();
//    test_3();
//    test_4();
//    test_5();
//    test_6();
//    test_7();
    test_8();
}