#include <iostream>
#include <vector>
using namespace std;

void test01()
{
    vector<int> v;
    for(int i=0; i<20; i++){
        v.push_back(i);
        cout << "容量:" << v.capacity() << endl;
    }
}

void PrintVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }

    cout << endl;
}

/*构造*/
void test02()
{
    vector<int> v1(10, 100);//10个100
    PrintVector(v1);

    vector<int> v2(v1.begin(), v1.end());
    PrintVector(v2);

}

/*赋值*/
void test03()
{
    vector<int> v1(10, 100);//10个100
    vector<int> v2;
    //v2.assign(v1.begin(), v1.end());
    v2 = v1;
    PrintVector(v2);

    int arr[] = {2, 3, 4, 5};
    vector<int> v3(arr, arr + sizeof(arr)/sizeof(int));
}

/*交换*/
void test04()
{
    vector<int> v1(10, 100);//10个100
    vector<int> v2(10, 999);
    v1.swap(v2);
    PrintVector(v1);
}

/*vector大小操作*/
void test05()
{
    vector<int>v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(30);

    cout << "size:" << v1.size() << endl;//返回容器中元素的个数

    if(v1.empty()){
        cout << "v1为空" << endl;
        return;
    }

    //重新指定容器长度
    v1.resize(10, 100);//第二个参数是默认填充的值，如果不写默认值为0
    PrintVector(v1);
    v1.resize(3);//末尾超出容器长度的元素被删除。
    PrintVector(v1);
}

/*数据存取操作*/
void test06()
{
    vector<int>v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(30);

    cout << "第一个元素" << v1.front() << endl;
    cout << "最后一个元素" << v1.back() << endl;
}

/*插入删除操作*/
void test07()
{
    vector<int>v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(30);

    v1.insert(v1.begin(), 1000);//第一个参数位置 迭代器
    PrintVector(v1);

    v1.pop_back();//尾删
    PrintVector(v1);

   // v1.erase(v1.begin(), v1.end());
   v1.clear();
    PrintVector(v1);
}

/*巧用swap收缩内存*/
void test08()
{
    vector<int> v;
    for(int i=0; i<10000; i++){
        v.push_back(i);
    }
    cout << "v的容量" << v.capacity() << endl;//v的容量16384
    cout << "v的大小" << v.size() << endl;//v的大小10000

    v.resize(3);
    cout << "v的容量" << v.capacity() << endl;//v的容量16384
    cout << "v的大小" << v.size() << endl;//v的大小3

    //收缩内存
    vector<int>(v).swap(v);
    cout << "v的容量" << v.capacity() << endl;//v的容量3
    cout << "v的大小" << v.size() << endl;//v的大小3
}

/*巧用reverse预留空间*/
void test09()
{
    vector<int> v;
    v.reserve(100000);

    int count = 0;
    int *p = NULL;

    for(int i=0; i<100000; ++i){
        v.push_back(i);

        if(p != &v[0]){//测试重新申请内存多少次
            p = &v[0];
            count++;
        }
    }

    cout << "count = " << count << endl;
}

/*逆序遍历*/
void test10()
{
    vector<int>v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(30);
    
    cout << "正序遍历：" << endl;
    PrintVector(v1);

    cout << "逆序遍历：" << endl;
    for(vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++){
        cout << *it << " ";
    }  
    cout << endl;
}

/*如何判断一个容器的迭代器是否支持随机访问*/
void test11()
{
    vector<int> v1(10, 100);//10个100

    vector<int>::iterator itBegin = v1.begin();
    itBegin = itBegin + 1;//语法通过 就支持随机访问

}
int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    // test08();
    // test09();
    test10();

    return 0;
}