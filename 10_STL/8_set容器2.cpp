#include <iostream>
#include <set>

using namespace std;

//判断是否插入成功
//insert返回对组，pair<iterator, bool>
void test01()
{
    set<int> s;
    s.insert(10);
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if(ret.second){
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }
}

//利用仿函数 指定set容器的排序规则
class MyCompare
{
public:
    bool operator() (int v1, int v2)
    {
        return v1 < v2;
    }
};
void test02()
{
    set<int, MyCompare> s;
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(50);
    s.insert(70);

    for(set<int, MyCompare>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// //自定义数据类型
// class Person
// {
// public:
//     Person(string name, int age)
//     {
//         this->m_name = name;
//         this->m_age = age;
//     }
//     string m_name;
//     int m_age;
// };
// class MyComparePerson
// {
// public:
//     bool operator()(const Person &p1, const Person &p2)
//     {
//          return p1.m_age < p2.m_name;
//     }
// };
// void test03()
// {
// 	set<Person, MyComparePerson> s;

// 	Person p1("aaa", 10);
// 	Person p2("bbb", 30);
// 	Person p3("ccc", 20);
// 	Person p4("ddd", 50);
// 	Person p5("eee", 40);

// 	s.insert(p1);
// 	s.insert(p2);
// 	s.insert(p3);
// 	s.insert(p4);
// 	s.insert(p5);

// 	//对于自定义数据类型，必须指定排序规则
// 	for (set<Person,MyComparePerson>::iterator it = s.begin(); it != s.end(); it++)
// 	{
// 		cout << "姓名： " << (*it).m_name << " 年龄： " << it->m_age << endl;
// 	}

// }

class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

class MyComparePerson
{
public:
	bool operator()(const  Person & p1 , const Person & p2)
	{
		//年龄 升序
		return p1.m_Age < p2.m_Age;
	}

};

void test03()
{
	set<Person, MyComparePerson> s;

	Person p1("aaa", 10);
	Person p2("bbb", 30);
	Person p3("ccc", 20);
	Person p4("ddd", 50);
	Person p5("eee", 40);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	//对于自定义数据类型，必须指定排序规则
	for (set<Person,MyComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << endl;
	}

}
int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}