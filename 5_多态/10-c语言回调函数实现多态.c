#include <stdio.h>

void func1(int a, int b)
{
	printf("func1()...\n");
}

void func2(int a, int b)
{
	printf("func2()...\n");
}

void func3(int a, int b)
{
	printf("func3()...\n");
}

//定义一个统一的接口 将他们全部调用起来。
void my_funtion(int(*fp)(int, int), int a, int b)
{
	fp(a, b);
}

int main(void)
{
	my_funtion(func1, 10, 20);
	my_funtion(func2, 100, 200);
	my_funtion(func3, 1000, 2000);

	return 0;
}