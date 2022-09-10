class Solution {
public:
    int climbStairs(int n) 
    {
        int arr[2] = {1, 2};
        
        for (int i = 3; i <= n; i++)
            arr[(i-1)%2] = arr[i%2] + arr[(i-1)%2];
        
        return arr[(n-1)%2];
    }
};