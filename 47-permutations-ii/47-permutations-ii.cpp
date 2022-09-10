class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& n) {
        sort(n.begin(), n.end());
        
        vector<int> curr;
        vector<vector<int>> res;
        
        permuteUnique(n, res, curr);
        
        return res;
    }
    
    void permuteUnique(vector<int>& v, vector<vector<int>> &res, vector<int> &curr) {
        
        if (v.size() == 0)
        {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < v.size(); i++)
        {
            if (i > 0 && v[i] == v[i-1])
                continue;
            
            // Change state
            int temp = v[i];
            v.erase(v.begin() + i);
            curr.push_back(temp);
            
            permuteUnique(v, res, curr);
                
            // Reset state
            v.insert(v.begin() + i, temp);
            curr.pop_back();
        }
    }
};