class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combos;
        const vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if (digits.empty())
            return {};
        
        combos.push_back("");
            
        for (char dig: digits)
        {
            vector<string> temp;
            for (char newLetter: letters[dig - '0'])
                for (string s: combos)
                    temp.push_back(s + newLetter);
            
            combos.swap(temp);
        }
        
        return combos;
    }
};