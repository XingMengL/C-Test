#include <iostream>
using namespace std;

#include <string>
int main()
{
    string str;
    string s1;
    string s2;
    
    cin >> str;
    for(int i = 0; i <= str.length(); i++)
    {
        if(str[i]>='0' && str[i] <='9')
            s1 += str[i];
        else
        {
            if(s2.length() < s1.length())
                s2 = s1;
            
                s1 = "";
            
        }
    }
    
    cout<<s2<<endl;
    return 0;
} 
