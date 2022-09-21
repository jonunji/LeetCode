class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> stk;
        
        for (int i = 0; i < s.length(); i++)
        {
            int dist = s[i] - (stk.empty() ? 0 : stk.top());
            stk.push(s[i]);

            if (dist > 0 && dist < 3)
            {
                stk.pop();
                stk.pop();

                continue;
            }
        }

        return stk.empty();
    }
};