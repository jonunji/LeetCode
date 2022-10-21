class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int total = 0, curGas = 0, start = 0;
        
        for (int i = 0; i < gas.size(); i++)
        {
            total += gas[i] - cost[i];
            curGas += gas[i] - cost[i];
            
            if (curGas < 0)
            {
                curGas = 0;
                start = i+1;
            }
        }
        
        return total < 0 ? -1 : start;
    }
};
    