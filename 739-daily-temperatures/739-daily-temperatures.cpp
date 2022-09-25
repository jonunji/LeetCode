class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) 
    {
        vector<int> res(temps.size(), 0);    
        stack<int> s; // stores index of temps
        
        for (int i = 0; i < temps.size(); i++)
        {
            while (!s.empty() && temps[i] > temps[s.top()])
            {
                res[s.top()] = i - s.top(); 
                s.pop();
            }
            
            s.push(i);
        }
        
        return res;
    }
};