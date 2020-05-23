#include <iostream>
using namespace std;

#include <windows.h>


#include <list>
#include <vector>
void Test1()
{
	list<int> l1();

	list<int> l2(10,1);

	auto it = l2.begin();
	while(it != l2.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	
	list<int> l3(l2);
	for(auto ch: l3)
		cout<<ch<<" ";
	cout<<endl;

	vector<int> v(10,2);
	list<int> l4(v.begin(),v.end());
	for(auto ch: l4)
		cout<<ch<<" ";
	cout<<endl;

	int array[] = {1,2,3,4,5};
	list<int> l5(array,array+sizeof(array)/sizeof(array[0]));
	for(auto ch: l5)
		cout<<ch<<" ";
	cout<<endl;

}
void Test2()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);
	cout<<L.size()<<endl;

	for(auto ch: L)
		cout<<ch<<" ";
	cout<<endl;
	
	L.pop_back();
	L.pop_back();
	for(auto ch: L)
		cout<<ch<<" ";
	cout<<endl;

	L.push_front(100);
	for(auto ch: L)
		cout<<ch<<" ";
	cout<<endl;

	L.pop_front();
	for(auto ch: L)
		cout<<ch<<" ";
	cout<<endl;
}

void Test3()
{
	
	int array[] = {1,2,3,4,5,6,7};
	list<int> L(array,array+sizeof(array)/sizeof(array[0]));
	for(auto ch: L)
		cout<<ch<<" ";
	cout<<endl;


	L.assign(10,5);
	for(auto ch: L)
		cout<<ch<<" ";
	cout<<endl;

}

void Test4()
{
	list<int> L(10,1);

	int array[] = {1,2,3,4,5,6,7};

	L.insert(L.begin(),0);
	for(auto ch: L)
		cout<<ch<<" ";
	cout<<endl;

	L.insert(L.begin(),array,array+sizeof(array)/sizeof(array[0]));
	for(auto ch: L)
		cout<<ch<<" ";
	cout<<endl;

	L.insert(find(L.begin(),L.end(),3),10,5);
	for(auto ch: L)
		cout<<ch<<" ";
	cout<<endl;
}

void Test5()
{
	int array[] = {1,2,3,4,5,6,7,8};
	list<int> L(array,array+sizeof(array)/sizeof(array[0]));
	
	L.erase(L.begin());
	
	//删除4及其所有的元素
	L.erase(find(L.begin(),L.end(),4),L.end());


	// clear
	L.erase(L.begin(),L.end());

}
bool IsMod3(int data)
{
	return 0== data % 3;
}
void Test6()
{
	int array[] = {1,1,2,3,4,5,6,7,8};
	list<int> L(array,array+sizeof(array)/sizeof(array[0]));
	//unique 重复性元素连在一起
	L.unique();

	for(auto ch: L)
		cout<<ch<<" ";
	cout<<endl;

	int array1[] = {1,23,4,6,2,6,7,3,9};
	list<int> LL(array1,array1+sizeof(array1)/sizeof(array1[0]));
	LL.sort();

	LL.merge(L);
	for(auto ch: LL)
		cout<<ch<<" ";
	cout<<endl;

	// remove删除指定的元素
	LL.remove(4);
	
	// remove_if 按照指定条件进行删除
	LL.remove_if(IsMod3);
	for(auto ch: LL)
		cout<<ch<<" ";
	cout<<endl;
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	Test6();

	system("pause");
	return 0;
}