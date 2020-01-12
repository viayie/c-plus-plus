#include <iostream>

using namespace std;

class Array
{
public:
	Array(int len=0)
	{
		if (len <= 0)
		{
			m_p = NULL;
			m_len = 0;
		}
		else
		{
			m_p = new int[len];
			m_len = len;
		}	
	}
	Array(const Array& a)
	{
		if (a.m_len == 0)
		{
			this->m_len = 0;
			this->m_p = NULL;
		}
		else
		{
			m_len = a.m_len;
			m_p = new int[a.m_len];

			for (int i = 0; i < m_len; i++)
			{
				m_p[i] = a.m_p[i];
			}
		}
	}
	~Array()
	{
		if (m_p != NULL)
		{
			delete[] m_p;
		}
		m_p = NULL;
		m_len = 0;
	}
public:
	int& operator[](int i)//访问+修改元素
	{
		return m_p[i];
	}
	const int& operator[](int i) const//只能访问
	{
		return m_p[i];
	}
public:
	int len() const
	{
		return m_len;
	}
	void dis() const
	{
		for (int i = 0; i < m_len; i++)
		{
			if (i == m_len - 1)
				cout << m_p[i] << endl;
			else
				cout << m_p[i] << ", ";
		}
	}
private:
	int m_len;//数组长度
	int* m_p;//数组空间
};

int main()
{
	int n;
	cin >> n;

	Array A(n);
	for (int i = 0, len = A.len(); i < len; i++)
	{
		A[i] = i * 5;
	}
	A.dis();

	const Array B(n);
	cout << B[n - 1] << endl;//访问最后一个元素

	return 0;

}

