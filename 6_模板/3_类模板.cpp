#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType=int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        m_name = name;
        m_age = age;
    }
private:
    NameType m_name;
    AgeType m_age;
};

void test()
{
    Person<string> p("Tom", 11);
}

int main()
{
    test();
    return 0;
}