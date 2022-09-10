class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i, currIndex = 0, n = nums.size();
        
        for (i = 1; i < n; i++)
            if (nums[currIndex] != nums[i])
                nums[++currIndex] = nums[i];
        
        return n == 0 ? 0 : currIndex + 1;
    }
};