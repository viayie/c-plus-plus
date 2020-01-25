#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque(deque<int> &d)
{
    // iterator 普通迭代器
	// reverse_iterator 反转迭代器
	// const_iterator   只读迭代器
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        //*it = 100;
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    deque<int> d;
    d.push_front(10);
    d.push_front(20);
    d.push_front(30);
    d.push_front(40);

    printDeque(d);

    deque<int>d2(10, 10);
	d.swap(d2);
	printDeque(d);

	if (d.empty())
	{
		cout << "d为空" << endl;
	}
	else
	{
		cout << "d不为空--size = " << d.size() << endl;
	}
}

void test02()
{
    deque<int> d;
    d.push_front(10);
    d.push_front(20);
    d.push_front(30);
    d.push_front(40);

    printDeque(d);
	d.pop_back();
	d.pop_front();
	printDeque(d);

    cout << "第一个元素： " << d.front() << endl;
	cout << "最后一个元素： " << d.back() << endl;

    //插入 
	d.insert(++d.begin(), 10000);
	printDeque(d);

	//删除 
	d.erase(++d.begin(),--d.end());
	printDeque(d);
}

/*排序*/
bool myCompare(int v1, int v2)
{
    return v1 > v2;//降序
}
void test03()
{
    deque<int> d;
    d.push_front(10);
    d.push_front(20);
    d.push_front(30);
    d.push_front(40);

    //默认排序规则从小到大
	sort(d.begin(), d.end());

	//从大到小排序
	sort(d.begin(), d.end(), myCompare);
	printDeque(d);
}
int main()
{
    // test01();
    test03();

    return 0;
}