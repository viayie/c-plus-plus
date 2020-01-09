#include <iostream>
#include <vector>
using namespace std;

void test01()
{
    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
        cout << v.capacity() << endl;
    }
}

void PrintVector(vector<int> v)
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
    
}

int main()
{
    test02();

    return 0;
}