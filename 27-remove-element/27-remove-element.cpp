class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int count = 0;
        
        int i = (nums.size() - 1);
        int tail = i;
        
        for (; i >= 0 ; i--)
            if (nums[i] == val)
            {
                nums[i] = nums[tail--];
                count++;
            }

        return nums.size() - count;
    }
};