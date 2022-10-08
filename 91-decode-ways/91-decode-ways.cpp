class Solution {
public:
    
    vector<int> memo;
    
    int numDecodings(string s) 
    {
        int n = s.length();
        
        memo = vector<int>(n + 1, -1);
        memo[n] = 1;
        return count(s, 0);
    }
    
    int count(string s, int i)
    {        
        if (memo[i] > -1) return memo[i];
        if (s[i] == '0') return memo[i] = 0;
        
        int res = count(s, i+1);
        
        if(i<s.size()-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) res += count(s, i+2);
    
        return memo[i] = res;
    }
};