class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        return quickSelect(0, nums.size() - 1, nums, k);
    }
    
    int quickSelect(int low, int high, vector<int>& nums, int k)
    {
        int pivot = nums[high];
        int p = low;
        
        for (int i = low; i < high; i++)
            if (nums[i] <= pivot)
                swap(nums[i], nums[p++]);
        
        swap(nums[high], nums[p]);
        
        int count = high - p + 1;
        
        if (count == k) return nums[p];
        if (count > k)  return quickSelect(p+1, high, nums, k);
        else            return quickSelect(low, p-1, nums, k - count);
    }
};