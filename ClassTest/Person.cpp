#include "Person.h"
#pragma warning(disable:4996)
 
// ȫ�溯��
void func(){}


//��ĳ�Ա���� 
//���� + :: + ������
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