#include <iostream>

using namespace std;

//内置数据类型转换
void test01()
{
	char c = 'c';
	double d = static_cast<double>(c);
	cout << d << endl;

}
//自定义数据类型
class Base
{

};
class Son:public Base
{

};
class Other
{

};
void test02()
{
	Base *b = NULL;
	Son  *s = NULL;

	//b转为Son* 向下类型转换 不安全
	Son* s1 = static_cast<Son*>(b);

	//s转为Base* 向上类型转换 安全
	Base* b1 = static_cast<Base*>(s);

	//base 转为 Other*
	//没有父子关系的两个类型之间转换是无法转换成功的
	//Other* o = static_cast<Other*>(b);
}


int main()
{
	test01();

	return 0;
}