#include "person.h"

template<class T1, class T2>
class Person{
public:
    Person();
    Person(T1 name, T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};
