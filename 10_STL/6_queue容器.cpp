#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
#include <string>
using namespace std;

class Person
{
public:
	Person(string name, int age) :m_Name(name), m_Age(age)
	{}

	string m_Name;
	int m_Age;
};

void test01()
{
	queue<Person>Q;

	Person p1("aaa",10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	//入队
	Q.push(p1);
	Q.push(p2);
	Q.push(p3);
	Q.push(p4);

	while ( !Q.empty())
	{
		//获取队头元素
		Person pFront =  Q.front();
		cout << "队头元素 姓名： " << pFront.m_Name << " 年龄： " << pFront.m_Age << endl;

		//获取队尾元素
		Person pBack = Q.back();
		cout << "队尾元素 姓名： " << pBack.m_Name << " 年龄： " << pBack.m_Age << endl;

		//出队
		Q.pop();
	}

	cout << "队列的大小为： " << Q.size() << endl;

}

int main(){

	test01();

	return 0;
}