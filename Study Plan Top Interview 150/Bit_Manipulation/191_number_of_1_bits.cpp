#define INT_SIZE 32

class Solution {
public:
    int hammingWeight(int n) 
    {
        int set_bits = 0;
        for(int i = 0; i<INT_SIZE; ++i)
        {
            if(n & 1)
                set_bits++;
            
            n >>= 1;
        }

        return set_bits;

    }
};