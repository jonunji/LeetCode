class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        vector<int> res;
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        
        for (auto const &p : pre)
        {
            degree[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        
        queue<int> q;
        for (int i = 0; i < degree.size(); i++)
            if (degree[i] == 0) q.push(i);
        
        while (!q.empty())
        {
            int curr = q.front(); q.pop(); n--;
            res.push_back(curr); 
            
            for (auto const &v : adj[curr])
                if (--degree[v] == 0) q.push(v);
        }
        
        if (n == 0) return res;
        return {};
    }
};