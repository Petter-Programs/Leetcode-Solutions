class Solution {
public:
    int trailingZeroes(int n) 
    {
        // Background:
        //
        // The ONLY way to multiply a base-10 number > 0 to add another 0 to the end is to multiply it with a number which makes a new pair of prime factors of 2 and 5 either standalone or by combination
        //
        // Intuition:
        // Any time you multiply a number by 10, you add a zero. Does not matter what the number was from before or how you factorize it. In base 10, any multiplication by 10 of any number >0 necessarily adds a 0 to the end. 
        //
        // This generalizes to: for each distinct pair of 2,5 in the prime factors of the multiplication, we add a 0 to the end.
        //
        //  Visual explanation:
        //  10^3    10^2    10^1  10^0
        //  0       0       0     2     // 2 * 1
        //  0       0       0     4     // 2 * 2
        //  0       0       0     6     // 2 * 3
        //  0       0       0     8     // 2 * 4
        //  0       0       1     0     // 2 * 5 <-- (prime factors: 2*5)
        //  0       0       1     2     // 2 * 6 
        //  0       0       1     4     // 2 * 7
        //  0       0       1     6     // 2 * 8
        //  0       0       1     8     // 2 * 9
        //  0       0       2     0     // 2 * 10 <-- (prime factors: 2*2*5)

        // In a factorial sequence (n>=2), the number of 2s in prime factors is always greater than the number of 5s in prime factors. Therefore, each 5 we find we can always pair up with a 2 to make 10.

        // One caveat: we cannot just divide by the fives, because we might miss the numbers that divide by 5 to make more fives or numbers that are further divisible to make fives etc.

        int zeroes = 0;
        int divisor = 5;

        int number_fit = n/divisor;

        while(number_fit>0)
        {
            zeroes+=number_fit;
            divisor*=5;
            number_fit = n/divisor;
        }

        return zeroes;
    }


};

