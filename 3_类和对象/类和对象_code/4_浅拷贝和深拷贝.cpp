#include <iostream>
#include <string.h>
using namespace std;

class Student
{
public:
	Student(int id, const char* name)
	{
		m_id = id;
		m_name = new char[20];
		strcpy(m_name, name);
	}
	~Student()
	{
		if (m_name != NULL)
		{
			delete[] m_name;
			m_name = NULL;
		}
		m_id = 0;
	}
	void print()
	{
		cout << "id:" << m_id << ", name:" << m_name << endl;
	}
	//复制堆上空间，进行深拷贝
	Student(const Student& obj)
	{
		m_id = obj.m_id;
		m_name = new char[20];
		strcpy(m_name, obj.m_name);
	}
private:
	int m_id;
	char *m_name;
};

int main()
{
	Student s1(1, "AAA");
	s1.print();

	Student s2 = s1;
	s2.print();

	return 0;
}