#include <iostream>
using namespace std;

int main()
{
    int E, F, G, H;
    int A, B, C;
    
    while(cin>>E>>F>>G>>H)
    {
        A = ( E + G ) / 2;
        B = ( F + H ) / 2;
        C = ( H - F ) / 2;
        
        if( A - B == E && B - C == F && A + B == G && B + C == H)
        {
            
            cout<<A<<" "<<B<<" "<<C<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
   
    return 0;
}
