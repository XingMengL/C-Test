#include <iostream>
#include <windows.h>
using namespace std;

#if 0
template <typename T> //ģ������б�
T Add(T left,T right)  //�����б�
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
	cout<<Add(1.0,2.0)<<endl;//��ͨ������������ʽ����ת��

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
// ����ģ���ʵ���� ---��ʽʵ��������ʽʵ����
// ����ģ��--���������ĺ�����ֻ��һ�����������ɴ����ģ�ߣ�����Ա�����������ɴ������һ�ֹ���

/*
�ڱ������У�ͨ�����Դ��뷢�֣�Add(1,2)��Add(1.0, 2.0)�������˺���ģ��--->˵���Ǵ���
���ܵ��ú���ģ��---����ģ�岻��һ��������������ֻ�Ǳ��������ɴ���Ĺ���
*/

/*
����ģ���ԭ����
 �������ڱ�������ǣ������⵽�Ժ���ģ�����ʵ������
 ��ʽʵ���������������Ȼ�Բ������ͽ������ݣ������ݵĽ���滻ģ������б��е�T��������ɾ����Ӧ���͵ĺ����������û�����
   ע�⣺�������Ͳ�����ȫƥ��ʱ�����������ᷢ����ʽ����ת��������ֱ�ӱ���

��ʽʵ��������ȷָ��ģ������б���T��ʵ������
  �������ڱ������ʱ�������������ʽʵ����--->ֱ�����ɴ��룬����������Ͳ�ƥ�䣬�᳢�Խ�����ʳ����ת��
  ���ת���ɹ�����ͨ�����룬���ת��ʧ���򱨴�   
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
	//��ʽʵ����-----����ADD����
	cout<<ADD(1,2)<<endl;  // int int  --- T --> int -->����һ���������͵�ADD����
	cout<<ADD(1.0,2.0)<<endl; //double double --T --double--����һ�ݸ������͵�ADD����
	ADD(1,1.2);// int  double    ����� int ��������ȱʧ
	
	
	//��ʽʵ����  --- ��ȷָ��ģ������б���T��ʵ������
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

	ADD(1,2.0);  // ���������� ԭ�򣺶Ժ���ģ��ʵ����������������ʱ�� ���������Ͳ�����ȫƥ�䣬
	             // ����������Բ������ͽ�����ʽ����ת��  ֱ�ӱ���
	system("pause");
	return 0;
}
#endif

#if 0
// ע�⣺ ��ģ���У�һ������´��ݲ����������ã��������ͨ���βθı��ⲿʵ�Σ�����const��������
//       ��Ϊ��T�������Զ�������
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
	ADD(1, 2);         // ���ȵ�����ͨ���͵ĺ���
	ADD<int>(1, 2);    // �����������ʽʵ�������������ͻ����ģ��������һ��int���͵�Add����
	/*
	ע�⣺ģ�����ɵ�int���͵�Add�����������ͨ������ͻ
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
		//Ĭ������Ϊ10
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
	size_t _size;//��Ч����
	size_t _capacity;//����
};
template<class T>
void SeqList<T>::PushBack(const T& data)
{
	//�������
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
	SeqList<int>--->��SeqList����ģ��ʵ����Ϊint���������ڱ���׶ξͻ�����һ��ר�����洢int��˳����Ĵ���
	*/
	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);

	cout << s1[0] << endl;

	// SeqList<double>--->��SeqList����ģ��ʵ����Ϊdouble���������ڱ���׶ξͻ�����һ��ר�����洢double��˳����Ĵ���
	SeqList<double> s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);

	// �ڶ����ٽ�SeqListʵ����Ϊint��������������������һ��int���͵�˳����Ĵ����ˣ���Ϊs1ʵ����ʱ���Ѿ�����һ�ݴ���int��˳����Ĵ�����
	SeqList<int> s3;
	return 0;
	system("pause");
	return 0;
}