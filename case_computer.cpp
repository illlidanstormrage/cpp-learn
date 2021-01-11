#include <iostream>
using namespace std;

// 创建CPU类
class CPU{
public:
    virtual void calculate() = 0;
};

// 创建显卡类
class VideoCard{
public:
    virtual void display() = 0;
};

// 创建内存类
class Memory{
public:
    virtual void storage() = 0;
};

// 创建电脑类
class Computer{
public:
    Computer()= default;

    Computer(CPU *cpu, VideoCard *video_card, Memory *memory){
        m_cpu = cpu;
        m_video_card = video_card;
        m_memory = memory;
    }

    ~Computer(){
        if(m_cpu != nullptr){
            delete m_cpu;
            m_cpu = nullptr;
        }
        if(m_video_card != nullptr){
            delete m_video_card;
            m_video_card = nullptr;
        }
        if(m_memory != nullptr){
            delete m_memory;
            m_memory = nullptr;
        }
    }

    // 提供工作函数
    void work(){
        m_cpu->calculate();
        m_video_card->display();
        m_memory->storage();
    }

private:
    CPU *m_cpu{}; //CPU零件指针
    VideoCard *m_video_card{}; //显卡零件指针
    Memory *m_memory{}; //内存条零件指针
};

// 具体厂商
// Intel
class IntelCPU: public CPU{
public:
    void calculate() override{
        cout << "IntelCPU work" << endl;
    }
};

class IntelVideoCard: public VideoCard{
public:
    void display() override{
        cout << "IntelVideoCard work" << endl;
    }
};

class IntelMemory: public Memory{
public:
    void storage() override{
        cout << "IntelMemory work" << endl;
    }
};

// Lenovo
class LenovoCPU: public CPU{
public:
    void calculate() override{
        cout << "LenovoCPU work" << endl;
    }
};

class LenovoVideoCard: public VideoCard{
public:
    void display() override{
        cout << "LenovoVideoCard work" << endl;
    }
};

class LenovoMemory: public Memory{
public:
    void storage() override{
        cout << "LenovoMemory work" << endl;
    }
};

void test_1(){
    //创建第一台电脑
    Computer *computer1 = new Computer(new IntelCPU, new IntelVideoCard, new IntelMemory);
    computer1->work();
    delete computer1;

    //创建第二台电脑
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
    computer2->work();
    delete computer2;
}

int main(){
    test_1();
}