#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

/*初始化操作*/
void test01()
{
    //构造
    string s1;
    string s2(s1);//拷贝构造
    string s3("aaa");//有参构造
    string s4(10, 'c');//10个c

    cout << s3 << endl;
    cout << s4 << endl;


    //赋值
    string s5;
    s5 = s4;
    s5.assign("asdfg", 3);//asd
    cout << s5 << endl;

    string s6 = "asdfgh";
    string s7;
    s7.assign(s6, 1, 3);//从第二个开始截取个字符
    cout << s7 << endl;
}

/*字符存取*/
void test02()
{
    string s = "hello world";

    // for(int i=0; i<s.size(); i++){
    //     //cout << s[i];
    //     cout << s.at(i);
    // }

    //at 和 [] 区别：
    //[]越界程序出错
    //at越界 会抛出一个异常 out_of_range
    try{
        //s[100];
        s.at(100);
    }
    catch (out_of_range &e){
        cout << e.what() << endl;
    }   
}

/*字符串拼接*/
void test03()
{
    string s1 = "hello ";
    string s2 = "world";

    //s1 += s2;
    s1.append(s2);

    cout << s1 << endl;
}

/*字符串查找*/
void test04()
{
    string s = "asdfghsd";
    cout << "pos = " << s.find("sd") << endl;//第一次出现的位置
    cout << "pos = " << s.rfind("sd") << endl;//从右往左第一次出现的位置
}

/*字符串替换*/
void test05()
{
    string s = "asdfghsd";
    //s.replace(1, 3, "333");//a333ghsd
    s.replace(1, 3, "333333");//a333333ghsd
    cout << s << endl;
}

/*比较*/
void test06()
{
    string s1 = "asdf";
    string s2 = "abbbbbbbbbbbbb";

    if(s1.compare(s2) == 0){
        cout << "字符串相等" << endl;
    }
    else if(s1.compare(s2) > 0){
        cout << "s1 > s2" << endl;//s1 > s2
    }
    else if(s1.compare(s2) < 0){
        cout << "s1 < s2" << endl;
    }
}

/*子串*/
void test07()
{
    string s = "hello world";
    string sub = s.substr(1, 3);
    cout << sub << endl;

    string email_str = "viayielos@gmail.com";
    int pos = email_str.find("@");
    string usr_name = email_str.substr(0, pos);
    cout << usr_name << endl;
}

/*子串案例*/
void test08()
{
    //www.viayie.online
    //需求：将网址的每一个单词截取到vector中
    string str = "www.viayie.online";
    vector<string> v;
    int start = 0;
    int pos = 0;
    string tmp;
    
    while(1){
        pos = str.find(".", start);
        if(pos == -1){//最后一个单词
            tmp = str.substr(start, str.size());
            v.push_back(tmp);
            break;
        }

        tmp = str.substr(start, pos-start);
        v.push_back(tmp);
        start = pos + 1;
    }

    for(vector<string>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

/*插入和删除*/
void test09()
{
    string s = "hello world";
    s.insert(1, "2222");
    cout << s << endl;

    s.erase(1, 4);
    cout << s << endl;
}

/*string和c-style转换*/
void func1(string s){}
void func2(const char *s){}

void test10()
{
    //char* → string
    const char *s1 = "hello world";
    string s2(s1);

    //string → char* 
    const char *s3 = s2.c_str();

    func1(s1);//编译器将const char*隐式转换为string
    //func2(s2);//编译器不会将string隐式转换为const char*
}

void test11()
{
    string s = "hello";
    char &a = s[2];
    char &b = s[3];

    a = '1';
    b = '2';
    cout << s << endl;
    cout << (int*)s.c_str() << endl;

    s = "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq";

    a = '3';//指向可能失效
    b = '4';
    cout << s << endl;
    cout << (int*)s.c_str() << endl;
}

/*string字符串所有小写字母转成大写字母*/
void test12()
{
    string str = "hello world";

    for(int i=0; i<str.size(); i++){
        str.at(i) = toupper(str.at(i));
        //str.at(i) = tolower(str.at(i));
    } 
    cout << str << endl;
}

int main()
{
    test11();

    return 0;
}