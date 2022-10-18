class Solution {
public:
//     DP solution
//     int jump(vector<int>& nums) 
//     {
//         int n = nums.size();
//         if (n == 1) return 0;
        
//         int dp[n];
//         for (int i = 0; i < n; i++) dp[i] = 1e9;
//         dp[0] = 0;
        
//         for (int i = 0; i < n-1; i++)
//         {
//             int end = min(n-1, nums[i] + i);

//             for (int j = i+1; j <= end; j++)
//                 dp[j] = min(dp[j], dp[i] + 1);
//         }
            
//         return dp[n-1];
//     }
    
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1) return 0;
        
        int l = 0, r = 0, res = 0;
        while (r < n-1)
        {
            int furthest = 0;
            for (int i = l; i <= r; i++)
                furthest = max(furthest, nums[i] + i);
            
            l = r+1;
            r = furthest;
            res++;
        }
        
        return res;
    }
};