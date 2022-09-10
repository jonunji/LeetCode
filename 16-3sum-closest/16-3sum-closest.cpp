class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int closestSum = nums[0] + nums[1] + nums[2], n = nums.size();
        int i, low, high;
        bool trackersMoved;
        
        sort(nums.begin(), nums.end());
        
        for (i = 0; i < n - 2; i++)
        {
            low = i + 1;
            high = n-1;
            
            trackersMoved = true;
            
            while (trackersMoved)
            {
                trackersMoved = false;
                int currSum = nums[i] + nums[low] + nums[high];
                
                // cout << currSum << "    " << i << " " << low << " " << high << endl;
                if (abs(target - currSum) < abs(target - closestSum))
                {
                    closestSum = currSum;    
                    if (closestSum == target) return closestSum;
                }
                
                if (currSum < target)
                {
                    if (low + 1 != high)
                    {
                        trackersMoved = true;
                        low++;
                    }
                }
                else
                    if (high - 1 != low)
                    {
                        trackersMoved = true;
                        high--;
                    }
                
            }
        }
    
        return closestSum;
    }
};