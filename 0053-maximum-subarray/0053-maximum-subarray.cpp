class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxSum = INT_MIN, sum = 0;
        
        for (int const &n : nums)
        {
            sum = max(n, sum + n);
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};

 