// 用成员函数和全局函数分别判断两个立方体对象是否相等，并计算体积和表面积

#include <iostream>
using namespace std;

class Cube{
public:
    void set_length(double length){
        m_L = length;
    }

    void set_width(double width){
        m_W = width;
    }

    void set_height(double height){
        m_H = height;
    }

    double get_width() const{
        return m_W;
    }

    double get_height() const{
        return m_H;
    }

    double get_length() const{
        return m_L;
    }

    double get_area() const{
        return (m_L * m_H + m_L * m_W + m_H * m_W)*2;
    }

    double get_volume() const{
        return m_L * m_H * m_W;
    }

    void is_same(Cube &cube) const{
        if(m_H==cube.get_height() && m_W==cube.get_width() && m_L==cube.get_length()){
            cout << "cube1 and cube2 are the same" << endl;
        }
        else{
            cout << "not the same" << endl;
        }
    }
private:
    double m_H;
    double m_L;
    double m_W;
};

// 全局函数判断两个立方体是否相等
void is_Same(Cube &c1, Cube &c2){
    if(c1.get_length()==c2.get_length() && c1.get_height()==c2.get_height() && c1.get_width()==c2.get_width()){
        cout << "cube1 and cube2 are the same" << endl;
    }
    else{
        cout << "not the same" << endl;
    }
}

int main(){
    Cube cube1{};
    Cube cube2{};
    cube1.set_height(12.2);
    cube1.set_length(12.2);
    cube1.set_width(11.2);
    cube2.set_height(12.2);
    cube2.set_length(12.2);
    cube2.set_width(11.2);

    cout << "cube1 volume:" << cube1.get_volume() << " area:" << cube1.get_area() << endl;
    cout << "cube2 volume:" << cube2.get_volume() << " area" << cube2.get_area() << endl;

    is_Same(cube1, cube2);
    cube1.is_same(cube2);
}