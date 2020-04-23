#include <iostream>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4996)
using namespace std;

//C++中的结构体
//C++中也有结构体   因为要兼容C语言
//C语言中结构体中不能定义函数，C++可以
//用student描述学生信息，不是一个具体的学生

//用calss定义一个类： sutdent类   struct也可以定义类
//类不是一个具体的实体，它是对实体的描述
//student不是一个具体的学生，而是对学生群体的一种描述

//类的定义方式一：将类的声明和定义全部放在类中进行定义
#if 0
class/*struct*/ student
{
	char _name[20];
	char _gender[4];
	int _age;

	void InisStudent(char* name,char* gender,int age)
	{
		strcpy(_name,name);
		strcpy(_gender,gender);
		_age = age;
	}


	void Print()
	{
		cout<<_name<<" "<<_gender<<" "<<_age<<endl;
	}

};
int main()
{
	//用student结构体定义出来的结构体类型的变量---》称为具体的学生
	
	//用student定义出来的变量---->称之为对象，对象才是真正的实体
	student s1,s2,s3;
	/*s1.InisStudent("静娃","女",21);
	s2.InisStudent("龙哥","男",21);

	s1.Print();
	s2.Print();*/

	system("pause");
	return 0;
}
/*
两种类定义的区别：
1.声明和定义分开-----成员函数在类外定义时，必须要在成员函数前加上：类名 ::
2.如果声明和定义都放在类中--编译器可能会将成员函数当成内联函数展开
3.建议将声明和定义分开---为了防止重复得包含
*/
#endif

// 访问限定符
//面向对象三大特性：封装、继承、多态
//封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口和对象进行交互
//C++中通过类将数据和操作数据的方法包装起来
//使用访问权限：来控制那些方法可以在外部直接被调用
class student
{
public://
	void InisStudent(char* name,char* gender,int age)
	{
		strcpy(_name,name);
		strcpy(_gender,gender);
		_age = age;
	}


	void Print()
	{
		cout<<_name<<" "<<_gender<<" "<<_age<<endl;
	}
private://
	char _name[20];
	char _gender[4];
protected:
	int _age;

};
int main()
{

	student s1,s2,s3;
	s1.InisStudent("静娃","女",21);
	s2.InisStudent("龙哥","男",21);

	s1.Print();
	s2.Print();

	cout<<s1._name<<endl;
	cout<<s1._age<<endl;

	system("pause");
	return 0;
}