#pragma once
#include <iostream>
using namespace std;

//�����������
class Person
{
	void InitPerson(char* name,char* genden,int age);
	void PrintPerson();

	char _name[20];
	char _gender[4];
	int _age;
};