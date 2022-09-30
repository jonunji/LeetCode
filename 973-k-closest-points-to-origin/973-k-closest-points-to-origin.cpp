class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<vector<int>> maxHeap;
        vector<vector<int>> res(k);

        for (vector<int> point : points)
        {
            int x = point[0];
            int y = point[1];

            maxHeap.push({x*x + y*y, x, y});
            if (maxHeap.size() > k) maxHeap.pop();
        }

        for (int i = 0; i < k; i++)
        {
            res[i] = { maxHeap.top()[1], maxHeap.top()[2] };
            maxHeap.pop();
        }

        return res;
    }
};