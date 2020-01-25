#### STL优点

1. STL 是 C++的一部分，因此不用额外安装什么，它被内建在你的编译器之内
2. STL的一个重要特点是数据结构和算法的分离
3. 程序员可以不用思考STL具体的实现过程，只要能够熟练使用STL就OK了。这样他们就可以把精力放在程序开发的别的方面
4. STL具有高可重用性，高性能，高移植性，跨平台的优点：
   * 高可重用性：STL中几乎所有的代码都采用了模板类和模版函数的方式实现，这相比于传统的由函数和类组成的库来说提供了更好的代码重用机会
   * 高性能：如map可以高效地从十万条记录里面查找出指定的记录，因为map是采用红黑树的变体实现的。(红黑树是平横二叉树的一种)
   * 高移植性：如在项目A上用STL编写的模块，可以直接移植到项目B上
   * 跨平台：如用windows的Visual Studio编写的代码可以在Mac OS的XCode上直接编译

#### STL三大组件

1.  容器：指存储有限数据元素的一种数据结构。比如栈(stack)，队列(queue)...

2.  STL中容器分为：序列式容器和关联式容器

    *   序列式容器：每个元素都有固定位置－－取决于插入时机和地点，和元素值无关。

        **vector、deque、list** 

    *   关联式容器：元素位置取决于特定的排序准则，和插入顺序无关 

        **set、multiset、map、multimap**

3.  迭代器

    迭代器在STL中用来将算法和容器联系起来，起着一种黏和剂的作用。迭代器是一种对象，它能够用来遍历标准模板库容器中的部分或全部元素，每个迭代器对象代表容器中的确定的地址

4.  算法

    C++通过模板的机制允许推迟对某些类型的选择，直到真正想使用模板或者说对模板进行特化的时候，STL就利用了这一点提 供了相当多的有用算法。它是在一个有效的框架中完成这些算法的——可以将所有的类型划分为少数的几类，然后就可以在模版的参数中使用一种类型替换掉同一种 类中的其他类型

    算法部分主要由头文件`<algorithm>`，`<numeric>`和`<functional>`组 成

5.  

#### 容器

|         数据结构         |                             描述                             | 实现头文件 |
| :----------------------: | :----------------------------------------------------------: | :--------: |
|       向量(vector)       |                        连续存储的元素                        |  <vector>  |
|        列表(list)        |         由节点组成的双向链表，每个结点包含着一个元素         |   <list>   |
|      双队列(deque)       |           连续存储的指向不同元素的指针所组成的数组           |  <deque>   |
|        集合(set)         | 由节点组成的红黑树，每个节点都包含着一个元素，节点之间以某种作用于元素对的谓词排列，没有两个不同的元素能够拥有相同的次序 |   <set>    |
|    多重集合(multiset)    |               允许存在两个次序相等的元素的集合               |   <set>    |
|        栈(stack)         |                      后进先出的值的排列                      |  <stack>   |
|       队列(queue)        |                      先进先出的执的排列                      |  <queue>   |
| 优先队列(priority_queue) | 元素的次序是由作用于所存储的值对上的某种谓词决定的的一种队列 |  <queue>   |
|        映射(map)         |     由{键，值}对组成的集合，以某种作用于键对上的谓词排列     |   <map>    |
|    多重映射(multimap)    |                  允许键对有相等的次序的映射                  |   <map>    |

#### string容器

1.  string和char*可以互相转换

    ```cpp
    //string 转 char*
    string str = "viayie";
    const char* cstr = str.c_str();
    //char* 转 string 
    char* s = "viayie";
    string sstr(s);
    ```

2.  构造

    ```cpp
    string s1;
    string s2(s1);//拷贝构造
    string s3("aaa");//有参构造
    string s4(10, 'c');//10个c
    ```

3.  赋值

    ```cpp
    string s5;
    s5 = s4;
    s5.assign("asdfg", 3);//asd
    
    string s6 = "asdfgh";
    string s7;
    s7.assign(s6, 1, 3);//从第二个开始截取个3字符
    ```

4.  字符存取

    ```cpp
    string s = "hello world";
    
    // for(int i=0; i<s.size(); i++){
    //     //cout << s[i];
    //     cout << s.at(i);
    // }
    
    //at 和 [] 区别：
    //[]越界程序出错
    //at越界 会抛出一个异常 out_of_range
    try {
    	//s[100];
    	s.at(100);
    	}
    catch (out_of_range &e){
    	cout << e.what() << endl;
    	} 
    ```

5.  字符串拼接

    ```cpp
    string s1 = "hello ";
    string s2 = "world";
    
    //s1 += s2;
    s1.append(s2);
    ```

6.  字符串查找

    ```cpp
    string s = "asdfghsd";
    cout << "pos = " << s.find("sd") << endl;//第一次出现的位置
    cout << "pos = " << s.rfind("sd") << endl;//从右往左第一次出现的位置
    ```

7.  字符串替换

    ```cpp
    string s = "asdfghsd";
    //s.replace(1, 3, "333");//a333ghsd
    s.replace(1, 3, "333333");//a333333ghsd
    ```

8.  比较

    ```cpp
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
    ```

9.  子串

    ```cpp
    string s = "hello world";
    string sub = s.substr(1, 3);
    cout << sub << endl;
    
    string email_str = "viayielos@gmail.com";
    int pos = email_str.find("@");
    string usr_name = email_str.substr(0, pos);
    cout << usr_name << endl;
    ```

10.  子串案例:  www.viayie.online，将网址的每一个单词截取到vector中

     ```cpp
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
     ```

11. 案例 

     ```cpp
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
     ```

12.  算法相关

     ```cpp
     string s2 = "AAAbbb";
     transform(s2.begin(), s2.end(), s2.begin(), toupper);
     cout << s2 << endl;
     string s3 = "AAAbbb";
     transform(s3.begin(), s3.end(), s3.begin(), tolower);
     ```

#### vector容器

1.  特性

    *   vector是动态数组，连续内存空间，具有随机存取效率高的优点
    *   vector是单口容器，在队尾插入和删除元素效率高，在指定位置插入会导致数据元素移动，效率低

2.  操作图

    ![图片1.png](http://yanxuan.nosdn.127.net/ed0f296bf52ac132cfa206f21f854abd.png)

3.  vector如何实现动态增长

    当vector空间满的时候，再当插入新元素的时候，vector会重新申请一块更大的内存空间，将原空间数据拷贝到新的内存空间，然后释放旧的内存空间，再将新元素插入到新空间中，以此可以看出vector的空间动态增长效率较低

    ```cpp
    vector<int> v;
    for(int i=0; i<20; i++){
        v.push_back(i);
        cout << "容量:" << v.capacity() << endl;
    }
    ```

4.  正序遍历：

    ```cpp
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    ```

    逆序遍历：

    ```cpp
    for(vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++){
    	cout << *it << " ";
    }  
    cout << endl;
    ```

5.  构造

    ```cpp
    vector<int> v1(10, 100);//10个100
    vector<int> v2(v1.begin(), v1.end());
    ```

6.  赋值

    ```cpp
    vector<int> v1(10, 100);//10个100
    vector<int> v2;
    //v2.assign(v1.begin(), v1.end());
    v2 = v1;
    
    int arr[] = {2, 3, 4, 5};
    vector<int> v3(arr, arr + sizeof(arr)/sizeof(int));
    ```

7.  交换

    ```cpp
    vector<int> v1(10, 100);//10个100
    vector<int> v2(10, 999);
    v1.swap(v2);
    ```

8.  vector大小操作

    ```cpp
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
    v1.resize(3);//末尾超出容器长度的元素被删除。
    ```

9.  数据存取操作

    ```cpp
    cout << "第一个元素" << v1.front() << endl;
    cout << "最后一个元素" << v1.back() << endl;
    ```

10.  插入删除操作

     ```cpp
     v1.insert(v1.begin(), 1000);//第一个参数位置 迭代器类型
     v1.pop_back();//尾删
     v1.erase(v1.begin(), v1.end());
     v1.clear();
     ```

11.  巧用swap收缩内存

     ```cpp
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
     ```

12.  巧用reverse预留空间

     ```cpp
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
     ```

13.  如何判断一个容器的迭代器是否支持随机访问

     ```cpp
     vector<int>::iterator itBegin = v1.begin();
     itBegin = itBegin + 1;//语法通过 就支持随机访问
     ```



#### deque容器

1.  特性

    *   双端插入和删除元素效率较高
    *   指定位置插入也会导致数据元素移动,降低效率
    *   可随机存取,效率高
    *   deque和vector的最大差异：
        1.  deque允许常数时间内对头端进行元素插入和删除操作
        2.  deque没有容量的概念，因为它是动态的以分段的连续空间组合而成，随时可以增加一段新的空间并链接起来

2.  操作图

    ![图片2.png](http://yanxuan.nosdn.127.net/39c9b9ed0530a01da00783078fa467be.png)

3.  原理图

    ![图片3.png](http://yanxuan.nosdn.127.net/7c35faa1c2143b732a0cffbe8ffcae25.png)

4.  遍历

    ```cpp
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
    ```

5.  赋值

    ```cpp
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
    ```

6.  存取

    ```cpp
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
    ```

7.  排序

    ```cpp
    #include <algorithm>
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
    ```

    deque是分段连续的内存空间，通过中控器维持一种连续内存空间的状态，其实现复杂性要大于vector queue stack等容器，其迭代器的实现也更加复杂，在需要对deque容器元素进行排序的时候，建议先将deque容器中数据数据元素拷贝到vector容器中，对vector进行排序，然后再将排序完成的数据拷贝回deque容器

#### stack容器

栈不能遍历，没有迭代器，不支持随机存取，只能通过top从栈顶获取和删除元素

![图片4.png](http://yanxuan.nosdn.127.net/e45b496fe605e243dfd9cb47b5a3362b.png)

```cpp
void test01()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << "栈的大小：" << s.size() << endl;

}
```

#### queue容器

*   必须从一个口数据元素入队，另一个口数据元素出队

*   不能随机存取，不支持遍历

![图片5.png](http://yanxuan.nosdn.127.net/0e194fe112e157953c3ab89a5bba3cf1.png)

```cpp
queue<Person>Q;

Person p1("aaa",10);
Person p2("bbb", 20);
Person p3("ccc", 30);
Person p4("ddd", 40);

//入队
Q.push(p1);
Q.push(p2);
Q.push(p3);
Q.push(p4);

while ( !Q.empty())
{
	//获取队头元素
	Person pFront =  Q.front();
	cout << "队头元素 姓名： " << pFront.m_Name << " 年龄： " << pFront.m_Age << endl;

	//获取队尾元素
	Person pBack = Q.back();
	cout << "队尾元素 姓名： " << pBack.m_Name << " 年龄： " << pBack.m_Age << endl;

	//出队
	Q.pop();
}

cout << "队列的大小为： " << Q.size() << endl;
```



#### list容器

1.  特性

    *   采用动态存储分配，不会造成内存浪费和溢出
    *   链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
    *   链表灵活，但是空间和时间额外耗费较大

2.  操作示意图

    ![图片6.png](http://yanxuan.nosdn.127.net/a7432d432179aa8b8e90db89ed88570c.png)

3.  list是一个双向循环链表

    ```cpp
    list<int> myList;
    for (int i = 0; i < 10; i++){
    	myList.push_back(i);
    }
    list<int>::_Nodeptr node = myList._Myhead->_Next;
    for (int i = 0; i < myList._Mysize * 2; i++){
    	cout << "Node:" << node->_Myval << endl;
    	node = node->_Next;
    	//node->_Prev 
    	if (node == myList._Myhead){
    		node = node->_Next;
    	}
    }
    ```

4.  正序遍历

    ```cpp
    void printList(const list<int>&L)
    {
    	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    
    ```

5.  算法

    ```cpp
    //反转  质变算法
    L.reverse();
    	
    bool myCompare(int v1, int v2)
    {
    	return v1 > v2;
    }
    //排序  
    // 所有系统提供标准算法  使用的容器提供的迭代器必须支持随机访问
    // 不支持随机访问的迭代器的容器 ，内部会对应提供相应的算法的接口
    //sort(L.begin(), L.end());
    L.sort(); //默认排序规则  从小到大
    L.sort(myCompare);//修改排序规则 为 从大到小
    ```

6.  自定义数据类型

    ```cpp
    class Person
    {
    public:
    	Person(string name, int age ,int height)
    	{
    		this->m_Name = name;
    		this->m_Age = age;
    		this->m_Height = height;
    	}
    
    	bool operator==( const Person & p)
    	{
    		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
    		{
    			return true;
    		}
    		return false;
    	
    	}
    
    	string m_Name;
    	int m_Age;
    	int m_Height; //身高
    };
    
    bool myComparePerson(Person & p1, Person &p2)
    {
    	//按照年龄  升序
    	// 如果年龄相同 按照身高 进行降序
    
    	if (p1.m_Age == p2.m_Age)
    	{
    		return p1.m_Height > p2.m_Height;
    	}
    
    	return p1.m_Age < p2.m_Age;
    }
    
    void test05()
    {
    	list<Person> L;
    
    	Person p1("大娃", 30 , 170);
    	Person p2("二娃", 28 , 160);
    	Person p3("三娃", 24 , 150);
    	Person p4("四娃", 24 , 166);
    	Person p5("五娃", 24 , 158);
    	Person p6("爷爷", 90 , 200);
    	Person p7("蛇精", 999 , 999);
    
    	L.push_back(p1);
    	L.push_back(p2);
    	L.push_back(p3);
    	L.push_back(p4);
    	L.push_back(p5);
    	L.push_back(p6);
    	L.push_back(p7);
    
    	for (list<Person>::iterator it = L.begin(); it != L.end();it++)
    	{
    		cout << " 姓名： " << it->m_Name << " 年龄： " << it->m_Age <<" 身高： "<< it->m_Height <<  endl;
    	}
    	cout << "排序后的结果为： " << endl;
    	L.sort(myComparePerson); //自定义的数据类型 必须指定排序规则
    	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    	{
    		cout << " 姓名： " << it->m_Name << " 年龄： " << it->m_Age << " 身高： " << it->m_Height << endl;
    	}
    }
    ```



#### set/multiset容器

1.  特性

    *   set是一个集合容器，其中所包含的元素是唯一的，集合中的元素按一定的顺序排列。元素插入过程是按排序规则插入，所以不能指定插入位置
    *   set采用红黑树变体的数据结构实现，红黑树属于平衡二叉树。在插入操作和删除操作上比vector快
    *   set不可以直接存取元素。（不可以使用at.(pos)与[]操作符）
    *   multiset与set的区别：set支持唯一键值，每个元素值只能出现一次；而multiset中同一值可以出现多次
    *   不可以直接修改set或multiset容器中的元素值，因为该类容器是自动排序的。如果希望修改一个元素值，必须先删除原有的元素，再插入新的元素

2.  插入

    ```cpp
    set<int> s;
    s.insert(10);
    s.erase(10);
    ```

3.  查找 和 统计

    ```cpp
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
    ```

4.  对组

    ```cpp
    //第一种声明
    pair<string, int> p(string("tom"), 18);
    cout << "name:" << p.first << ", age:" << p.second << endl;
    
    //第二种声明
    pair<string, int> p2 = make_pair("jarry", 20);
    cout << "name:" << p2.first << ", age:" << p2.second << endl;
    ```

5.  判断是否插入成功

    ```cpp
    //insert返回对组，pair<iterator, bool>
    set<int> s;
    s.insert(10);
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if(ret.second){
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }
    ```

6.  **利用仿函数 指定set容器的排序规则**

    ```cpp
    class MyCompare
    {
    public:
        bool operator() (int v1, int v2)
        {
            return v1 < v2;
        }
    };
    void test()
    {
        set<int, MyCompare> s;
        s.insert(10);
        s.insert(30);
        s.insert(20);
        s.insert(50);
        s.insert(70);
    
        for(set<int, MyCompare>::iterator it = s.begin(); it != s.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    ```

7.  **对于自定义数据类型，必须指定排序规则**

    ```cpp
    class Person
    {
    public:
    	Person(string name,int age)
    	{
    		this->m_Name = name;
    		this->m_Age = age;
    	}
    
    	string m_Name;
    	int m_Age;
    };
    
    class MyComparePerson
    {
    public:
    	bool operator()(const  Person & p1 , const Person & p2)
    	{
    		//年龄 升序
    		return p1.m_Age < p2.m_Age;
    	}
    
    };
    
    void test()
    {
    	set<Person, MyComparePerson> s;
    
    	Person p1("aaa", 10);
    	Person p2("bbb", 30);
    	Person p3("ccc", 20);
    	Person p4("ddd", 50);
    	Person p5("eee", 40);
    
    	s.insert(p1);
    	s.insert(p2);
    	s.insert(p3);
    	s.insert(p4);
    	s.insert(p5);
    
    	//对于自定义数据类型，必须指定排序规则
    	for (set<Person,MyComparePerson>::iterator it = s.begin(); it != s.end(); it++)
    	{
    		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << endl;
    	}
    
    }
    ```



#### map和multimap容器

1.  特性

	*   map是标准的**关联式容器**，一个map是一个键值对序列，即(key,value)对。它提供基于key的快速检索能力
	*   map中**key值是唯一的**。集合中的元素按一定的顺序排列。元素插入过程是按排序规则插入，所以不能指定插入位置
	*   map的具体实现采用红黑树变体的平衡二叉树的数据结构。在插入操作和删除操作上比vector快
	*   map可以直接存取key所对应的value，**支持[]操作符，如map[key]=value**
	*   multimap与map的区别：map支持唯一键值，每个键只能出现一次；而multimap中相同键可以出现多次。multimap不支持[]操作符
	
2.  插入

    ```cpp
    	//第一种
    	m.insert(pair<int, int>(1, 10));
    
    	//第二种
    	m.insert(make_pair(2, 20));
    
    	//第三种
    	m.insert(map<int, int>::value_type(3, 30));
    
    	//第四种
    	m[4] = 40;
    
    	for (map<int, int>::iterator it = m.begin(); it != m.end();it++)
    	{
    		cout << " key =  " << it->first << " value = " << (*it).second << endl;
    	}
    
    
    	//cout << m[5] << endl;//即使没有数据也会插入个0
    	//for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    	//{
    	//	cout << " key =  " << it->first << " value = " << (*it).second << endl;
    	//}
    ```

3.  删除

    ```cpp
    //m.erase(3); //按照key进行删除元素
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
    	cout << " key =  " << it->first << " value = " << (*it).second << endl;
    }
    ```

4.  查找

    ```cpp
    //查找
    map<int,int>::iterator pos =  m.find(3);
    if (pos != m.end())
    {
    	cout << "找到了 key为： " << (*pos).first << " value 为： " << pos->second << endl;
    }
    ```

5.  指定map容器的排序规则

    ```cpp
    class MyCompare
    {
    public:
    	bool operator()(int v1,int v2)
    	{
    		return v1 > v2;
    	}
    
    };
    
    //指定map容器的排序规则
    void test()
    {
    	map<int, int, MyCompare> m;
    	m.insert(pair<int, int>(1, 10));
    	m.insert(make_pair(2, 20));
    	m.insert(map<int, int>::value_type(3, 30));
    	m[4] = 40;
    
    	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    	{
    		cout << " key =  " << it->first << " value = " << (*it).second << endl;
    	}
    
    }
    ```

    










