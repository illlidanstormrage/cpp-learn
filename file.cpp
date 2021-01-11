#include <iostream>
using namespace std;
#include <fstream>

// 文件类型分为两种：
//    1、文本文件-文件以文本的ASCII码形式储存在计算机
//    2、二进制文件-文件以文本的二进制形式储存在计算机中，用户一般不能直接读懂

// 操作文件的三大类：
//    1、ofstream: 写操作
//    2、ifstream: 读操作
//    3、fstream: 读写操作

// 写文件：
//    1、创建流对象 ofstream ofs;
//    2、打开文件 ofs.open("文件路径", 打开方式);
//    3、写数据 ofs << "写入的数据";
//    4、ofs.close()

// 文件打开方式:
//    ios::in     为读文件而打开文件
//    ios::out    为写文件而打开文件
//    ios::ate    初始位置：文件尾
//    ios::app    追加方式写文件
//    ios::trunc  如果文件存在先删除再创建
//    ios::binary 二进制方式

void test_1(){
    ofstream f;
    f.open("test.txt", ios::out);
    f << "name: zhang" << endl;
    f.close();
}

int main(){
    test_1();
}