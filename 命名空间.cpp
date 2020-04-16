/*
设想一下现在有一个上万行的代码，现在要求在它的基础上在实现新的函数，
在这个过程中难免会遇到变量，函数的名称冲突，这不但会增加工作量，
而且有些错误是不会报错的这就会造成不可预料的灾难，为了解决变量，
函数的名称冲突C++使用命名空间是标识符的名称进行本地化，以避免命名冲突或名字 污染，
namespace关键字的出现就是针对这种问题的。
*/
/*
命名空间的使用
在定义命名空间后应该怎么使用命名空间中的成员？
1.使用作用域限定符“::”： 命名空间名称 + 作用域符 
类似与结构体成员访问符号 “圆点运算符”和“箭头运算符”           
2.使用using将命名空间中成员引入
  在using将成员引入后，成员就可以直接使用不需要用作用域限定符说明是哪个命名空间中的成员变量
3.使用using namespace将命名空间引入
将命名空间引入，那么命名空间中的成员变量、函数都可以直接使用
*/

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
