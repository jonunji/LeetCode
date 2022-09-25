class Solution {
public:
    int findKthNumber(int m, int n, int k) 
    {
        int left = 1, right = m * n;
        
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            
            if (countLess(m, n, mid, k)) 
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
    
    bool countLess(int m, int n, int num, int k)
    {
        int count = 0;
        
        for (int i = 1; i < m + 1; i++)
            count += min(num / i, n);
        
        return count >= k;
    }
};