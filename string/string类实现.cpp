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

#if 0
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
		//传统写法
		/*
		//拷贝构造函数
		string(const string& s)
			:_str(new char [strlen(s._str)]+1) // 
		{
			strcpy(_str,s._str);
		}
		*/

		//简洁写法
		//拷贝构造函数
		string(const string& s)
		{
			string strtemp(s._str);
			swap(_str, strtemp._str);

		}


		// 传统写法
		/*
		string& operator=(const string& s)
		{
			if(this!= &s)
			{
				//重新开辟空间
				//将s2空间中的内容拷贝到新的空间中
				//将s1中旧空间释放掉
				//让s1指向新空间
				char* temp = new char[strlen(s._str)+1];
				strcpy(temp,s._str);
				delete [] _str;
				_str = temp;
			}
			return *this;
		}*/

		string& operator=(string s)//传参值拷贝 
		{
			swap(_str,s._str);
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

#if 0
#include <stdio.h>


int area(int r)
{
	return r*r*3.14;
}
/*double fun()
{
	int i = 0;
	double sum = 0;
	for(i = 1;i <=20;i++)
	{
		sum += (i/(2*i+1));
	
	}
	return sum;
}*/
int main() 
{
	double i = 0;
	double sum = 0;
	for(i = 1; i <= 20; i++)
	{
		sum += i/(2*i+1);
		
	}

	system("pause");
	return 0;
}
#endif

#include <string.h>
namespace xml
{
	class String
	{
	public:
		String(const char* s = "")
		{
			if(s == nullptr)
			{
				_str = "";
			}
			else
			{
				_str = new char[strlen(s)+1];  // 分配空间
				strcpy(_str,s);

			}
		}
		// 浅拷贝
		/*String(const String& s)
			:_str(s._str)
		{
		
		}*/
		
		// 深拷贝
		/*String(const String& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str,s._str);
		}*/
		String(const String& s)
		{
			String temp(s._str); // String temp("字符串")；
			//String temp("qwer");
			swap(_str,temp._str);
		}

		// 浅拷贝
		/*String& operator=(const String& s)
		{
			_str = s._str;
			return *this;
		}*/
		String& operator=(const String& s)
		{
			if(*this != &s)
			{
			
			}
		
		}
		~String()
		{
			delete [] _str;
			_str = nullptr;
		}
	
	private:
		char* _str;
	};


}

int main()
{
	xml::String s1("qwer");
	xml::String s2(s1);

}
