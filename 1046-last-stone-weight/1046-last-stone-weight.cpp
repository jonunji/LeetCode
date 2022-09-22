class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> pq;
        
        for (int stone : stones)
            pq.push(stone);
        
        while (pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            
            x = abs(x - pq.top());
            pq.pop();
            
            pq.push(x);
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};