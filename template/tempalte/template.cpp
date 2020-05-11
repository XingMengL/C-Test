#include <iostream>
#include <windows.h>
using namespace std;

#if 0
template <typename T> //模板参数列表
T Add(T left,T right)  //参数列表
{
	return left + right;
}
#endif

#if 0 
template <typename T>
T Add(T left, T right)
{
	return left + right;
}

int Add(int left,int right)
{
	return left +  right;
}

int main()
{
	cout<<Add(1,2)<<endl;
	cout<<Add(1.0,2.0)<<endl;//普通方法发生了隐式类型转化

	system("pause");
	return 0;
}
#endif

#if 0
template <typename T,typename U>

U Add(T left, U right)
{
	return left + right;
}

int main()
{
  Add(1,2);
  Add(2.0,1.0);
  Add(1,1.0);
  Add('1', '2');

  system("pause");
}
#endif

#if 0
// 函数模板的实例化 ---隐式实例化和显式实例化
// 函数模板--不是真正的函数，只是一个编译器生成代码的模具，程序员给编译器生成代码的以一种规则

/*
在编译器中，通过调试代码发现：Add(1,2)和Add(1.0, 2.0)都调用了函数模板--->说法是错误
不能调用函数模板---函数模板不是一个真正函数，它只是编译器生成代码的工具
*/

/*
函数模板的原理：
 编译器在编译代码是，如果检测到对函数模板进行实例化：
 隐式实例化：编译器首先会对参数类型进行推演，用推演的结果替换模板参数列表中的T，最后生成具体对应类型的函数参数共用户调用
   注意：参数类型不能完全匹配时，编译器不会发生隐式类型转化，而是直接报错

显式实例化：明确指定模板参数列表中T的实际类型
  编译器在编译代码时，如果发现是显式实例化--->直接生成代码，如果参数类型不匹配，会尝试进行饮食类型转换
  如果转换成功，就通过编译，如果转化失败则报错   
*/
template <class T>
T ADD(T left, T right)
{
	return left + right;
}

template <class T2 ,class U>
T2 ADD(T2 left, U right)
{
	return left + right;
}

class Date
{
private:
	int year;
	int month;
	int day;
};

int main()
{
	//隐式实例化-----调用ADD函数
	cout<<ADD(1,2)<<endl;  // int int  --- T --> int -->生成一份整形类型的ADD函数
	cout<<ADD(1.0,2.0)<<endl; //double double --T --double--生成一份浮点类型的ADD函数
	ADD(1,1.2);// int  double    结果是 int 发生精度缺失
	
	
	//显式实例化  --- 明确指定模板参数列表中T的实际类型
	ADD<int>(1,1.2);// int  
	ADD<double>(1,1.2);// double

	Date d;
	//cout<<ADD<int>(1, d);
	system("pause");
	 return 0;
}
#endif

#if 0
template <class T>
T ADD(T left, T right)
{
	return left + right;
}

int main()
{

	ADD(1,2.0);  // 编译器报错 原因：对函数模板实例化进行类型推演时， 参数的类型不能完全匹配，
	             // 编译器不会对参数类型进行隐式类型转化  直接报错
	system("pause");
	return 0;
}
#endif

#if 0
// 注意： 在模板中，一般情况下传递参数都是引用，如果不想通过形参改变外部实参，传递const类型引用
//       因为：T可能是自定义类型
template <class T>
T ADD(const T& left, const T& right)
{
	return left + right;
}

int ADD(const int& left, const int& right)
{
	return left + right;
}

int main()
{
	ADD(1, 2);         // 优先调用普通类型的函数
	ADD<int>(1, 2);    // 如果进行了显式实例化，编译器就会根据模板来生成一份int类型的Add函数
	/*
	注意：模板生成的int类型的Add函数不会和普通函数冲突
	int Add<int>(const int& left, const int& right)
	{
	    return left + right;
	}
	*/
	system("pause");
	return 0;
}
#endif

template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)//
	{
		//默认容量为10
		_array = new T[capacity];
		_capacity = capacity;
		_size = 0;

	}
	void PushBack(const T& data);
	void PopBack();
	~SeqList()
	{
		if(_array)
		{
		delete[] _array;
		_array = nullptr;
		_size = 0;
		_capacity = 0;
		}
	}
		size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

private:
	T* _array;
	size_t _size;//有效个数
	size_t _capacity;//容量
};
template<class T>
void SeqList<T>::PushBack(const T& data)
{
	//检测扩容
	_array[_size++]  = data;
}
template<class T>
void SeqList<T>::PopBack()
{
	if (Empty())
			return;

		--_size;
}
int main()
{
		/*
	SeqList<int>--->将SeqList的类模板实例化为int，编译器在编译阶段就会生成一份专门来存储int的顺序表的代码
	*/
	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);

	cout << s1[0] << endl;

	// SeqList<double>--->将SeqList的类模板实例化为double，编译器在编译阶段就会生成一份专门来存储double的顺序表的代码
	SeqList<double> s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);

	// 第二次再将SeqList实例化为int，编译器将不会再生成一份int类型的顺序表的代码了，因为s1实例化时候已经生成一份处理int的顺序表的代码了
	SeqList<int> s3;
	return 0;
	system("pause");
	return 0;
}