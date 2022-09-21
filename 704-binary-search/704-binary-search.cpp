class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int low = 0, high = nums.size() - 1, mid;
        
        while (high - low > 1)
        {
            mid = (low + high) / 2;
            
            if (target < nums[mid])
                high = mid;
            
            else
                low = mid;
        }
        
        if (nums[low] == target)
            return low;
        
        if (nums[high] == target)
            return high;
        
        return -1;
    }
};