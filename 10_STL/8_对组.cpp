#include <iostream>
#include <string>
using namespace std;

//对组的声明
int main()
{
    //第一种声明
    pair<string, int> p(string("tom"), 18);
    cout << "name:" << p.first << ", age:" << p.second << endl;

    //第二种声明
    pair<string, int> p2 = make_pair("jarry", 20);
    cout << "name:" << p2.first << ", age:" << p2.second << endl;

    return 0;
}