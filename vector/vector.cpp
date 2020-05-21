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

	//STL�����е�������������ҿ���
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

	//C++���������б��ĳ�ʼ��
	//vector<int> v7{1,2,3,4,5};  �������汾��֧��
	
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

	v1.reserve(20);//�ڶ���û�д���ʱʹ��Ĭ��ֵ0�������
	for( auto ch: v1)
		cout<<ch<<" ";
	cout<<endl;

	v1.reserve(8);
	for( auto ch: v1)
		cout<<ch<<" ";
	cout<<endl;

	// reserve ���� ������С����
	// resize 
	// �������� 
	// �Զ������� ---- Ҫ��Ĭ�Ϲ��캯�� ��Ȼ�����
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
	Date(const Date& d)//�������캯��
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
	vd.resize(20);// �ڶ����������û�д��ݣ����������ӾDate()������һ���������������Ͳ
				  // ����һ�������˹��캯�����������Ͳ����Զ������޲εĹ��캯��
	
}
void Test4()
{
	vector<int> v1;
	v1.reserve(10);
	// ���д�������� ԭ�� reserve(10)ֻ�ǽ��������󣬲�����������ЧԪ�صĸ���
	//����0��λ�õ�Ԫ�ػ����
	cout<<v1[0]<<endl;

	vector<int> v2;
	v2.resize(10);
	cout<<v2[0]<<endl;
}
/*
	1.push_back�ٲ����ڼ���ܻ�����
	2.vector�����ݵĻ�����1.5��
	3.���ݾ�������������¿ռ䡢����Ԫ�ء��ͷžɿռ�
	����Ԫ�ز��ϵ����ӣ�ÿ�����ݳɱ��ǳ���
	����ڲ����ڼ䣬������������

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

	//C++11�ṩ�͵ع���
	vd.emplace_back(2016,3,29);

}
void Test6()
{
	int array[] = {1,2,3,4,5};
	vector<int> v1(array,array+sizeof(array)/sizeof(array[0]));
	
	// ��3���ڵ�λ�ò���0
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
//������ʧЧ

// ԭ��vector���������ݣ��������¿ռ䣬���µ�������һ��Ұָ�� 
void Test8()
{
	int array[] = {1,2,3,4,5};
	vector<int> v1(array,array+sizeof(array)/sizeof(array[0]));
	auto it = v1.begin();
	//v1.resize(10);
	//v1.push_back(6);
	//v1.reserve(10);

	while(it != v1.end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
}
void Test9()
{
	int array[] = {1,2,3,4,5,6,7,8,9,0};
	vector<int> v1(array,array+sizeof(array)/sizeof(array[0]));

	//��Ҫ��vectoe�е�ż��ɾ��
	auto it = v1.begin();
	while(it != v1.end())
	{
		if(*it%2 == 0)
		{
			v1.erase(it);
		}
		else
			++it;
	}
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	Test9();
	system("pause");
	return 0;
}