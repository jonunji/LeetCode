class Solution {
public:
    
    struct VectorHash {
    size_t operator()(const std::vector<int>& v) const 
    {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
    };
    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> solutions;
        int i, n = nums.size(), low, high;
        
        sort(nums.begin(), nums.end());
        
        for (i = 0; i < n; i++)
        {
            low = i+1;
            high = n-1;

            while (low < high)
            {
                int currSum = nums[i] + nums[low] + nums[high];
                
                if (currSum == 0)
                {
                    vector<int> triplet = {nums[i], nums[low], nums[high]};
                    solutions.push_back(triplet);
                    
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (low < high && nums[low] == triplet[1]) low++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (low < high && nums[high] == triplet[2]) high--;
                }
                
                else if (currSum < 0)
                    low++;
                else 
                    high--;
            }
            
            while (i+1 < n && nums[i] == nums[i + 1]) i++;
        }

        return solutions;
    }
};