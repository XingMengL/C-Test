#include <iostream>
using namespace std;

#include <windows.h>
#include <vector>
#include <string>

void Test1()
{
	vector<int> v1;
	vector<int> v2(10,5);

	for(auto ch: v2)
		cout<<ch<<" ";
	cout<<endl;

	int array[] = {1,2,3,4,5};	

	//STL中所有的容器都是左闭右开的
	vector<int> v3(array,array+sizeof(array)/sizeof(array[0]));
	for(auto ch : v3)
		cout<<ch<<" ";
	cout<<endl;

	vector<int> v4(array,array+3);
	for(auto ch : v4)
		cout<<ch<<" ";
	cout<<endl;

	string s("hello");
	vector<char> v5(s.begin(),s.end());
	for(auto ch: v5)
		cout<<ch<<" ";
	cout<<endl;
	
	vector<char> v6(v5);
		for( auto ch: v6)
		cout<<ch<<" ";
	cout<<endl;

	//C++新增加了列表的初始化
	//vector<int> v7{1,2,3,4,5};  编译器版本不支持
	
}
void Test2()
{
	int array[] = {1,2,3,4,5};
	vector<int> v1(array,array+sizeof(array)/sizeof(array[0]));

	for( auto ch: v1)
		cout<<ch<<" ";
	cout<<endl;

	cout<<v1.size()<<endl;
	cout<<v1.capacity()<<endl;

	v1.resize(10,6);
	for( auto ch: v1)
		cout<<ch<<" ";
	cout<<endl;
	v1.resize(5);
	for( auto ch: v1)
		cout<<ch<<" ";
	cout<<endl;

	v1.reserve(20);//第二个没有传递时使用默认值0进行填充
	for( auto ch: v1)
		cout<<ch<<" ";
	cout<<endl;

	v1.reserve(8);
	for( auto ch: v1)
		cout<<ch<<" ";
	cout<<endl;

	// reserve 扩容 不会缩小容量
	// resize 
	// 内置类型 
	// 自定义类型 ---- 要有默认构造函数 不然会崩溃
}
class Date
{
public:
	Date(int year = 1999, int month = 2, int day = 2)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout<<"Date(int int int)"<<this<<endl;
	}
	Date(const Date& d)//拷贝构造函数
		:_year(d._year)
		,_day(d._day)
		,_month(d._month)
	{
		cout<<"Date(const Date& d)"<<this<<endl;
	}
	
	~Date()
	{
		cout<<"~Date()"<<this<<endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void Test3()
{
	Date d(2020, 2 , 2);
	vector<Date> vd;
	vd.resize(10,d);
	vd.resize(20);// 第二个参数如果没有传递，编译器会电泳Date()来构造一个匿名对象进行甜筒
				  // 类中一旦定义了构造函数，编译器就不会自动生成无参的构造函数
	
}
void Test4()
{
	vector<int> v1;
	v1.reserve(10);
	// 该行代码崩溃， 原因： reserve(10)只是将容量扩大，并不会增加有效元素的个数
	//访问0号位置的元素会出错
	cout<<v1[0]<<endl;

	vector<int> v2;
	v2.resize(10);
	cout<<v2[0]<<endl;
}
/*
	1.push_back再插入期间可能会扩容
	2.vector中扩容的机制是1.5倍
	3.扩容具体操作：开辟新空间、拷贝元素、释放旧空间
	随着元素不断地增加，每次扩容成本非常高
	因此在插入期间，尽量避免扩容

*/
void Test5()
{
	vector<int> v;
	v.reserve(100);
	size_t capacity = v.capacity();
	for(size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		if(capacity != v.capacity())
		{
			capacity = v.capacity();
			cout<<capacity<<endl;
		}
	}
	for(auto ch : v)
		cout<<ch<<" ";
	cout<<endl;

	Date d(2016,3,29);
	vector<Date> vd;
	vd.push_back(d);

	//C++11提供就地构造
	vd.emplace_back(2016,3,29);

}
void Test6()
{
	int array[] = {1,2,3,4,5};
	vector<int> v1(array,array+sizeof(array)/sizeof(array[0]));
	
	// 在3所在的位置插入0
	auto pos = find(v1.begin(),v1.end(),3);
	if(pos!=v1.end())
	v1.insert(pos,0);
	
	
}
void Test7()
{
	int array[] = {1,2,3,4,5};
	vector<int> v1(array,array+sizeof(array)/sizeof(array[0]));
	v1.erase(v1.begin());

	v1.erase(v1.begin(),v1.end());


}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	Test7();
	system("pause");
	return 0;
}