class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> arr(2);
        arr[0] = 1;
        arr[1] = 2;
        
        for (int i = 2; i < n; i++)
            arr[i%2] = arr[(i-1)%2] + arr[(i-2)%2];
    
        return arr[(n-1)%2];
    }
};