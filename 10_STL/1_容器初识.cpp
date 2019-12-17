#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void myPrint(int val)
{
    cout << val << " ";
}

/*内置数据类型*/
void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //第一种遍历方式
    //v.end()指向最后一个元素的下一个元素
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //第二种遍历方式
    for_each(v.begin(), v.end(), myPrint);//参数3 回调函数

}

/*自定义数据类型*/
class Person
{
public:
    Person(string name, int age){
        m_name = name;
        m_age = age;
    }
    string m_name;
    int m_age;
};
void test02()
{
    vector<Person> v;

    Person p1("aaa", 1);
    Person p2("bbb", 2);
    Person p3("ccc", 3);
    Person p4("ddd", 4);
    Person p5("eee", 5);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << (*it).m_name << ", ";//*it 的数据类型 就是 尖括号里的数据类型
        cout << it->m_age << endl;
    } 
}

/*自定义数据类型指针*/
void test03()
{
    vector<Person*> v;

    Person p1("aaa", 1);
    Person p2("bbb", 2);
    Person p3("ccc", 3);
    Person p4("ddd", 4);
    Person p5("eee", 5);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++){
        cout << (*it)->m_name << ", ";//*it 的数据类型是 Person*
        cout << (*it)->m_age << endl;
    } 
}

/*容器嵌套容器*/
void test04()
{
    vector< vector<int> > v;//大容器，类似二维数组

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    //初始化小容器
    for(int i=0; i<5; i++){
        v1.push_back(i);
        v2.push_back(i+10);
        v3.push_back(i+100);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++){
        for(vector<int>::iterator vit = (*it).begin(); vit!=(*it).end(); vit++){
            cout << *vit << ", ";
        }
        cout << endl;
    }
}

int main()
{
    test04();

    return 0;
}