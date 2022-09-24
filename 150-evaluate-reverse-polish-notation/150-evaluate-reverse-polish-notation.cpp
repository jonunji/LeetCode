class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> nums;
        
        for (int i = 0; i < tokens.size(); i++)
        {
            string token = tokens[i];
            
            if (isdigit(token[0]) || token.length() > 1)
            {
                nums.push(stoi(token));
                continue;
            }
            
            long num2 = nums.top();
            nums.pop();
            long num1 = nums.top();
            nums.pop();

            if (token[0] == '+') num1 += num2;
            if (token[0] == '-') num1 -= num2;
            if (token[0] == '*') num1 *= num2;
            if (token[0] == '/') num1 /= num2;

            nums.push(num1);
        }
        
        return nums.top(); 
    }
};