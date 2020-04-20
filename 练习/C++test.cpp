
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
/*//定义命名空间，需要使用到namespace关键字，后面跟命名空间的名字，然后接一对{}即可，{}中即为命名空间的成员。
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
*/

//void test(int a = 10);
#if 0 
int main()
{
	int a;
	int& ra =a;
	int& raa =ra;
	raa = 10;
	cout<<a<<endl;
	///test(10);
	return 0;

}
#endif
#if 0
#include <iostream>

int add(int a = 10, int b = 20)
{

    return a + b;
}
double add(double a, double b = 1.3)
{
	return a + b;
}
int main()
{

	cout<<add(1.2)<<endl;
	cout<<add(1,2)<<endl;
	system("pause");
    return 0;
}
#endif
#if 0 
#include <iostream>
using namespace std;
int add(int a, int b = 10)
{
    return a+b;
}
int main()
{
     cout<<add(1)<<endl;
	 system("pause");
    return 0;
}
#endif
#if 0
int add(int a, int b)
{
	return a + b;
}

double add(double a, double b )
{
	return a + b;
}
int main()
{

	cout<<add(1,1)<<endl; //int int --->调用add(int a , int b)
	cout<<add('a','b')<<endl;//上述中没有定义字符类的加法函数，char和int可以隐式转换 char char --> int int调用add(int a, int b)
	cout<<add(1,1.3)<<endl;//int double 上述也没有这种加法函数，int double ---> int int 或 double double  编译器不知道调用那个函数，直接报错
	system("pause");
}
#endif
#if 0
//int add(int a,int b);
//int add(int a , double b);
int add(double a, double b);

int main()
{
	add(1,2);
	return 0;
}
#endif
#if 0
int main()
{
	int a = 10;
	int& ra = a;
	
	cout<<a<<endl;
	cout<<ra<<endl;

	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int a = 10;
	int b = 20;
	int& ra = a;//引用一个实体后不能在引用别的实体
	cout<<a<<endl;
	cout<<ra<<endl;
	ra = b;//赋值 不是引用  a ra 都是20
	cout<<a<<endl;
	cout<<ra<<endl;

	system("pause");
	return 0;
	
}
#endif
#if 0 
int main()
{
	//int& a = 10;  编译报错 10 是常量
	const int& ra = 10;
	const int b = 10;
	//int& rb = b;  编译报错 b是一个常量
	const int& rb = b; 
	int aa = 10;
	int bb = 20;
	int cc = aa + bb;
	//int& rcc = aa+bb;//非常量引用的初始值必须为左值
	//个人理解 ： 非常量引用 引用的实体必须有左值（地址值）编译器会对实体进行检测 判断是否有左值
	//cout<<cc<<endl;
	const int& raa = aa;
	aa = 40; // aa = 40  raa = 40
	//raa = 40;  //编译报错 表达式必须是可被修改的左值
	cout<<" "<<endl;
	cout<<aa<<" "<<raa<<endl;
	cout<<&aa<<" "<<&raa<<endl;


	system("pause");
	return 0;
}
#endif

/*int main()
{
	double  a = 13.4;
	const int& ra = a;

	cout<<a<<" "<<ra<<endl;// a = 13.4 ra = 13
	
	a = 20.6;
	
	cout<<a<<" "<<ra<<endl; //a = 20.6 ra = 13


	system("pause");
	return 0;
}*/
#if 0
//引用做参数 相当于传地址 可以通过形参改变外部的实参
void Add(int& left,int& right)
{
	int temp = left;
	left = right;
	right = left;
}
int main()
{
	int a = 10;
	int b = 20;
	cout<<a<<b<<endl;
	Add(a, b);
	cout<<a<<b<<endl;

	system("pause");
	return 0;
}
#endif

#if 0
//引用做为返回值  
//以引用返回函数值，定义函数时需要在函数名前加 &
int& add(int a, int b)
{
	int c = a+ b;
	return c;
	//return a + b// 编译报错  a+b不是左值 （表达式 常量 没有左值）
}
int& Count()
{
	static int n = 0;
	n++;

	return n;
}
int main()
{
	int& ret = add(1,2);//不能返回局部变量的引用。主要原因是局部变量会在函数返回后被销毁，
	                   //因此被返回的引用就成为了"无所指"的引用，程序会进入未知状态。
	int& r = Count();
	cout<<r<<endl;
	cout<<r<<endl;
	cout<<r<<endl;
	//printf("\n");
	//cout<<ret<<endl;
	//cout<<ret<<endl;
	system("pause");
	return 0;
	//如果函数返回时，出了函数作用域，如果返回对象还未还给系统，则可以使用引用返回，
	//如果已 经还给系统了，则必须使用传值返回。

}
#endif
#include <time.h>

 struct test
{
	int array[100000];
};

void Func1(test T){}//传值
void Func2(test& T){}//传引用
void Func3(test* T){}

void TestRefAndValue()
{
	test T;
	     //传值测试
	//size_t begin1 = clock();
	//for(size_t i = 0; i < 1000000; i++)
	//	Func1(T);
	//size_t end1 = clock();
    //  cout<<end1 - begin1<<endl;
	    //传引用测试
	size_t begin1 = clock();
	for(size_t i = 0; i < 1000000; i++)
		Func2(T);
	 size_t end1 = clock();
	cout<<end1 - begin1<<endl;
		//传指针测试
	 begin1 = clock();
	for(size_t i = 0; i < 1000000; i++)
		Func3(&T);
	 end1 = clock();
	cout<<end1 - begin1<<endl;
	
	
}
int main()
{
	TestRefAndValue();
	system("pause");
	return 0;
}

