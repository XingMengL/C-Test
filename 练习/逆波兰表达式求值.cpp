class Solution {
public:
    int evalRPN(vector<string>& tokens) {
            stack<int> s;
            for(auto e: tokens)
            {
                if(!(e=="+" || e == "-" || e == "*" || e== "/"))
                {
                    s.push(atoi(e.c_str()));
                }
                else
                {
                    
                    int r = s.top();
                    s.pop();
                    int l = s.top();
                    s.pop();

                    switch(e[0])
                    {
                        case '+':
                        s.push(l+r);
                        break;
                         case '-':
                        s.push(l-r);
                        break;
                         case '*':
                        s.push(l*r);
                        break;
                         case '/':
                        s.push(l/r);
                        break;

                    }
                }
            }
            return s.top();
    }
};
