#include <iostream>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4996)
using namespace std;

//C++�еĽṹ��
//C++��Ҳ�нṹ��   ��ΪҪ����C����
//C�����нṹ���в��ܶ��庯����C++����
//��student����ѧ����Ϣ������һ�������ѧ��

//��calss����һ���ࣺ sutdent��   structҲ���Զ�����
//�಻��һ�������ʵ�壬���Ƕ�ʵ�������
//student����һ�������ѧ�������Ƕ�ѧ��Ⱥ���һ������

//��Ķ��巽ʽһ������������Ͷ���ȫ���������н��ж���
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
	//��student�ṹ�嶨������Ľṹ�����͵ı���---����Ϊ�����ѧ��
	
	//��student��������ı���---->��֮Ϊ���󣬶������������ʵ��
	student s1,s2,s3;
	/*s1.InisStudent("����","Ů",21);
	s2.InisStudent("����","��",21);

	s1.Print();
	s2.Print();*/

	system("pause");
	return 0;
}
/*
�����ඨ�������
1.�����Ͷ���ֿ�-----��Ա���������ⶨ��ʱ������Ҫ�ڳ�Ա����ǰ���ϣ����� ::
2.��������Ͷ��嶼��������--���������ܻὫ��Ա����������������չ��
3.���齫�����Ͷ���ֿ�---Ϊ�˷�ֹ�ظ��ð���
*/
#endif
#if 0
// �����޶���
//��������������ԣ���װ���̳С���̬
//��װ�������ݺͲ������ݵķ��������л���ϣ����ض�������Ժ�ʵ��ϸ�ڣ������⹫���ӿںͶ�����н���
//C++��ͨ���ཫ���ݺͲ������ݵķ�����װ����
//ʹ�÷���Ȩ�ޣ���������Щ�����������ⲿֱ�ӱ�����
//�����޶������Ƶ��Ǹó�Ա�Ƿ���������ֱ��ʹ�ã������з���û���޶�
//һ�������һ��������
//C++������ȫ�������򡢺������еľֲ������������ռ䡢����
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
	s1.InisStudent("����","Ů",21);
	s2.InisStudent("����","��",21);

	s1.Print();
	s2.Print();

	//cout<<s1._name<<endl;
	//cout<<s1._age<<endl;

	system("pause");
	return 0;
}
#endif
#if 0
//һ�������һ��������
//C++������ȫ�������򡢺������еľֲ������������ռ䡢����
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
//Testfunc�����ڲ�ͬ�������򣬲����ɺ�������
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
	SutdentInit(&s1,"����","��",36);

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
	s1.SutdentInit("����","��",36);

	system("pause");

	return 0;
}
#endif

#if 0
class Data
{
public:
	//���ɺ�����������ͬ��û�з���ֵ
	Data(int year,int month,int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void InitData(int year,int month,int day)//��ʼ��
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
	//Data b;			//û�ж��幹�캯��������Ҳ���Դ����ɹ�����˴˴����õ��Ǳ��������ɵ�Ĭ�Ϲ��캯��	
	Data a(2020,04,05);//���캯�������ڶ�����ʱ�Ͷ�����г�ʼ��
	a.Print();
	//Data b;          //���뱨��  ��Data��: û�к��ʵ�Ĭ�Ϲ��캯�����ã���Ϊ�����ж�����һ�����캯�������������Ĭ�ϵĹ��캯��
			           //�����о�û�к��ʵĹ��캯������
	
	
	// ͨ������Ļ����룺
	// lea         ecx, [d]
	// call        Date::Date(0251357h): �ڴ�������d�ڼ�ȷʵ���ù��캯��
	system("pause");
	return 0;
}
#endif
#if 0
class Tim
{
public:
	Tim() //���캯��
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
	 Data(int year,int month,int day)//��ʼ������
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

	Tim _tim; //�Զ�������  ����������Ĭ�ϵĹ��캯������Զ����ͳ�Ա_tim���õ�����Ĭ�ϳ�Ա����
 
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
	A( )//�޲εĹ��캯��
	{
	cout<<"A( )Ĭ�Ϲ��캯��"<<endl;
	}
	A(int a = 10 ,int b = 20)
	{
		cout<<"A( )Ĭ�Ϲ��캯��"<<endl;
	}
// Ĭ�ϵĹ��캯����
// 1. �û�������޲ι��캯��
// 2. �û��������ȫȱʡ�Ĺ��캯��---���в���������Ĭ��ֵ
// 3. ����û�û����ʽ�����κι��캯�������������Զ�����һ���޲εĹ��캯��
// Ĭ�ϵĹ��캯����ֻ�ܴ���һ��



//�������⣺���캯����Ĭ�Ϲ��캯�� �� Ĭ�Ϲ��캯���ǹ��캯�������캯����һ����Ĭ�Ϲ��캯��
									  Ĭ�Ϲ��캯���ڶ���Ĵ���ʱ����Ҫ����  A a; ���� + ����
									  ���캯���ڶ���Ĵ���ʱ��Ҫ���ݹ��캯���Ĳ����б�����  A a(...) 
};

int main()
{
	//A a();  // ʹ���޲ι��캯����������ʱ����Ӧ�ڶ����������������  A a(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
	A a;
	//A b;  //���뱨�� 

	
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
	void InitData(int year,int month,int day)//��ʼ��
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

#if 0
class String{
	
public:
		String(char* str = "")//���캯��
		{
			cout<<this<<"String()"<<endl;
			_str = (char*)malloc(sizeof(char)*(strlen(str)+1));
			strcpy(_str,str);
		}
		~String()//��������   _str�ڶ�������ռ�
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
	/*student(char* name,char* gender,int age)//���캯��
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
   ~student()//�����������޷���ֵ���޲Σ������ͷŶ����е���Դ
			  //һ������ֻ����һ�������������ڶ�����������ڽ���ʱ��C++���������Զ�����
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
	String s2("���");
	student stu1;

}

int main()
{
	Test(); 
	system("pause");
}
#endif
#if 0
class Date
{
public:
	Date(int year = 2020,int month = 1,int day = 1)//Ĭ�Ϲ��캯��
		:_year(year)
		,_month(month)
		,_day(day)
	{
		
	}
	~Date()
	{
		cout<<this<<" "<<"~Date()"<<endl;
	}
	void Print()
	{	
		cout<<this<<" "<<_year<<" "<<_month<<" "<<_day<<" "<<endl;	
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Print();

	Date d2(d1);// ��δ��ʾ���壬ϵͳ����Ĭ�ϵĿ������캯����
				//Ĭ�ϵĿ������캯�������ڴ�洢���ֽ�����ɿ��������ֿ������ǽ���ǳ����������ֵ������
 
	d2.Print();

	system("pause");
	return 0;

}
#endif


#if 0
class String{
	
public:
		String(char* str = "")//���캯��
		{
			cout<<this<<"String()"<<endl;
			_str = (char*)malloc(sizeof(char)*(strlen(str)+1));
			strcpy(_str,str);
		}
		~String()//��������   _str�ڶ�������ռ�
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

void Test()
{
	String s1("hello");
	String s2(s1);
	//��String����û����ʽ�����������캯�������������Զ�����Ĭ�Ͽ������캯������һ�������е����ݿ������¶����У�
	//���ֿ�����ʽ��ֿ��ǳ��������Ҳ��ֵ������
	//ǳ�����ĺ�����������ͬʹ��һ����Դ������һ����Դ������ͷŴӶ��������ı���
}
int main()
{
	Test();
	system("pause");
	return 0;

}
#endif

#if 0
class String{
	
public:
		String(char* str = "")//���캯��
		{
			cout<<this<<"String()"<<endl;
			_str = (char*)malloc(sizeof(char)*(strlen(str)+1));
			strcpy(_str,str);
		}
		~String()//��������   _str�ڶ�������ռ�
		{
			if(_str)
			{
			 cout<<this<<"~String()"<<endl;
			 free(_str);
			 _str = nullptr;

			}
		}
		String(const String& s)
		{
			_str = (char*)malloc(sizeof(strlen(s._str+1)));
		}

private:
	char* _str;
};

void Test()
{
	String s1("hello");
	String s2;
}
int main()
{
	Test();
	system("pause");
	return 0;

}
#endif

#if 0
class Date
{
public:
	Date(int year = 2020,int month = 1,int day = 1)//Ĭ�Ϲ��캯��
		:_year(year)
		,_month(month)
		,_day(day)
	{
		
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month =d._month;
		_day = d._day;
		
	}
	~Date()
	{
		cout<<this<<" "<<"~Date()"<<endl;
	}
	void Print()
	{	
		cout<<this<<" "<<_year<<" "<<_month<<" "<<_day<<" "<<endl;	
	}

private:
	int _year;
	int _month;
	int _day;
};
void Test()
{
	Date d1;
	Date d2(d1);
	d2.Print();
}
Date func() //һ������ֵ���ݵķ�ʽ�Ӻ�������
{
	Date c;
	return c;
}
int main()
{
	Test();
	func();
	system("pause");
	return 0;

}
#endif

#if 0
class Date
{
public:
	Date(int year = 2020,int month = 1,int day = 1)//Ĭ�Ϲ��캯��
		:_year(year)
		,_month(month)
		,_day(day)
	{
		
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month =d._month;
		_day = d._day;
		
	}
	~Date()
	{
		cout<<this<<" "<<"~Date()"<<endl;
	}
	void Print()
	{	
		cout<<this<<" "<<_year<<" "<<_month<<" "<<_day<<" "<<endl;	
	}
	bool operator>(const Date& d)
	{
		return _year > d._year ||
			_year == d._year&& _month > d._month ||
			_year == d._year&&_month == d._month&&_day>d._day;
	} 
	bool operator==(const Date& d)
	{
		return _year ==d._year&&_month==d._month&&_day==d._day;
	}
	bool operator!=(const Date& d)
	{
		return !(*this==d);
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(2222,22,22);
	int ret = d2>d1;
	cout<<ret<<endl;
	system("pause");
	return 0;

}
#endif

#if 0
class Date
{
public:
	Date(int year = 2020,int month = 2,int day = 1)//Ĭ�Ϲ��캯��
		:_year(year)      //��ʼ���б�
		,_month(month)
		,_day(day)
	{
		
	}
	Date(const Date& d)//�������캯��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	~Date()//��������
	{

	}
	void Print()
	{
		cout<<_year<<"/"<<_month<<"/"<<_day<<endl;
	}
	//�ж��Ƿ�������1
	bool IsRyear()
	{
		if( ((0 == _year%4)&&(0 != _year%100)) ||(0 == _year %400) )
			return true;
		else
			return false;
	}
	//�ж������Ϸ�
	bool DaysAllow()
	{    
		if(_month == 1 ||_month == 3 ||_month == 5 ||_month == 7 ||_month == 8 ||
			_month == 10 ||_month == 12  )
		{
			if(_day<=31&&_day>0)
			{
				return true;
			}
			else 
				return false;
		}
		
		if(_month == 4 ||_month == 6 ||_month == 9 ||_month == 11 ||_month == 8 && _day <=30  )
		{
		
	       if(_day<=30&&_day>0)
			{
				return true;
			}
			else 
				return false;
			
		}
		if(IsRyear())//�Ƿ�����
		{
			//����
			//2��29��
			if(_day <= 29 && _day >0 &&_month == 2 )
				return true;
			else 
				return false;
		
		}
		else
		{
			//ƽ��
			if(_day <= 29 && _day >0 &&_month == 2 )
				return true;
			else 
				return false;
		
		
		}
		return false;
}
	//�·ݺϷ�
bool MonthAllow()
{
		if(_month < 12 && _month >0)//�Ϸ�
		{
			return true;
		}
		else
			return false;
	}
	bool operator==(const Date& d)
	{
		return _year ==d._year&&_month==d._month&&_day==d._day;
	}
	bool operator!=(const Date& d)
	{
		return!(*this==d);
}
	//������ж�����
int Days(int month)
{
		if(month == 1 ||month == 3 ||month == 5 ||month == 7 ||month == 8 ||
			month == 10 ||month == 12 )
			return 31;
		else if(month == 4 ||month == 6 ||month == 9 ||month == 11  )
			return 30;
		if(IsRyear())//�Ƿ�����
			return 29;	
		else 
			return 28;
}	
	//��ֵ
	Date& operator=(const Date& d)//��ֵ���������
		//���� ��ѡ��ʹ�����ô��� �� ���ε�Ч�ʸ�
{
		if(*this!=d)
		{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		}
		return *this;
		//����ֵ��  һ��Ҫ�з���ֵ��������������ֵ
		//a=b=c;----> c--->b  b---->a
}
	
	//��days��֮�������
	Date operator+=(int day)
{
		Date temp(*this);//����һ����ʱ�Ķ���

			for(int i = 0; i < day; i++)
			{
				 temp._day++; //��һ��
				if(!temp.DaysAllow())//���Ϸ�  �·ݽ�1 ��������
				{
					temp._day = 1;
					temp._month += 1;
					if(!temp.MonthAllow())//�·ݲ��Ϸ�
					{
						temp._year+=1;
					   temp._month = 1;	
					}
				}
			}
			return temp;
}
	//��days��֮ǰ������
Date operator-=(int day)
{
		Date temp(*this);//������ʱ����
		for(int i =0; i < day; i++)
		{
			temp._day-=1;
			if(!temp.DaysAllow())//�������Ϸ�
			{	
				temp._month-=1;
				temp._day =Days(temp._month) ;
			
				if(!temp.MonthAllow())//�·ݲ��Ϸ�
					{
						temp._year-=1;
					   temp._month = 12;	
					}
			}
		
		}
			return temp;
}
//ǰ��++
Date& operator++()
{
	_day+=1;
	return *this;
}
//����++
Date operator++(int)
{
	Date temp(*this);
	_day += 1;
	return temp;
}
//ǰ��--
Date& operator--()
{
	_day-=1;
	return *this;
}
Date operator--(int)
{
	Date temp(*this);
	_day-=1;
	return temp;
}
bool operator>(const Date& d)
{
	
	
		return _year > d._year ||
			_year==d._year && _month > d._month ||
			_year==d._year && _month == d._month || _day > d._day;
	
}
bool operator <(const Date& d)
{
	return *this!=d && !(*this > d);
}
bool operator>=(const Date& d)
{
	return _year >= d._year ||
			_year==d._year && _month >= d._month ||
			_year==d._year && _month == d._month || _day >= d._day;
	
}
bool operator<=(const Date& d)
{
	return _year <= d._year ||
			_year==d._year && _month <= d._month ||
			_year==d._year && _month == d._month || _day <= d._day;
}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2000,2,1);
	Date d2(2020,2,2);
	int ret;
	ret = d1 > d2;
	int a = d1<d2;
	cout<<ret<<endl;
	cout<<a<<endl;

	
	
	system("pause");
	return 0;
}
#endif

#if 0
class Func
{
public:
	Func()
	{
		_a = 10;
	}
	void set()const
	{
		cout<<"set()const"<<endl;
	}
private:
	int _a;

};
int main()
{
    Func a;
	a.set();

	system("pause");
	return 0;
}
#endif

#if 0
class Time
{
public:
	///*Time(int hour = 10,int minute = 10,int second = 10)
	//	:_hour(hour)
	//	,_minute(minute)
	//	,_second(second)
	//{
	//	cout<<"Ĭ�Ϲ��캯��"<<endl;
	//}*/
private:
	int _hour;
	int _minute;
	int _second;
};
//�����Ա�����д����Զ������͵ģ�
class Date
{
public:
	Date(int year = 2020)
		:_year(year)
		,_ra(year)
		//_t(0,0,0)
	{
		//���캯���岻�ǳ�ʼ���Ǹ�ֵ
		
	}
private:
	int _year;
	Time _t;
	int& _ra;
};
int main()
{
	Date d;

	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	// ���캯�����ã�������һ������
	Date(int year = 1970, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
		//, count(0)
	{
		count++;
		cout << "Date(int,int,int):" << this << endl;
	}

	// �������캯������������
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		count++;
		cout << "Date(const Date&):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << " = " << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	~Date()
	{
		count--;
		cout << "~Date():" << this << endl;
	}

	void PrintDate()const
	{
		cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

public:
	// static���εĳ�Ա����---��Ϊ��̬��Ա���� 
	static int count;  // ע�⣺��̬��Ա����������ֻ������������Ҫ��������г�ʼ��
};

// ��̬��Ա�����ĳ�ʼ��
// ע�⣺��̬��Ա������������г�ʼ��ʱ����Ҫ����static�ؼ���
int Date::count = 0;


void TestDate()
{
	// ��û�д���d1��d2֮ǰ����Ҫ֪�����ڴ����˶��ٸ�����
	// ��̬��Ա�������Բ�ͨ��������ʣ�ֱ��ʹ������::��̬��Ա��������
	cout << Date::count << endl;

	Date d1;
	Date d2(d1);
	cout << d1.count << endl;
	cout << d2.count << endl;
}

int main()
{
	Date d1;
	Date d2(d1);

	// d1��d2����ʹ�õ���ͬһ��count---count�ܹ���ֻ��һ�ݣ������ж�������һ����Ա
	cout << &d1.count << " " << &d2.count << endl;

	// 12-->˵����̬��Ա����û�д洢�ڶ���Ŀռ���
	cout << sizeof(Date) << endl;
	TestDate();

	return 0;
}
#endif

class Date
{
public:
	// ���캯�����ã�������һ������
	Date(int year = 1970, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
		//, count(0)
	{
		count++;
		cout << "Date(int,int,int):" << this << endl;
	}

	// �������캯������������
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		count++;
		cout << "Date(const Date&):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << " = " << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	~Date()
	{
		count--;
		cout << "~Date():" << this << endl;
	}

	void PrintDate()const
	{
		count = 1000;
		cout<<count<<endl;
		cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

public:
	// static���εĳ�Ա����---��Ϊ��̬��Ա���� 
	static int count;  // ע�⣺��̬��Ա����������ֻ������������Ҫ��������г�ʼ��
};

// ��̬��Ա�����ĳ�ʼ��
// ע�⣺��̬��Ա������������г�ʼ��ʱ����Ҫ����static�ؼ���
int Date::count = 0;


void TestDate()
{
	// ��û�д���d1��d2֮ǰ����Ҫ֪�����ڴ����˶��ٸ�����
	// ��̬��Ա�������Բ�ͨ��������ʣ�ֱ��ʹ������::��̬��Ա��������
	cout << Date::count << endl;

	Date d1;
	Date d2(d1);
	cout << d1.count << endl;
	cout << d2.count << endl;
}

int main()
{
	Date d1;
	Date d2(d1);

	// d1��d2����ʹ�õ���ͬһ��count---count�ܹ���ֻ��һ�ݣ������ж�������һ����Ա
	cout << &d1.count << " " << &d2.count << endl;

	// 12-->˵����̬��Ա����û�д洢�ڶ���Ŀռ���
	cout << sizeof(Date) << endl;
	TestDate();
	d1.PrintDate();
	system("pause");

	return 0;
}