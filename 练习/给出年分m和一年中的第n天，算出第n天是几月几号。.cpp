#include <iostream>
using namespace std;

class Date
{
public:
    void Set(int year, int day)
    {
     _year = year;
     _day = day;
    }
    bool IsRyear()
	{
		if( ((0 == _year%4)&&(0 != _year%100)) ||(0 == _year %400) )
			return true;
		else
			return false;
	} 
    void func()
    {
       int array1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//平年
       int array2[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};//闰年
        
        if(IsRyear())
        {
            //闰年
            int i = 1;
            while(_day > array2[i])
            {
				  
                  _day = _day - array2[i++];
				  if(i == 13)
				  {
				   i = 1;
				   _year++;
				  }
				  _month = i;
				  
            }
			
			
        }
        else
        {
            //平年
            int i = 1;
            while(_day > array1[i])
            {
              _day = _day - array1[i++];
				  if(i == 13)
				  {
				   i = 1;
				   _year++;
				  }
				  _month = i;
			
              }
		}
        //cout<<_year<<_month<<_day<<endl;
    }

    int _year;
    int _month;
    int _day;
};
int main()
{
	int year,day;
	cin>>year>>day;
	Date d1;
	d1.Set(year,day);
	d1.func();
	printf("%04d-%02d-%02d",d1._year, d1._month, d1._day);

	system("pause");
    return 0;
}
