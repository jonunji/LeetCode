class KthLargest {
public:
    
    int K;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    KthLargest(int k, vector<int>& nums) 
    {
        K = k;
        
        for (int val : nums)
        {
            minHeap.push(val);
            
            // limit minHeap to k elements, so kth largest is the 
            // smallest in a minHeap of size k
            if (minHeap.size() > k) minHeap.pop();
        }
    }
    
    int add(int val) 
    { 
        minHeap.push(val);
        if (minHeap.size() > K) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */