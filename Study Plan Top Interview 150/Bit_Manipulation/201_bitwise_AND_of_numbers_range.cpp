class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

     // for any digit to be 1 at the end, it has to be 1 in all of the numbers

     // 2^3 (8), 2^2 (4), 2^1 (2), 2^0 (1)
     // 1111 --> 15
     // ------------ 1 (2^0) numbers before first bit flips
     // 1110 --> 14
     // ------------ 2 (2^1) numbers before second bit flips
     // 1101 --> 13
     // 1100 --> 12
     // ------------ 4 (2^2) numbers before third bit flips
     // 1011 --> 11
     // 1010 --> 10
     // 1001 --> 9
     // 1000 --> 8
     // ------------ 8 (2^3) numbers before fourth bit flips
     // 0111 --> 7
     // 0110 --> 6
     // 0101 --> 5
     // 0100 --> 4
     // 0011 --> 3
     
     //bit N flips every N steps

     // We can use these patterns and just AND them
     // because if we know the difference < flip expectancy, 
     // there won't be a hidden flip in there

     int difference = right-left;

     if(difference == 0)
        return left;

     int diff_log = std::ceil(log2(difference));

     unsigned int mask = ~(0);
     mask <<= diff_log; 


     right &= mask;
     right &= left;
     
     return right;
    }
};