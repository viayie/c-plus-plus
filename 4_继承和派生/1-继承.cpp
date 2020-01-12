#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student(int id, string name)
	{
		this->id = id;
		this->name = name;
	}
	void dis()
	{
		cout << "id:" << id << ", name:" << name << endl;
	}
private:
	int id;
	string name;
};

//ผฬณะ
class Student1 :Student
{
public:
	Student1(int id, string name, int score):Student(id, name)
	{
		this->score = score;
	}
	void dis()
	{
		Student::dis();
		cout << "score: " << score << endl;
	}
private:
	int score;
};


int main()
{
	Student s1(22, "zhang3");
	s1.dis();

	Student1 s2(23, "li4", 90);
	s2.dis();

	return 0;
}