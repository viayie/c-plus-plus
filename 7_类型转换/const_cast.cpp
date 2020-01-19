#include <iostream>

using namespace std;

void test01()
{
	const int *p = NULL;

	//将 const int * 转为 int *
	int *p2 = const_cast<int*>(p);

	//将 p2 转为  const int * 
	const int *p3 = const_cast<const int *>(p2);

	//引用之间的转换
	const int a = 10;
	const int &aRef = a;
	int &aRef2 = const_cast<int &>(aRef);
	const int &aRef3 = const_cast<const int &>(aRef2);

	//不可以对非指针 或者 非引用 做const_cast转换
	//int b = const_cast<int>(a);
}
int main()
{
	test01();
}