class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carry = 1;
        for(int i = digits.size()-1; i>=0 && carry != 0; --i)
        {
            digits[i]+=carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        
        if(carry > 0)
        {
            digits.push_back(0);
            int prev = carry;
            for(int i = 0; i<digits.size(); ++i)
            {
                int tmp = digits[i];
                digits[i] = prev;
                prev = tmp;
            }
        }

        return digits;
    }
};