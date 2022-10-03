class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<vector<int>> adjList(n);
        vector<int> degree(n, 0);
        
        // make our adj list and indegrees
        for (auto const &p : pre)
        {
            degree[p[0]]++;
            adjList[p[1]].push_back(p[0]);
        }
        
        queue<int> q;
        
        // find nodes with no incoming edges
        for (int i = 0; i < degree.size(); i++)
            if (degree[i] == 0) q.push(i);
        
        while (!q.empty())
        {
            int curr = q.front(); q.pop(); n--;
            
            // get rid of one edge going into node, if 0, push to queue
            for (auto const &v : adjList[curr])
                if (--degree[v] == 0) q.push(v);
        }
            
        return n == 0;
    }
};