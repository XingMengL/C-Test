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
#if 0
// 访问限定符
//面向对象三大特性：封装、继承、多态
//封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口和对象进行交互
//C++中通过类将数据和操作数据的方法包装起来
//使用访问权限：来控制那些方法可以在外部直接被调用
//访问限定符限制的是该成员是否能在类外直接使用，对类中访问没有限定
//一个类就是一个作用域
//C++作用域：全局作用域、函数体中的局部作用域、命名空间、类域
class student
{
public:
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
private:
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

	//cout<<s1._name<<endl;
	//cout<<s1._age<<endl;

	system("pause");
	return 0;
}
#endif
#if 0
//一个类就是一个作用域
//C++作用域：全局作用域、函数体中的局部作用域、命名空间、类域
void Testfunc()
{}
namespace N
{
	void Testfunc();
}

class student
{
public:
	void Testfunc()
	{
	
	}

};
//Testfunc隶属于不同的作用域，不够成函数重载
int main()
{
	system("pause");
	return 0;
}
#endif

#if 0
struct student{

	char _name[20];
	char _gender[4];
	int _age;
};
void SutdentInit(student* s,char* name,char* gender,int age)
{
	strcpy(s->_name,name);
	strcpy(s->_gender,gender);
	s->_age = age;
}

int main()
{
	student s1,s2;
	SutdentInit(&s1,"张三","男",36);

	return 0;
}
#endif
#if 0
class student{

public:
	void SutdentInit(char* name,char* gender,int age)
{
	cout<<this<<endl;
	strcpy(this->_name,name);
	strcpy(this->_gender,gender);
	this->_age = age;
}
	

private:
	char _name[20];
	char _gender[4];
	int _age;
};

int main()
{
	student s1,s2;
	s1.SutdentInit("张三","男",36);

	system("pause");

	return 0;
}
#endif

#if 0
class Data
{
public:
	//构成函数与类名相同，没有返回值
	Data(int year,int month,int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void InitData(int year,int month,int day)//初始化
	{
		_year = year;
		_month = month;
		_day = day;
		
	}
	void Print()
	{
		cout<<_year<<"/"<<_month<<"/"<<_day<<endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//Data b;			//没有定义构造函数，对象也可以创建成功，因此此处调用的是编译器生成的默认构造函数	
	Data a(2020,04,05);//构造函数可以在对象定义时就对其进行初始化
	a.Print();
	//Data b;          //编译报错  “Data”: 没有合适的默认构造函数可用，因为在类中定义了一个构造函数则编译器生成默认的构造函数
			           //则类中就没有合适的构造函数可用
	
	
	// 通过背后的汇编代码：
	// lea         ecx, [d]
	// call        Date::Date(0251357h): 在创建对象d期间确实调用构造函数
	system("pause");
	return 0;
}
#endif
#if 0
class Tim
{
public:
	Tim() //构造函数
	{
		cout<<"Tim()"<<endl;
		this->_hour = 0;
		this->_minute=0;
		this->_second =0;
	}
	~Tim()
	{
		cout<<"~Tim()"<<endl;
	}
private:
	int _hour;
	int _minute;    
	int _second; 
};
class Data
{
public:
	 Data(int year,int month,int day)//初始化函数
	{
		_year = year;
		_month = month;
		_day = day;
		
	}
	void Print()
	{
		cout<<_year<<"/"<<_month<<"/"<<_day<<endl;
	}
private:
	int _year;
	int _month;
	int _day;

	Tim _tim; //自定义类型  编译器生成默认的构造函数会对自定类型成员_tim调用的它的默认成员函数
 
};

int main()
{
	Data a(2020,04,25);
	a.Print();//
	
	system("pause");
	return 0;
}
#endif
#if 0
class A
{
public:
	A( )//无参的构造函数
	{
	cout<<"A( )默认构造函数"<<endl;
	}
	A(int a = 10 ,int b = 20)
	{
		cout<<"A( )默认构造函数"<<endl;
	}
// 默认的构造函数：
// 1. 用户定义的无参构造函数
// 2. 用户定义带有全缺省的构造函数---所有参数都带有默认值
// 3. 如果用户没有显式定义任何构造函数，编译器会自动生成一个无参的构造函数
// 默认的构造函数：只能存在一个



//个人理解：构造函数与默认构造函数 ： 默认构造函数是构造函数，构造函数不一定是默认构造函数
									  默认构造函数在对象的创建时不需要传参  A a; 类名 + 对象
									  构造函数在对象的创建时需要根据构造函数的参数列表传参  A a(...) 
};

int main()
{
	//A a();  // 使用无参构造函数创建对象时，不应在对象名后面加上括号  A a(void)”: 未调用原型函数(是否是有意用变量定义的?)
	A a;
	//A b;  //编译报错 

	
	system("pause");
	return 0;
}
#endif
#if 0
class Data
{
public:
	
	Data()
	{
		_year = 2020;
		_month = 5;
		_day = 1;
	}
	Data(int year,int month,int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void InitData(int year,int month,int day)//初始化
	{
		_year = year;
		_month = month;
		_day = day;
		
	}
	void Print()
	{
		cout<<_year<<"/"<<_month<<"/"<<_day<<endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data a;
    Data b(2020,4,25);
	
	

	system("pause");
    return 0;
}
#endif
#if 0
class XML{

public:
	XML()
	{
	
	}
//
	...
};

class XML{

public:
	XML(int a = 10,int b =10)
	{
	
	}
	//
	...
};

class XML{

	//
	...
};
#endif
#if 0
#pragma warning (disable:4018)
typedef int SQDataType;
class SeqList
{
public:
	 SeqList()
	{
		_array = (SQDataType*)malloc(sizeof(SQDataType)*10);
		if(nullptr == _array)
		{
			return;
		}
		_size = 0;
		_capacity = 10;
	}
	 void PushBack(const SQDataType& val)
	 {
		 _array[_size++] = val;
	 }
	 	void PopBack()
	{
		if (Empty())
			return;

		_size--;
	}

	size_t Size()
	{
		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}

	bool Empty()
	{
		return 0 == _size;
	}
		void PrintSeqList()
	{
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}

private:
	SQDataType* _array;
	int _size;
	int _capacity;
};

void TestSeqList()
{
	SeqList s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);

	cout << s.Size() << endl;
	cout << s.Capacity() << endl;

	s.PopBack();
	s.PrintSeqList();
}

int main()
{
	TestSeqList();

	system("pause");
	return 0;
}
#endif

class String{
	
public:
		String(char* str = "")//构造函数
		{
			cout<<this<<"String()"<<endl;
			_str = (char*)malloc(sizeof(char)*(strlen(str)+1));
			strcpy(_str,str);
		}
		~String()//析构函数   _str在堆上申请空间
		{
			if(_str)
			{
			 cout<<this<<"~String()"<<endl;
			 free(_str);
			 _str = nullptr;

			}
		
		}

private:
	char* _str;
};
class student{

public:
	/*student(char* name,char* gender,int age)//构造函数
{
	cout<<this<<endl;
	strcpy(_name,name);
	strcpy(_gender,gender);
	this->_age = age;
}*/
	student()
	{
	cout<<this<<"student"<<endl;
	
	}
   ~student()//析构函数：无返回值，无参，用来释放对象中的资源
			  //一个类中只能有一个析构函数，在对象的生命周期结束时，C++编译器会自动调用
   {
	   cout<<this<<"~student"<<endl;
              }
	

private:
	String _name;
	String  _gender;
	int _age;
};
void Test()
{
	
	String s1("hello");
	String s2("你好");
	student stu1;

}

int main()
{
	Test(); 
	system("pause");
}