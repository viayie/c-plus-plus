#### 作用域解析符
```cpp
int a = 10;
int main()
{
    int a = 20;

    cout << "局部变量值为：" << a << endl;
    cout << "全局变量值为：" << ::a << endl;
    //如果::前面没有任何作用域，代表使用全局作用域
    return 0;
}
```
---
#### register关键字加强
1. 寄存器不在内存中，寄存器变量不存在地址；

2. 在C++中，对寄存器变量取地址操作，register对变量的声明变得无效，被定义的变量被强制放在内存中
   ```cpp
   #include <stdio.h>
   register int b = 10;//编译不通过：不正确的存储类“register”
   int main()
   {
       register int a = 10;
       printf("&a = %p\n", &a);
       
       return 0;
   }
   ```

   ```
   输出结果：
   &a = 00CFF7B0
   ```

3. C++ 中register无法在全局中定义变量，否则会提示“不正确的存储类”；
   
   C 中register可以在全局中定义变量，当对变量进行取地址操作时警告“有坏的存储类”

---

#### struct 的加强 

```cpp
struct Student
{
	char name[20];
	int age;
    //void func();//C语言下结构体中不能放函数
};

struct Student stu1 = {"wang", 11};//c语言要加struct 关键字

Student stu2 = { "wang", 11 };//c++认为struct是一个新类型的定义声明， 可以直接使用结构体名来定义变量

```

***

#### 三目运算符的加强 

1. c++中三目运算符可作左值使用

   ```cpp
   int a = 10;
   int b = 20;
   (a > b ? a : b) = 40;
   printf("b = %d", b);//输出结果 b = 40
   ```

2. 实现原理

   ```cpp
   *（a>b ? &a : &b）= 40;
   //*（a>20 ? &a : &20）= 40;无法通过编译
   ```

***

#### bool 类型 

```cpp
bool a;
cout << sizeof(a) << endl;
//输出1（byte）；
//如果多个bool变量定义在一起，可能会各占 1 bit,这取决于编译器的实现
```

***

#### c/c++ 中 const 

1. c 语言中的 const

   ```c
   /*全局*/
   const int m_A = 200;//全局const受到常量区保护
   void test01()
   {
       int *p = &m_A;
       *p = 100;//语法通过，运行阶段报错。
   }
   
   /*局部*/
   //修饰的是 只读变量 ， 本质上仍是变量，有自己存储空间
   void test02()
   {
       const int m_B = 200;
       int *p = &m_B;
       *p = 100;//可以间接修改
   
       int arr[m_B];//err 不可以初始化数组
   }
   
   /*const在C语言下默认是外部链接属性*/
   void test03()
   {
       //在另一个.c文件中有 const int m_C = 20;
       extern const int m_C;
   
       printf("m_C = %d\n", m_C);
   }
   ```

2. c++ 中的const 

   ```cpp
   /*全局*/
   const int m_A = 200;//全局const受到常量区保护
   void test01()
   {
       int *p = (int *)&m_A;
       *p = 100;//语法通过，运行阶段报错。
   }
   
   /*局部*/
   void test02()
   {
       const int m_B = 200;//被编译器放到符号表中去
       int *p = (int *)&m_B;
       *p = 100;
   
       cout << "m_B = " << m_B << endl;
       //修改不成功，使用时，值是从符号表获取，而不是分配的存储空间的值
   
       int arr[m_B];//可以初始化数组 常量
   }
   
   /*const在C++下默认是内部部链接属性*/
   void test03()
   {
       //在另一个.c文件中有 const int m_C = 20;
       extern const int m_C;
   
       cout << m_C << endl;//err
   
       //修改另一.c文件中为 extern const int m_C = 20;
       cout << m_C << endl;//ok
   }
   
   /*const分配内存情况*/
   //1、对const修饰的变量取地址，会分配临时内存
   
   //2、const修饰的变量前加 extern 关键字
   
   //3、使用变量来初始化const修饰的变量
   void test04()
   {
       int a = 10;
       const int m_D = a;
       int *p = (int *)m_D;
       *p = 20;
       cout << m_D << endl;//修改成功
   }
   
   //4、const修饰自定义数据类型
   struct Person
   {
       string name;
       int age;
   };
   void test05()
   {
       const Person p;
       // p.name = "aaa";//err
       // p.age = 10;//err
   
       Person *pp = (Person*)&p;
       pp->name = "aaa";//OK
       pp->age = 10;//OK
   }
   
   /*尽量利用const代替#define*/
   //1. 宏常量没有类型
   //2. 不重视作用域
   ```

3. const 与 define 相同

   ```cpp
   //#define N 30
   int main()
   {
   	const int a = 10;
   	const int b = 20;
   
   	int array[a + b] = {0};
   
   	return 0;
   }
   ```

4. const 和 define 不同

   ```cpp
   //const常量是由编译器处理的，提供类型检查和作用域检查
   //宏定义由预处理器处理，单纯的文本替换
   void fun1()
   {
   	#define M 10
   	const int a = 10;
   }
   void fun2()
   {
   	//#undef M
   	printf("M = %d", M);
   
   	printf("a = %d", a);//err，作用域检查
   }
   void fun3(char *p)
   {
   	;
   }
   int main()
   {
   	fun1();
   	fun2();
   
   	const int b = 10;//err, 类型检查
   	fun3(b);
   }
   ```

---

#### 真正的枚举 

```cpp
//c语言 中枚举本质就是整型,枚举变量可以用任意整型赋值
//c++ 中枚举变量, 只能用被枚举出来的元素初始化。

#include <iostream>
using namespace std;

enum season {Spri, Sum, Aut, Win};

int main()
{
	enum season s = Spri;
	s = Sum;

	//s = 0; // err,但C语言可编译通过

	return 0;
}
```

