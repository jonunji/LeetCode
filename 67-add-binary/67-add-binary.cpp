class Solution {
public:
    string addBinary(string a, string b) 
    {
        string s = "";
        int carry = 0, i = a.length() - 1, j = b.length() - 1;
        
        while (i >= 0 || j >= 0)
        {
            int sum = (i < a.length() ? a[i--] - '0' : 0) 
                    + (j < b.length() ? b[j--] - '0' : 0)
                    + carry;
            
            carry = 0;
            
            if (sum >= 2)
            {
                sum = (sum == 2) ? 0 : 1;
                carry = 1; 
            }
    
            s = to_string(sum) + s;
        }
        
        if (carry == 1)
            s = to_string(carry) + s;
        
        return s;
    }
};