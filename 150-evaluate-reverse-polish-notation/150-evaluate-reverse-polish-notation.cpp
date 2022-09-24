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
            
            long num2 = nums.top(); nums.pop();
            long num1 = nums.top(); nums.pop();
            
            switch (token[0])
            {
                case '+': num1 += num2; break;
                case '-': num1 -= num2; break;
                case '*': num1 *= num2; break;
                case '/': num1 /= num2; break;
            }

            nums.push(num1);
        }
        
        return nums.top(); 
    }
};