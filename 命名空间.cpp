#include <iostream>
#include <windows.h>
using namespace std;
//定义命名空间，需要使用到namespace关键字，后面跟命名空间的名字，然后接一对{}即可，{}中即为命名空间的成员。
// namespace 命名空间
//1 普通的命名空间
namespace  N1
{
	//命名空间中可以定义变量 函数
	int a = 10;
	int b = 10;

	int add(int a, int b )
	{
		return a+b;
	}
	////2. 命名空间可以嵌套
	namespace N3
	{
		int a = 30;
		int b = 30;


	}
}

namespace N2
{
	int a = 20;
	int b = 20;

	void Print()
	{
		cout<<"XML"<<endl;
	
	}
}
//3. 同一个工程中允许存在多个相同名称的命名空间,编译器后会合成同一个命名空间中
namespace N1
{
	int c = 10;

	void Print()
	{
	cout<<"这是第三中情况"<<endl;
	}
}
using N1::N3::a;

using namespace N1::N3;

int main()
{
	cout<<N1::a<<endl;
	cout<<N2::a<<endl;
	cout<<N1::N3::a<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
	int ret = N1::add(1,2);
	cout<<ret<<endl;
	//cou<<N1::add(1,2)::endl;
	N2::Print();
	cout<<N1::c<<endl;
	N1::Print();
		system("pause");
	return 0;
}