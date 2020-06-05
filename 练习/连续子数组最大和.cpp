#include <iostream>
using namespace std;

#include <vector>

int main()
{
    vector<int> v;
    int n = 0;
   
    int count = 0;
    
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    // ¿¼ÂÇ¸ºÊý
    int max = -1;
    
    for(int i = 0; i < n ; i++)
    {
        count += v[i];
        
        if(count < 0)
        {
            count = 0;
        }
        else
        {
            max = max > count ? max : count;
        }
    }
    
    cout<<max<<endl;
    return 0;
}

