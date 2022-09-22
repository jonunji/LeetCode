class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int i = digits.size() - 1;
        int carry = 1;
        
        while (carry != 0 && i >= 0)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            
            digits[i] %= 10;
            
            i--;
        }
        
        if (carry != 0) digits.insert(digits.begin(), carry);
        
        return digits;
    }
};