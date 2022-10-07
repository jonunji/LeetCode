class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> fb(n);
        
        for (int i = 1; i <= n; i++)
        {
            string val = "";
            
            if (i % 3 == 0) val += "Fizz";
            if (i % 5 == 0) val += "Buzz";
            
            if (val == "") val += to_string(i);
            
            fb[i-1] = val;
        }
        
        return fb;
    }
};