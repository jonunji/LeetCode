class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        vector<int> counts = {0, 0, 0};
        int i, j, currIndex;
        
        for (i = 0; i < nums.size(); i++)
        {
            counts[nums[i]]++;
            nums[i] = 0;
        }
        
        currIndex = counts[0];
        
        for (i = 1; i < 3; i++)
        {
            for (j = 0; j < counts[i]; j++)
            {
                nums[j + currIndex] = i; 
            }
            
            currIndex += j;
        }
    }
};