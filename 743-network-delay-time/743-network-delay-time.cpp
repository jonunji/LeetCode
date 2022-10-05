class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {     
        int res;
        vector<bool> visited(n+1, false);
        priority_queue<pair<int, int>> pq;
        
        pq.push({0, k});
        
        while (!pq.empty())
        {
            int currDist = -pq.top().first;
            int currVal = pq.top().second;
            pq.pop();
            
            if (visited[currVal]) continue;
            visited[currVal] = true;
            
            res = currDist;
            if (--n == 0) return res;
            
            for (auto const &time : times)
                if (!visited[time[1]] && time[0] == currVal)
                    pq.push({-(currDist + time[2]), time[1]});
        }
        
        
        return n == 0 ? res : -1;
    }
};