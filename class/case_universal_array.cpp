#include <iostream>
using namespace std;

// 实现一个通用的数组类
// 可以对内置数据类型以及自定义数据类型的数据进行储存
// 将数组中的数据储存到堆区
// 构造函数中可以传入数组的容量
// 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
// 提供尾插法和尾删法对数组中的数据进行增加和删除
// 可以通过下标的方式访问数组中的元素
// 可以获取数组中当前元素个数和数组的容量

template<class T>
class MyArray{
    friend ostream& operator<<(ostream &out, MyArray<T>& p){
        out << "Capacity:" << p.m_Capacity << endl;
        out << "Size:" << p.m_Size << endl;
        out << "Content:" << endl;
        for(int i=0; i<p.m_Size; i++){
            out << "index " << i << ": " << p.pAddress[i] << endl;
        }
        return out;
    }

public:
    MyArray() = default;

    // 有参构造
    explicit MyArray(int capacity){
        cout << "construct with parament" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // 深拷贝
    MyArray(const MyArray& arr){
        cout << "construct with copy" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for(int i=0; i<arr.m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // operate= 深拷贝
    MyArray& operator=(const MyArray& arr){
        cout << "operate =" << endl;
        //先判断原先堆区是否有数据，如果有先释放
        if(this->pAddress != nullptr){
            delete[] this->pAddress;
            this->pAddress = nullptr;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for(int i=0; i<arr.m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    // 析构
    ~MyArray(){
        if(pAddress != nullptr){
            delete pAddress;
            pAddress = nullptr;
        }
        cout << "destroy" << endl;
    }

    // 尾插法
    void push(const T& val){
        //判断容量是否等于大小
        if(this->m_Capacity == this->m_Size){
            cout << "already full" << endl;
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    // 尾删法
    T pop(){
        if(this->m_Size == 0){
            cout << "no data!" << endl;
            return 0;
        }
        T temp;
        return this->pAddress[--this->m_Size];
    }

    // 通过下标访问
    T& operator[](int index){
        return this->pAddress[index];
    }

    // 返回数组容量
    int getCapacity(){
        return this->m_Capacity;
    }

    // 返回当前占用空间
    int getSize(){
        return this->m_Size;
    }

private:
    T *pAddress; //指针指向堆区开辟的真实数组
    int m_Capacity{};
    int m_Size{};
};

void test(){
    MyArray<int> arr1(5);
    for(int i=0; i<5; i++){
        arr1.push(i);
    }
    cout << arr1 << endl;
    cout << arr1.pop() << endl;
    cout << arr1 << endl;
}

int main(){
    test();

    return 0;
}