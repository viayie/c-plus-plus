#include <iostream>

using namespace std;

//重新解释转换  最不安全 不建议用
class Base
{
	virtual void func(){};
};
class Son :public Base
{
	virtual void func(){};
};
class Other
{};
void test()
{
	int a = 10;
	int * p = reinterpret_cast<int*>(a);

	//将base* 转为 Other * 
	Base * base = NULL;
	Other * other = reinterpret_cast<Other *>(base);
}
int main()
{


	return 0;
}