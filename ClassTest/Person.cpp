#include "Person.h"
#pragma warning(disable:4996)
 
// 全面函数
void func(){}


//类的成员函数 
//类名 + :: + 函数名
void Person::InitPerson(char* name,char* gender,int age)
{
		strcpy(_name,name);
		strcpy(_gender,gender);
		_age = age;
}

void Person::PrintPerson()
{
	cout<<_name<<" "<<_gender<<" "<<_age<<endl;
}