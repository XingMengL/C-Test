#include <iostream>
using namespace std;

int main()
{
    long a = 1;
    long b = 0;
    long c = 0;
    
    long n = 0;
    cin >> n;
    
    long left = 0;
    long right = 0;
    while(1)
    {
        c = a + b;
        a = b;
        b = c;
       if(n == 0)
       {
           left = 1;
           right = 1;
           break;
       }
       if(n > c && (a+b)>n)
       {
           left = n - c;
           right = (a+b) - n;
           break;
       }
        
    }
   long min = left<right?left:right;
   cout<<min<<endl;
    return 0;
}
