class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> row(rowIndex + 1);
        row[0] = 1;
        
        int carry = 0;
        
        for (int i = 1; i <= rowIndex; i++)
        {
            carry = 1;
            
            for (int j = 1; j <= i; j++)
            {
                int temp = row[j];
                
                row[j] = row[j] + carry;
                
                carry = temp;
            }
        }
        return row;
    }
};