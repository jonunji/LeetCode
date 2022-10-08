class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), closest = 1e9;
        
        for (int k = 0; k < n; k++)
        {
            int i = k+1, j = n-1;
            
            while (i < j)
            {
                int sum = nums[k] + nums[i] + nums[j];

                if (abs(target - sum) < abs(closest - target)) 
                    closest = sum;
                
                if (sum < target) i++;
                else if (sum > target) j--;
                else return sum;
            }
        }
        
        return closest;
    }
};