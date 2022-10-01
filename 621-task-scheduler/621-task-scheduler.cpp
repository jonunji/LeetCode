class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int totalTime = 0;
        int freq[26] = {0};
        priority_queue<int> pq;
        queue<pair<int, int>> waiting;
        
        // fill our frequency array
        for (char task : tasks) freq[task - 'A']++;
        // push frequencies onto maxheap
        for (int task : freq) if (task > 0) pq.push(task);
        
        while (!pq.empty() || !waiting.empty())
        {
            if (!pq.empty())
            {
                int currTask = pq.top() - 1;
                pq.pop();

                // add our task to the queue if it isnt finished
                if (currTask > 0) waiting.push({currTask, totalTime + n});
            }
            
            if (!waiting.empty())
            {
                // if our queue is empty, and we are done waiting, push it onto the heap
                while (!waiting.empty() && waiting.front().second == totalTime)
                {
                    pq.push(waiting.front().first);
                    waiting.pop();
                }
            }
            
            totalTime++;
        }
        
        return totalTime;
    }
};


// A__A__A
// key is noticing we always need the maximum number here.
// O(log 26) => O(1) for our maxheap
// traversing n elements O(n) so O(log 26 + n) => O(n)
// space is holding O(26) elements, so O(1)