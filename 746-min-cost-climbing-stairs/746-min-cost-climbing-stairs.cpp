class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int arr[2];
        arr[0] = cost[0];
        arr[1] = cost[1];
        
        for (int i = 2; i < cost.size(); i++)
            arr[i%2] = cost[i] + min(arr[(i-1) % 2], arr[(i-2) % 2]);
        
        return min(arr[(cost.size() - 1) % 2], arr[(cost.size() - 2) % 2]);
    }
};