class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int total = 0, curGas = 0, start = 0;
        
        for (int i = 0; i < gas.size(); i++)
        {
            int g = gas[i] - cost[i];
            total += g;
            curGas += g;
            
            if (curGas < 0)
            {
                curGas = 0;
                start = i+1;
            }
        }
        
        return total < 0 ? -1 : start;
    }
};
    