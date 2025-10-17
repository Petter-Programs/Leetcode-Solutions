#define INT_SIZE 32 
class Solution {
public:
    int reverseBits(int n) 
    {
        int answer = 0;

        for(int i = 0; i<INT_SIZE; i++)
        {
            answer <<= 1; // first time executed has no effect since we start from 0
            answer |= (n & 1); // add last bit to answer
            n >>= 1; // remove last bit from template
        }   

        return answer;
    }
};