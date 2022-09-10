class Solution {
public:
    int romanToInt(string s) 
    {   
        map<char, int> table = {{'I', 1}, 
                                {'V', 5}, 
                                {'X', 10}, 
                                {'L', 50}, 
                                {'C', 100}, 
                                {'D', 500}, 
                                {'M', 1000}
                               };
        int i, n = s.length(), sum = 0;
        for (i = 0; i < n; i++)
        {
            // cout << i << "  " << table[s[i]] << "  " << table[s[i+1]] << endl;
            if ((i+1 < n) && table[s[i + 1]] > table[s[i]])
            {
                sum += table[s[i + 1]] - table[s[i]];
                // cout << sum << endl;
                i++;
            }
            else
            {
                sum += table[s[i]];        
                // cout << sum << endl;
            }
        }
        
        return sum;
    }
};