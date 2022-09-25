class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left = 1, right = 1e9;
        
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            
            if (canConsume(piles, h, mid)) 
                right = mid;
            else 
                left = mid + 1;
        }
        
        return left;
    }
    
    bool canConsume(vector<int> piles, int h, int k)
    {
        int hours = 0;
        
        for (int pile : piles)
            hours += ceil(1.0 * pile / k);
        
        return hours <= h;
    }
};