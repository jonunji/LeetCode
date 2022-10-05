class Solution {
public:
    
    typedef pair<int, int> time;
    
    // dijktras
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {     
        vector<vector<time>> adj(n+1);
        for (auto const &t : times)
            adj[t[0]].push_back({t[1], t[2]});
        
        int res;
        vector<bool> visited(n+1, false); // n+1 since values start at 1
        priority_queue<time, vector<time>, greater<time>> pq;
        
        pq.push({0, k}); // start with our k
        
        while (!pq.empty())
        {
            // using negatives cuz of maxheap instead of minheap
            int currDist = pq.top().first;
            int currVal = pq.top().second;
            pq.pop();
            
            // skip if we have seen this before
            if (visited[currVal]) continue;
            visited[currVal] = true;
            
            // currDist will always be the highest, lowest number in our final distances
            res = currDist;
            if (--n == 0) return res;
            
            for (auto const &t : adj[currVal])
                if (!visited[t.first])
                    pq.push({currDist + t.second, t.first});
        }
        
        
        return n == 0 ? res : -1;
    }
};