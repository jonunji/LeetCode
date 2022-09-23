class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> cnt;
        vector<int> res;
        
        // fill frequency map
        for (auto& num : nums) cnt[num]++;

        // bucket sort
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& kv : cnt)
            buckets[kv.second].push_back(kv.first);
            
        // get top k from buckets
        for (int i = buckets.size() - 1; i >= 0; i--)
            for (int j = 0; j < buckets[i].size(); j++)
            { 
                res.push_back(buckets[i][j]);
                if (res.size() == k) return res;
            }
        
        return res;
    }
};