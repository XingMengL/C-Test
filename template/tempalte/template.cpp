#include <iostream>
#include <windows.h>
using namespace std;

#if 0
template <typename T> //模板参数列表
T Add(T left,T right)  //参数列表
{
	return left + right;
}
#endif

#if 0 
template <typename T>
T Add(T left, T right)
{
	return left + right;
}

int Add(int left,int right)
{
	return left +  right;
}

int main()
{
	cout<<Add(1,2)<<endl;
	cout<<Add(1.0,2.0)<<endl;//普通方法发生了隐式类型转化

	system("pause");
	return 0;
}
#endif

#if 0
template <typename T,typename U>

U Add(T left, U right)
{
	return left + right;
}

int main()
{
  Add(1,2);
  Add(2.0,1.0);
  Add(1,1.0);
  Add('1', '2');

  system("pause");
}
#endif

//函数模板的实例化

template <class T>
T ADD(T left, T right)
{
	return left + right;
}

template <class T2 ,class U>
T2 ADD(T2 left, U right)
{
	return left + right;
}

class Date
{
private:
	int year;
	int month;
	int day;
};

int main()
{
	//隐式实例化-----调用ADD函数
	cout<<ADD(1,2)<<endl;  // int int  --- T --> int -->生成一份整形类型的ADD函数
	cout<<ADD(1.0,2.0)<<endl; //double double --T --double--生成一份浮点类型的ADD函数
	ADD(1,1.2);// int  double    结果是 int 发生精度缺失
	
	
	//显式实例化  --- 明确指定模板参数列表中T的实际类型
	ADD<int>(1,1.2);// int  
	ADD<double>(1,1.2);// double

	Date d;
	//cout<<ADD<int>(1, d);
	system("pause");
	 return 0;
}