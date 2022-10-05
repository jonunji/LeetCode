class Solution {
public:
    
    // Prim's
    int minCostConnectPoints(vector<vector<int>>& p) 
    {
        int n = p.size(), res = 0, connected = 0, i = 0;
        
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>> pq; // minheap
        
        while (++connected < n)
        {
            visited[i] = true;
            for (int j = 0; j < n; j++)
                if (!visited[j]) // if we havent connected node j
                    pq.push({-manhattan(p, i, j), j}); // manhattan distance
            
            // get rid of things we visited before
            while (visited[pq.top().second]) pq.pop(); 
        
            res -= pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        
        return res;
    }
    
    
    int manhattan(vector<vector<int>>& p, int i, int j)
    {
        return abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
    }
};