class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> seen;
        int left = 0, right = 0;
        int longest = 0;
        
        while (right < s.length())
        {
            char ch = s[right];
            
            if (seen.find(ch) != seen.end())
                left = max(left, seen[ch] + 1);
            
            longest = max(longest, right - left + 1);
            seen[ch] = right;
            right++;
        }
        
        return longest;
    }
};