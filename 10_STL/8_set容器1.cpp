#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> &s)
{
    for(set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    set<int> s;
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(50);
    s.insert(70);

    printSet(s);

    s.erase(30);
    printSet(s);

}

void test02()
{
    set<int> s;
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(50);
    s.insert(70);

    //查找
    set<int>::iterator pos = s.find(50);
    if(pos != s.end()){
        cout << "找到了元素：" << *pos << endl;
    }
    else{
        cout << "未找到" << endl;
    }

    //统计 对于set 结果要么0 要么1
    int num = s.count(10);
    cout << "10的个数为：" << num << endl;

    //lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    set<int>::iterator res = s.lower_bound(30);
    if(pos != s.end()){
        cout << "找到lower_bound的值为" << *res << endl;
    }
    else{
        cout << "未找到" << endl;
    }

    //upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	res = s.upper_bound(30);
	if (res != s.end())
	{
		cout << "找到upper_bound的值为： " << *res << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

    //equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	pair< set<int>::iterator, set<int>::iterator> it = s.equal_range(30);
	if (it.first != s.end())
	{
		cout << "找到equal_range中的 lower_bound的值为： " << *(it.first) << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	if ( it.second != s.end() )
	{
		cout << "找到equal_range中的 upper_bound的值为： " << *(it.second) << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
int main()
{
    // test01();
    test02();

    return 0;
}