#include <iostream>

using namespace std;

//内置数据类型	不允许内置数据类型转换
void test01()
{
	char c = 'c';
	//double d = dynamic_cast<double>(c);
}

//自定义数据类型
class Base
{
	virtual void func(){}
};
class Son:public Base
{
	void func(){}
};
class Other
{

};
void test02()
{
	Base *b = NULL;
	Son  *s = NULL;

	//b转为Son* 向下类型转换 不安全
	//Son* s1 = dynamic_cast<Son*>(b);//转换失败

	//s转为Base* 向上类型转换 安全
	Base* b1 = dynamic_cast<Base*>(s);

	//base 转为 Other*
	//Other* o = static_cast<Other*>(b);//转换失败

	//如果发生多态，父类和子类之间的转换总是安全的
	Base* b2 = new Son;
	Son* s2 = dynamic_cast<Son*>(b2);
}

int main()
{

}
