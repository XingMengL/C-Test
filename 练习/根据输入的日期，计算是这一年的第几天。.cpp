#include<iostream>
using namespace std;
int main()
{
    static int monthdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int year,month,day;
   while (cin>>year>>month>>day){
  
    int num=0;
    for (int i=0; i<month; i++)
    {
        num+=monthdays[i];
    }
     num+=day;
     if ((month>2)&&(year%4 == 0 && year% 100 !=0) ||( year%400==0))
    {
        num+=1;
    }
    cout<<num<<endl;
    }
    return 0;
}
