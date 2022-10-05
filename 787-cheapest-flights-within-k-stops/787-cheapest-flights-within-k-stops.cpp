class Solution {
public:
    
    typedef array<int, 3> dest;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto &f : flights)
            adj[f[0]].push_back({f[2], f[1]});
        
        priority_queue<dest, vector<dest>, greater<dest>> pq;
        pq.push({0, src, k+1});
        
        // store our distances to avoid pushing worse options
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        
        while (!pq.empty())
        {
            auto [price, val, stops] = pq.top();
            pq.pop();
            
            // cout << price << "  " << val << "  " << stops << endl;
            
            if (val == dst) return price;
            if (!stops) continue;
            
            for (const auto &node : adj[val])
                if (dist[node.second][stops-1] > node.first + price)
                {
                    dist[node.second][stops-1] = node.first + price;
                    pq.push({node.first + price, node.second, stops - 1});
                }
        }
        
        return -1; 
    }
};