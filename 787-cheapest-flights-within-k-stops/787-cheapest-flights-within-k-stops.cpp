class Solution {
public:
    
//     typedef array<int, 3> dest;
        
//     Djikstra
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
//     {
//         // create our adjacency matrix
//         vector<vector<pair<int, int>>> adj(n);
//         for (const auto &f : flights)
//             adj[f[0]].push_back({f[2], f[1]});
        
//         // minheap
//         priority_queue<dest, vector<dest>, greater<dest>> pq;
//         pq.push({0, src, k+1});
        
//         // store our distances to avoid pushing worse options
//         vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        
//         while (!pq.empty())
//         {
//             auto [price, val, stops] = pq.top();
//             pq.pop();
                        
            
//             if (val == dst) return price;
//             if (!stops) continue;
            
//             // check edges of current stop
//             for (const auto &node : adj[val])
//                 if (dist[node.second][stops-1] > node.first + price)
//                 {
//                     dist[node.second][stops-1] = node.first + price;
//                     pq.push({node.first + price, node.second, stops - 1});
//                 }
//         }
        
//         return -1; 
//     }
    
//  Bellman Ford
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        // < OR = ?????
        for (int i = 0; i <= k; i++)
        {
            vector<int> temp(dist);
            
            for (const vector<int> &f : flights)
            {
                int curr = f[0], next = f[1], price = f[2];
                
                if (dist[curr] == INT_MAX) continue;
                temp[next] = min(dist[curr] + price, temp[next]);
            }
            
            dist = temp;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};