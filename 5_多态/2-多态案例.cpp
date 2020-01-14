#include <iostream>
#include <string>
using namespace std;

//�����������
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}

	int m_a;
	int m_b;
};

//�ӷ���������
class AddCalculator:public AbstractCalculator
{
	int getResult()
	{
		return m_a + m_b;
	}
};

//������������
class SubCalculator:public AbstractCalculator
{
	int getResult()
	{
		return m_a - m_b;
	}
};

int main()
{
	AbstractCalculator *calculator = new AddCalculator;
	calculator->m_a = 10;
	calculator->m_b = 20;
	cout << calculator->getResult() << endl;

	delete calculator;

	calculator = new SubCalculator;
	calculator->m_a = 10;
	calculator->m_b = 20;
	cout << calculator->getResult() << endl;

	return 0;
}