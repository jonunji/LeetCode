class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int max = nums[0], sum = 0;
        int i, n = nums.size();
        
        for (i = 0; i < n; i++)
        {
            sum += nums[i];
            
            if (sum > max)
                max = sum;
                
            if (sum < 0)
                sum = 0;
        }
        
        return max;
    }
};