class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) 
    {
        int a = m - 1,
            b = n - 1,
            k = m + n - 1;
        
        while (a >= 0 && b >= 0)
        {
            if (A[a] > B[b])    A[k--] = A[a--];
            else                A[k--] = B[b--];
        }
        
        while (b >= 0)          A[k--] = B[b--];
    }
};