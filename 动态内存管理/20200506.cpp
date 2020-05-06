#include <iostream>
#include <windows.h>
using namespace std;

// C++中为什么要重新实现一套动态内存管理？
// 首先：C语言中的动态内存管理方式在C++中仍旧可以使用
// 原因1：C语言中的方式使用比较麻烦 malloc calloc realloc
// 原因2：malloc/free不会调用构造函数和析构函数 new/delete在进行空间申请和释放时会调用对象的构造函数和析构函数

// C++中的动态内存管理方式：
// new delete  单个空间 
// new[] delete[]   连续的空间

// 注意：new是C++中的关键字 malloc是C语言中的库函数


class A
{
public:
	A(int t )
		:_t(t)
	{
		cout<<"A()"<<this<<endl;
	}
	~A()
	{
		cout<<"~A()"<<this<<endl;
	}

private:
	int _t;
};

// new/delete和new[]/delete[]的使用
void test1()
{
	int* p1 = new int;  
	int* p2 = new int(100);
	int* p3 = new int[10];
	//int* p4 = new int[10]{1,2,3,4,5,6,7,8,9,0};  vs2012不支持

	delete p1;
	delete p2;
	delete p3;
}
void test2()
{
	// 注意：malloc并不是创建了一个A类型对象 只是在堆上申请了一个和A类型对象大小相等的堆空间
	// 因为： malloc 不会调用构造函数
	A* pt1 = (A*)malloc(sizeof(A)); // malloc 不会调用构造函数
	if(nullptr == pt1)
		return;
	// new 真正创建了一个对象，该对象的空间在堆上
	A* pt2 = new A(10); // new在申请空间会调用构造函数

	free(pt1);// free不会调用析构函数
	delete pt2;// delete会调用对象的析构函数
	
}
/* 
 在C++中 ，如果想要在堆上申请空间：
 1. 采用malloc/calloc/realloc，不能申请对象的空间
 2. 采用new/new[] 可以调用构造函数能申请对象空间，注意：如果使用new[]申请连续的空间时，该类必须提供默认构造函数
*/
int main()
{
	test2();

	system("pause");
	return 0;
}