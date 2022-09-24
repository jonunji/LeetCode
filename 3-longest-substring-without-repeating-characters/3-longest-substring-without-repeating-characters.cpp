class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> seen;
        int longest = 0;
        int left = 0, right = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (seen.find(s[i]) != seen.end())
                left = max(left, seen[s[i]] + 1);
            
            longest = max(longest, right - left + 1);
            seen[s[i]] = i;
            right++;
        }
        
        return longest;
    }
};