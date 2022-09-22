class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        
        int arr[2]; 
        arr[0] = cost[0];
        arr[1] = cost[1];
        
        for (int i = 2; i < n; i++)
            arr[i%2] = cost[i] + min(arr[(i-1) % 2], arr[(i-2) % 2]);
        
        return min(arr[(n - 1) % 2], arr[(n - 2) % 2]); 
    }
};