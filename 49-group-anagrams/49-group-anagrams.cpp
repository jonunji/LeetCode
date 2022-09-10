class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // sorted string, strs[i]
        unordered_map<string, vector<string>> m;
        
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            
            m[s].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        
        for (auto it : m)
            res.push_back(it.second);
        
        return res;
    }
};