class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int curr = 0, left = 0, right = height.size() - 1, temp;
        
        while (left < right)
            // check for right^2 > curr
            // move right side inwards
            if (height[left] >= height[right])
            {
                temp = height[right] * (right - left);
                curr = temp > curr ? temp : curr;
                right--;
            }
            // check for left^2 > curr
            // move left side inwards
            else if (height[left] < height[right])
            {
                temp = height[left] * (right - left);
                curr = temp > curr ? temp : curr;
                left++;
            }
        
        return curr;
    }
};