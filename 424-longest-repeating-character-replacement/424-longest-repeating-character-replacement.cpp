class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int freq[26] = {0};
        int mostFreqLetter = 0;
        int longest = 0;
        
        for (int right = 0, left = 0; right < s.length(); right++)
        {
            int curr = s[right] - 'A';
            
            freq[curr]++;
            mostFreqLetter = max(freq[curr], mostFreqLetter);
            
            int lettersToChange = (right - left + 1) - mostFreqLetter;
            if (lettersToChange > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }
            
            longest = max(longest, right - left + 1);
        }
        
        return longest;
    }
};