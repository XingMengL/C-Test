class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 入栈的个数与出栈的个数不同，则一定不匹配
        if(pushV.size() != popV.size())
            return false;
        
        int in = 0;
        int out = 0;
        stack<int> s;
        
        while(out < popV.size())
        {
        	// s栈为空 或 s栈顶元素与出栈栈顶元素不同时  入栈 
           while(s.empty() || s.top() != popV[out])
           {
               if(in < pushV.size())
               s.push(pushV[in++]);
               else 
                   return false;
           }
           // 走下来是 s.top() == popV[out];
            s.pop();
            out++;
        }
        return true;
    }
  
};
