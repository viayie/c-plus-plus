#include <iostream>
using namespace std;

class Student
{
public:
	Student(const char *name, int score):m_name(name), m_score(score)
	{
		count++;
		sum += m_score;
	}
	static float average();
private:
	int m_score;
	const char* m_name;
	static int count;
	static float sum;
};

int Student::count = 0;
float Student::sum = 0;
float Student::average()
{
	return sum / count;
}

int main()
{
	Student stu1("AAA", 67);
	Student stu2("BBB", 89);
	Student stu3("CCC", 93);

	cout << Student::average() << endl;

	return 0;
}