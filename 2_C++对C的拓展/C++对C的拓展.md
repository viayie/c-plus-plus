#### 引用 ####

1. 引用的语法：`Type& name = var;`

   ```cpp
   int main()
   {
   	int a = 10;
   	int &b = a;
   
   	a = 11;
   	{
   		int *p = &a;
   		*p = 12;
   		cout << "a = " << a << endl;
   	}
   	b = 22;
   	cout << "a = " << a << ", b = " << b << endl;
   
   	return 0;
   }
   ```

2. 引用的规则

   ```cpp
   void test02()
   {
       int a = 10;
       int b = 20;
   
       int &r = a;//声明的时候必须初始化
       //&r = b;//err 一经声明，不可改变原有的引用关系
   
       //float &R = b;//err 类型与原类型保持一致
   
       cout << &a << " " << &r << endl;//地址相同，引用不分配内存
   
       int &ra = r;//变量a 有两个别名：r, ra
   
       //建立对数组的引用1
       int arr[10];
       int (&parr)[10] = arr;
       
       //建立对数组的引用2：定义出数组的类型，再定义引用
       typedef int(ARRAY_TYPE)[10];
       ARRAY_TYPE &parr2 = arr;   
   }
   ```


3. 引用作函数参数

   ```cpp
   void swap(int &a, int &b)//声明的时候不进行初始化
   {
   	int tmp = a;
   	a = b;
   	b = tmp;
   }
   void test03()
   {
   	int num1 = 10;
   	int num2 = 20;
   
   	cout << "before swap: num1=" << num1 << ", num2=" << num2 << endl;
   	swap(num1, num2);
   	cout << "after  swap: num1=" << num1 << ", num2=" << num2 << endl;
   }
   ```
   
4. 引用作函数返回值（引用当左值）

   * 若返回栈变量:不能成为其它引用的初始值（不能作为左值使用）

     ```cpp
     int &getA1()
     {
         int a = 10;
         return a;
     }
     void test04()
     {
         //值拷贝
         int a1 = 0;
         a1 = getA1();
         cout << "a1 = " << a1 << endl;
     
         //将一个引用赋给另一个引用作为初始值，由于是栈的引用，内存非法
         int &a2 = getA1();
         cout << "a2 = " << a2 << endl;
     }
     ```
     
   * 返回静态变量或全局变量：可以成为其他引用的初始值（可作为右值使用，也可作为左值使用）
   
     ```cpp
     int getA3()
     {
     	static int a = 10;
     	return a;
     }
     int& getA4()
     {
     	static int a = 10;
     	return a;
     }
     int main()
     {
     	int a1 = 0;
    	    int a2 = 0;
     
     	//值拷贝
     	a1 = getA3();
     
     	//将引用赋给一个变量，会有拷贝动作
     	//a2 = *(getA4());
     	a2 = getA4();
     
     	//将一个引用赋给另一个引用作为初始值，由于是静态区域，内存合法
     	int &a3 = getA4();
     
     	cout << "a1 = " << a1 << endl;
     	cout << "a2 = " << a2 << endl;
     	cout << "a3 = " << a3 << endl;
     
     	return 0;
     }
     ```
   
   * 如果返回值为引用可以当左值，如果返回值为普通变量不可以当左值
   
     ```cpp
     int getA5()
     {
     	static int a = 10;
     	return a;
     }
     int& getA6()
     {
     	static int a = 10;
     	return a;
     }
     int main()
     {
     	//函数作为右值
     	int a1 = getA5();
     	cout << "a1 = " << a1 << endl;//a1=10
     	int a2 = getA6();
     	cout << "a2 = " << a2 << endl;//a2=10
     
     	//函数作为左值
     	//getA5() = 100; //err
     	getA6() = 100;
     	int a3 = getA6();
     	cout << "a3 = " << a3 << endl;//a3=100
     
     	return 0;
     }
     ```
   
1. 指针引用

   ```cpp
   struct Teacher
   {
   	char name[64];
   	int age;
   };
   int getTeacher1(Teacher **p)
   {
   	Teacher *tmp = NULL;
   	if (p == NULL)
   	{
   		return -1;
   	}
   	tmp = (Teacher *)malloc(sizeof(Teacher));
   	if (tmp == NULL)
   	{
   		return -2;
   	}
   	tmp->age = 33;
   	*p = tmp;
   
   	return 0;
   }
   int getTeacher2(Teacher* &p)
   {
   	p = (Teacher *)malloc(sizeof(Teacher));
   	if (p == NULL)
   	{
   		return -1;
   	}
   	p->age = 40;
   
   	return 0;
   }
   void freeTeacher(Teacher *p)
   {
   	if (p == NULL)
   	{
   		return;
   	}
   	free(p);
   }
   int main()
   {
   	Teacher *p = NULL;	
   
   	//1.C语言中二级指针
   	getTeacher1(&p);
   	cout << "age:" << p->age << endl;
   	freeTeacher(p);
   
   	//2.C++中的引用
   	getTeacher2(p);
   	cout << "age:" << p->age << endl;
   	freeTeacher(p);
   
   	return 0;
   }
   ```

6. 引用的本质：指针常量

    ```cpp
    Type &name = var; // ----> Type *const name = var;
    ```

7. 常引用(const引用)

   * const 对象的引用必须是 const 的,将普通引用绑定到 const 对象是不合法的。 

     ```cpp
     const int a = 1;
     int &b = a;//err: “初始化”: 无法从“const int”转换为“int &”
     const int &b = a;
     cout << b << endl;
     ```

   * const 引用可使用相关类型的对象(**常量**、**非同类型的变量** 或 **表达式**)初始化

     ```cpp
     double a = 3.14;
     const int &b = a;
     cout << b << endl; //b=3
     ```
     
   * 原理

       ```cpp
       double	val = 3.14;
           
       const int &ref1 = val;// ref1 是 const 的,在初始化的过程中已经给定值, 不允许修改
       double &ref2 = val;
           
       cout << ref1 << " " << ref2 << endl;// 结果：3 3.14
           
       val = 4.14;//val非const, 修改不影响ref1, 会影响ref2
       cout << ref1 << " " << ref2 << endl;// 结果：3 4.14
       ```

   * 实际发生如下过程

       ```c++
       const int &ref1 = val;
       
       int tmp = val;
       const int &ref1 = tmp;
       ```
       
       ```cpp
       void printTeacher(const Teacher &myt)
       {
       	//myt.age = 888;//err 常引⽤ 让 实参变量 拥有只读属性
       	printf("myt.age:%d", myt.age);
       }
       int main()
       {
       	Teacher t1;
       	t1.age = 34;
       
       	printTeacher(t1);
       
       	return 0;
       }
       ```
   * 注意

       ```cpp
       int add(int &a, int &b);
       add(10, 20);//err
       
       //正确方式
       int add(const int &a, const int &b);
       add(10, 20);
       ```

   * 总结：

       1. `const int &e` 相当于 `const int * const e` 
       2. 普通引用 相当于 `int *const e`
       3. 当使用常量为 `const` 引用 进行 初始化时，C++编译器会为常量值分配空间，并将引用名作为这段空间的别名
       4. 使用字面量对 `const引用` 初始化后，将生成一个只读变量
       5. **使用场景：修饰函数形参，防止误操作**

------

####  inline内联函数 ####

1. 使用

    ```cpp
    inline void func(int a)
    {
    	a = 20;
    	cout << a << endl;
    }
    
    int main1()
    {
    	func(10);
    	/*
    	编译器将内联函数的函数体直接展开
    	{
    		a =20;
    		cout << a << endl;
    	}
    	*/
    	return 0;
    }
    ```

2. 特点

    * 内联函数声明时inline关键字必须和函数定义结合在一起，否则编译器会直接忽略内联请求

        ```cpp
        //函数的声明和实现必须同时加入inline关键字，否则不会按照内联方式处理
        inline void func();
        void func() {...}
        ```

    * 在类的内部定义的函数自动成为内联函数

    * C++编译器直接将函数体插入在函数调用的地方

    * 内联函数没有普通函数调用时的额外开销(压栈，跳转，返回)

    * 内联函数是一种特殊的函数，具有普通函数的特征（参数检查，返回类型等）

    * 内联函数  由 编译器 处理，直接将编译后的函数体插入调用的地方；

        宏代码片段 由 预处理器 处理， 进行简单的文本替换，没有任何编译过程

    * 当函数体的执行开销远大于压栈，跳转和返回所用的开销时，那么内联将无意义

    * C++中内联编译的限制

        1. 不能存在任何形式的循环语句
        2. 不能存在过多的条件判断语句
        3. 函数体不能过于庞大
        4. 不能对函数进行取址操作
        5. 函数内联声明必须在调用语句之前

3.  内联函数 vs 宏函数

    ```cpp
    #define SQR(x) ((x)*(x))
    
    inline int sqr(int x)
    {
    	return x * x;
    }
    
    int main()
    {
    	int i = 0;
    
    	while (i < 5)
    	{
    		cout << "i = " << i << endl;
    		printf("%d\n", SQR(i++));
    		//printf("sqr: %d\n", sqr(i++));	
    	}
    
    	return 0;
    }
    ```

4. 总结

    * 优点:避免调用时的额外开销(入栈与出栈操作)
    * 代价:会增加代码段的空间
    * 本质:以牺牲代码段空间为代价,提高程序的运行时间的效率
    * 适用场景:函数体很“小”,且被“频繁”调用

*****

#### 默认参数和占位参数 ####

1. 单个默认参数

    ```cpp
    //若 填写参数,使⽤填写的,不填写使用默认
    void myPrint(int x = 3)	
    { 
    	cout<<"x: “<< x << endl;	
    }
    ```

2. 多个默认参数

    ```cpp
    //只有参数列表后面部分的参数才可以提供默认参数值
    //一旦在一个函数调用中开始使用默认参数值，那么这个参数后的所有参数都必须使用默认参数值
    float volume(float length, float weigth = 4, float high = 5)
    {
    	return length * weigth* high;
    }
    
    int main1()
    {
    	float v1 = volume(10);
    	float v2 = volume(10, 20);
    	float v3 = volume(10, 20, 30);
    
    	cout << v1 << endl;
    	cout << v2 << endl;
    	cout << v3 << endl;
    
    	return 0;
    }
    ```

3. 占位参数

    ```cpp
    /*
    	1.占位参数只有参数类型声明，⽽没有参数名声明
    	2.⼀般情况下，在函数体内部⽆法使⽤占位参数
    */
    int func(int a, int b, int)
    {
    	return a + b;
    }
    int main2()
    {
    	//func(1, 2); //err,必须把最后一个占位参数补上
    
    	cout << "func(1, 2, 3) = " << func(1, 2, 3) << endl;
    
    	return 0;
    }
    ```

    ```cpp
    /*
    	1.可以将占位参数与默认参数结合起来使⽤
    	2.意义
    		>为以后程序的扩展留下线索		
    		>兼容C语⾔程序中可能出现的不规范写法
    */
    int func2(int a, int b, int = 0)
    {
    	return a + b;
    }
    int main()
    {
    	cout << "func(1, 2)    = " << func2(1, 2 )   << endl;
    	cout << "func(1, 2, 3) = " << func2(1, 2, 3) << endl;
    
    	return 0;
    }
    ```

****

#### 函数重载 ####

1. 重载规则

    * 函数名相同
    * 参数个数不同,参数的类型不同,参数顺序不同,均可构成重载
    * 返回值类型不同则不可以构成重载

    ```cpp
    void func(int a); //ok
    void func(char a); //ok
    void func(char a,int b); //ok
    void func(int a, char b); //ok
    char func(int a); //与第⼀个函数有冲突
    ```

2. 重载底层实现

    C++利用 name mangling(倾轧)技术,来改名函数名,区分参数不同的同名函数

    实现原理:用 `v c i f l d `表示 `void char int float long double` 及其引用

    ```cpp
    void func(char	a);		//	func_c(char	a)	
    void func(char a, int b, double	c);		//func_cid(char	a,	int	b,	double	c)
    ```

3. 函数重载条件

    * 作用域必须相同

      ```cpp
      class Person
      {
      	void func() {};
      };
      void func(int a) {};
      ```
    
    * 函数名称相同
    
    * 函数参数的 类型不同 或 个数不同 或 顺序不同
    
    * 返回值不可作为函数重载的条件
    
    * 对于引用，加const和不加const可以作为重载条件
    
      ```cpp
      void func(int &a) {}//int a=10; func(a);
      void func(const int &a){}//func(10);
      
      void func(int a) {}//避免调用时二义性
      ```
    
4. 函数重载 与 函数默认参数

    一个函数，不能既作重载，又作默认参数的函数。当少写一个参数时,系统无法确认是重载还是默认参数

    ```cpp
    int func(int a, int b, int c = 0)
    {
    	return a * b * c;
    }
    
    int func(int a, int b)
    {
    	return a + b;
    }
    
    void test()
    {
    	int c = 0;
    	c = func(1, 2);//err 存在二义性
    }
    ```

5. 函数重载和函数指针结合

    * 函数指针 回顾

        ```cpp
        int func1(int x)
        {
        	return x;
        }
        
        typedef int(myTypeFunc)(int);//声明⼀个函数类型
        typedef int(*myTypeFunc_P)(int);//声明⼀个函数指针类型
        
        int main()
        {
        	//第一种
        	myTypeFunc *fp1 = NULL;//定义⼀个函数指针
        	fp1 = func1;
        	fp1(10);
        
        	//第二种
        	myTypeFunc_P fp2 = NULL;//定义⼀个函数指针
        	fp2 = func1;
        	fp2(10);
        
        	//第三种
        	int(*fp3)(int) = NULL;//定义⼀个函数指针 变量
        	fp3 = func1;
        	fp3(10);
        	
        	return 0;
        }
        ```

    * 函数重载与函数指针

        ```cpp
        /*
        	当使⽤重载函数名对函数指针进⾏赋值时,
        	根据重载规则挑选与函数指针参数列表⼀致的候选者,
        	严格匹配候选者的函数类型与函数指针的函数类型
        */
        int func2(int x)
        {
        	return x;
        }
        
        int func2(int a, int b)
        {
        	return a + b;
        }
        
        int func2(const char* s)
        {
        	return strlen(s);
        }
        
        typedef int(*myFunc)(int x);
        typedef int(*myFunc_1)(int a, int b);
        typedef int(*myFunc_2)(const char* s);
        int main()
        {
        	int c = 0;
        
        	myFunc p1 = func2;
        	c = p1(10);
        	cout << c << endl;
        
        	myFunc_1 p2 = func2;
        	c = p2(2, 3);
        	cout << c << endl;
        
        	myFunc_2 p3 = func2;
        	c = p3("hello");
        	cout << c << endl;
        
        	return 0;
        
        }
        ```

****

#### extern C

```cpp
//test.c test.h main.cpp
//main.cpp中
//include "test.h"//注释掉
extern "C" void hello();


//test.c test.h main.cpp
//test.h文件中
//表示如果是C++在运行本文件时，extern C包含的内容用C语言方式链接
#ifdef __cplusplus
extern "C"{
#endif
    
#include <stdio.h>
void hello();
    
#ifdef __cplusplus   
}
#endif
```









