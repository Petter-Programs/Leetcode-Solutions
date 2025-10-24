#define INT_SIZE 32
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int the_num = 0;
        int another_num = 0;

        for(int num : nums)
        {
            for(int i = 0; i<INT_SIZE; ++i)
            {
                int bit_in_num = (num & 1);
                num >>= 1;

                if(bit_in_num)
                {
                    if(!(the_num & (1<<i)))
                    {
                        the_num |= (1<<i);
                    }
                    else if(!(another_num & (1<<i)))
                    {
                        another_num |= (1<<i);
                    }
                    else
                    {
                        another_num ^= (1<<i);
                        the_num ^= (1<<i);
                    }
                }


            }

        }

        return the_num;
    }
};