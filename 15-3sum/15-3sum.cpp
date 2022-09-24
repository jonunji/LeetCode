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
            
            int i = k + 1, j = nums.size() - 1;
            
            while (i < j)
            {
                if ((nums[i] + nums[j] + nums[k]) < 0) i++;
                else if ((nums[i] + nums[j] + nums[k]) > 0) j--;
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