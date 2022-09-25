class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int midNum = (nums[mid] < nums[0]) == (target < nums[0])
                        ? nums[mid]
                        : target < nums[0] ? INT_MIN : INT_MAX;
            
            if (target == midNum) 
                return mid;
            
            if (target < midNum) 
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return -1;
    }
};