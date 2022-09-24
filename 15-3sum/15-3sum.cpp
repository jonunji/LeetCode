class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 3 || nums[0] > 0) return {};
        
        vector<vector<int>> res;
        
        for (int k = 0; k < nums.size(); k++) 
        {
            if (nums[k] > 0) break;
            
            int i = k + 1;
            int j = nums.size() - 1;
            int target = -nums[k];
            
            while (i < j)
            {
                int sum = nums[i] + nums[j];
                
                if (sum < target) i++;
                else if (sum > target) j--;
                else
                {
                    vector<int> curr{nums[k], nums[i], nums[j]};
                    res.push_back(curr);
                    
                    while (i < nums.size() && nums[i] == curr[1]) i++;
                    while (j < nums.size() && nums[j] == curr[2]) j--;
                }
            }
            
            while (k < nums.size() - 1 && nums[k] == nums[k+1]) k++;
        }
        
        return res;
    }
};