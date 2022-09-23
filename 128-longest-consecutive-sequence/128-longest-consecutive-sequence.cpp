class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        
        for (int num : nums)
        {
            int prev = num - 1;
            int next = num + 1;
            
            while (s.find(prev) != s.end()) s.erase(prev--);
            while (s.find(next) != s.end()) s.erase(next++);
            
            res = max(res, next - prev - 1);
        }
        
        return res;
    }
};