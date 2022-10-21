class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gSize) 
    {
        if (hand.size() % gSize != 0) return false;
        
        map<int, int> freq;
        for (int const& card : hand) freq[card]++;
        auto it = freq.begin();
        
        while (it != freq.end())
        {
            if (it->second == 0)
            {
                it++; 
                continue;
            }
            
            int c = it->first;    
            for (int i = 0; i < gSize; i++)
            {
                if (freq.find(c+i) == freq.end()) 
                    return false;
                
                if (freq[c+i]-- <= 0) 
                    return false;
            }
        }
        
        
        return true;
    }
};


// 1,2,3,6,2,3,4,8,7
// 1 2 2 3 3 4 6 9 8
// . 
    
// same or greater than 1, next empty,
// diff by 1, same