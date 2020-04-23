#pragma once
#include <iostream>
using namespace std;

//给出类的声明
class Person
{
	void InitPerson(char* name,char* genden,int age);
	void PrintPerson();

	char _name[20];
	char _gender[4];
	int _age;
};