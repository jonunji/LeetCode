class Solution {
public:
    int lastStoneWeight(vector<int>& A) 
    {
        priority_queue<int> pq(begin(A), end(A));
        while (pq.size() > 1)
        {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            
            if (x != y) pq.push(y - x);
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};