class Solution {
public:    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.length(), m = wordDict.size();
        vector<bool> dp(n+1, false);
        
        dp[n] = true;
        sort(wordDict.begin(), wordDict.end());
        
        for (int i = n-1; i >= 0; i--)
        {
            string str;
            
            for (int j = i; j < n; j++)
            {
                str += s[j];
                cout <<str<< endl;
                if (binary_search(wordDict.begin(), wordDict.end(), str))
                    if (dp[i] = dp[j+1]) break;
            }
        }
        
        return dp[0];
    }
};