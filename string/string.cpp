#include <iostream>
#include <string>
using namespace std;
#if 0
int main()
{
	string s1;
	string s2("Hi");
	string s3 = s2;
	string s4(10,'$');
	string s5 = "Hi";

	string s6  = s2 + s4;
	cin>>s1;
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

	system("pause");
	return 0;

}
#endif
// reserve
/*
reserve: 
1. 扩容函数--只是扩容，不会改变有效元素个数
2. reserve(n): n只有比当前string类对象底层空间容量大的情况下才会真正扩容，而且一般情况下不会直接将容量给成n
3. reserve(n): n小于当前string类对象底层空间时，reserve会忽略本次操作，除非n < 15
4. reserve方法一般只会将容量扩大，而不会将空间缩小的，
5. string类为了提高性能，在其类中管理一个长度为16个字符的数组
6.扩容的大小不是指定的n
*/
void Test1()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(32);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

}
// resize(size_t n, char ch): 将string中有效字符个数改变到n个，多出的字符用ch进行填充
// resize(size_t n)：将string中有效字符个数改变到n个，多出的字符用0进行填充
/*
resize(newsize, ch): 假设string类的有效元素个数为size，容量为capacity
1. newsize < size: 只是将有效元素个数改变到newsize即可，不会缩小容量
2. size<newsize<capacity: 直接将有效元素个数增加到newsize，多出的newsize-size个元素使用ch(0)进行填充
3. newsize > capacity: 扩容-：申请新空间，拷贝元素，释放旧空间--将新元素个数增加到newsize个，多出的newsize-size个元素使用ch(0)进行填充
*/
void Test2()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10,'!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	
	s.resize(20,'!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(30,'!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(40,'!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

		s.resize(30);
			cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20);
		cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10);
		cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

}
/*
vs-string的扩容方式是按照1.5倍的方式进行扩容的
注意：linux-SGI-STL string扩容的方式：是按照2倍的方式扩容的

按照两倍的方式扩容好呢还是按照1.5倍的方式扩容比较好？


push_back: 在尾插期间会进行扩容：开辟新空间  拷贝元素   释放旧空间
如果一边插入，一边开辟空间---效率太低了

string: 采用push_back尾插元素时，如果知道大概要存放多少个元素，最好提前先将空间给足然后插入---效率高
*/
void Test3()
{
	string s1("hello");

	cout<<s1[0]<<endl;
	s1[0] = 'H';
	cout<<s1<<endl;

	for(size_t i = 0; i < s1.size();i++)
	{
		if(s1[i]>='a'&&s1[i]<='z')
			s1[i]-=32;
	}
	cout<<s1<<endl;

	//通过迭代器遍历string对象
	auto it = s1.begin();
	while(it != s1.end())
	{
		cout<<*it;
		it++;
	}
	cout<<endl;
	//反向迭代器
	auto rit = s1.rbegin();
	while(rit != s1.rend())
	{
		cout<<*rit;
		rit++;
	}
	cout<<endl;
	//范围for
	for(auto c: s1)
		cout<<c;
	cout<<endl;
}
void Test4()
{
	string s;
	s.push_back('I');
	s.append(" ");

	string ss("Love");
	s.append(ss);
	s.append(" ");

	string sss("R");
	s.append(sss);

	s.append(3, '!!!');
	size_t pos = s.find('!');//返回的是下标
	s.insert(s.find('!'),"✌");
	cout<<pos<<endl;

	cout<<s<<endl;


}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	system("pause");

	return 0;
}