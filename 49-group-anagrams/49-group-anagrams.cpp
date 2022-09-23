class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        
        for (string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            
            m[key].push_back(s);
        }
        
        res.reserve(m.size());
        for (auto& anagrams : m)
            res.push_back(move(anagrams.second));
        
        return res;
    }
};