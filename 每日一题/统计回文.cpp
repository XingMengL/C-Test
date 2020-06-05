#include <iostream>
#include <algorithm>
using namespace std;
#include <string>


int main()
{
    string s1,s2;
    string s3,s4;
    cin >> s1 >> s2;
    s4 = s1;
    int c = s1.length()+1;
    int count = 0;
    //循环插入
    while(c--)
    {   
        s1.insert(c,s2);
       //判断是否为回文
        s3 = s1;
     reverse(s1.begin(),s1.end());
        if(s3 == s1)
        {
            count++;
        }
        
        s1 = s4;
    }
    cout<<count<<endl;
        return 0;
}
