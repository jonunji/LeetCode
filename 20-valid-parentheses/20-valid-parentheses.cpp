class Solution {
public:
    bool isValid(string str) 
    {
        stack<char> s;
        
        for (char &c: str)
        {
            if (c == '(' || c == '{' || c == '[')
                s.push(c);
            
            switch (c)
            {
                case ')':
                    if (s.empty() || s.top() != '(')
                        return false;
                    s.pop();
                    break;
                
                case '}':
                    if (s.empty() || s.top() != '{')
                        return false;
                    s.pop();
                    break;
                    
                case ']':
                    if (s.empty() || s.top() != '[')
                        return false;
                    s.pop();
                    break;
            }
        }
        
        if (!s.empty())
            return false;
        
        return true;
    }
};