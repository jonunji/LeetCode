class Solution {
public:
    int reverse(int x) 
    {
        int revNum = 0;
        bool neg = false;
        
        if (x < 0)
            neg = true;
        
        x = abs(x);
        
        while (x > 0)
        {
            if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10)
                return 0;
            
            revNum = revNum * 10 + x % 10;
            x /= 10;
        }
        
        return revNum * (neg ? -1 : 1);
    }
};