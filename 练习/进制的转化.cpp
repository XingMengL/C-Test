
#include <iostream>
using namespace std;
int main(){
    string s="",table="0123456789ABCDEF";
    int m,n;
    cin>>m>>n;
    while(m){
        if(m  < 0)
        {
            m = -m;
            cout<<"-";
        }
        else
        {
            s = table[m%n]+s;
            m = m/n;
        }
    }
    cout<<s<<endl;
    return 0;
}
