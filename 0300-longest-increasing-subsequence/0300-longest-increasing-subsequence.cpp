class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n);
        
        for (int i = n-1; i >= 0; i--)
        {
            dp[i] = 1;
            
            for (int j = i+1; j < n; j++)
                if (nums[j] > nums[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            
            // cout << i << ": "<< dp[i] << endl;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

// [0,1,0,3,2,3]
//  4 3 3 1 2 1