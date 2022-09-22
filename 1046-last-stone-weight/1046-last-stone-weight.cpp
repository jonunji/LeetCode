class Solution {
public:
    int lastStoneWeight(vector<int>& A) 
    {
        priority_queue<int> pq(begin(A), end(A));
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