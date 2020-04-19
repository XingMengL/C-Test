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
	//cout<<add(1.2,1.3)<<endl;
	system("pause");
}
