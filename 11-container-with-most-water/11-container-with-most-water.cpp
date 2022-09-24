class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        // distace between points * minHeight of our two indicies
        int left = 0;
        int right = heights.size() - 1;
        int maxWater = -1;
        
        while (left < right)
        {
            int currWater = (right - left) * min(heights[left], heights[right]);
            
            maxWater = max(maxWater, currWater);
            if (heights[left] < heights[right]) left++;
            else right--;
        }
        
        return maxWater;
    }
};