class Solution {
public:
    bool isPalindrome(int x) 
    {
        long long revNum = 0;
        int orig = x;
        
        if (x < 0)
            return false;
        
        while (x > 0)
        {
            revNum = revNum * 10 + x % 10;
            x /= 10;
        }
        
        return revNum == orig;
    }
};