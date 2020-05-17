#include <iostream>
#include <windows.h>
using namespace std;
#pragma warning (disable:4996)

#if 0
// 反例
namespace String
{
	class string
	{
	public:
		/*
		string(const char* str = "")//构造函数
		{
			if(nullptr == str)
			{
				//构造空的字符串：是一个有效的字符串，只有一个‘\0’
				_str = new char[1];
				//将\0放置字符空间中
				*_str = '\0';
			}
			else
			{
				//多申请一个空间用来存放\0
				_str = new char[strlen(str)+1];
				strcpy(_str,str);
			}
			
		}*/

		string(const char* str = "")
		{
			if(nullptr == str)
			{
				str = "";
			}
			else
			{
				_str = new char[strlen(str)+1];
				strcpy(_str,str);
			}
		}

		//拷贝构造函数
		string(const string& s)
			:_str(s._str)
		{

		}
		string operator=(const string& s)
		{
			_str = s._str;
			return *this;
		}
		~string()//析构函数
		{

			delete [] _str;
			_str = nullptr;
		}

	private:
		char* _str;

	};


}

void Test1()
{
	String:: string s1;
	String::string s2("nihao");
	String::string s3(s2);

}

int main()
{
	Test1();
	system("pause");
	return 0;
}
#endif

namespace String
{
	class string
	{
	public:
		/*
		string(const char* str = "")//构造函数
		{
			if(nullptr == str)
			{
				//构造空的字符串：是一个有效的字符串，只有一个‘\0’
				_str = new char[1];
				//将\0放置字符空间中
				*_str = '\0';
			}
			else
			{
				//多申请一个空间用来存放\0
				_str = new char[strlen(str)+1];
				strcpy(_str,str);
			}
			
		}*/

		string(const char* str = "")
		{
			if(nullptr == str)
			{
				str = "";
			}
			else
			{
				_str = new char[strlen(str)+1];
				strcpy(_str,str);
			}
		}

		//拷贝构造函数
		string(const string& s)
			:_str(new char [strlen(s._str)]+1) // 
		{
			strcpy(_str,s._str);
		}
		string operator=(const string& s)
		{
			_str = s._str;
			return *this;
		}
		~string()//析构函数
		{

			delete [] _str;
			_str = nullptr;
		}

	private:
		char* _str;

	};


}

void Test1()
{
	String:: string s1;
	String::string s2("nihao");
	String::string s3(s2);

}

int main()
{
	Test1();
	system("pause");
	return 0;
}