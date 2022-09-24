class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int freq[26] = {0};
        
        // fill our freq array
        for (char ch : s1) freq[ch - 'a']++;
        
        // search for permutations
        for (int right = 0, left = 0; right < s2.size(); right++)
        {
            int ch = s2[right] - 'a';
            // cout << left <<"   " << right << "  " << s2[right] << "  " << freq[ch] << endl;
            if (freq[ch] > 0)
            {
                freq[ch]--;
            }
            else if (left != right)
            {
                ++freq[s2[left++] - 'a'];
                right--;
            }
            else
            {
                left++;
            }
            
            if ((right - left + 1) == s1.length()) return true;
        }
        
        return false;
    }
};