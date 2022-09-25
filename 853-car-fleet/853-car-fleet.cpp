class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) 
    {
        vector<pair<int, double>> cars;
        stack<double> s;
        
        // fill our cars array to store everything together
        for (int i = 0; i < pos.size(); i++)
        {
            double time = (target - pos[i]) / (double)speed[i];
            cars.push_back(pair<int, double>(pos[i], time));
        }
        
        sort(cars.begin(), cars.end());
        
        for (int i = 0; i < cars.size(); i++)
        {
            while (!s.empty() && s.top() <= cars[i].second)
                s.pop();
            
            s.push(cars[i].second);
        }
        
        return s.size();
    }
};


// Target: 12
// Position:    [0,3,5,8,10]
// Speed:       [1,3,1,4,2]    
// Time:       [12,3,7,1,1] 
// 
// time = (target - pos) / speed


//  10
// [6,  8]
// [3,  2]
// [4/3,1]