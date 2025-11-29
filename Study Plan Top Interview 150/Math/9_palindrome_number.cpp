class Solution {
private:
    // nth digit from left
    int nth_digit(int x, int n)
    {
        // so, first divide out the non-relevant digits before target
        // then just mod 10 for the digit to ignore all digits after target
        x /= pow(10, n);
        return x%10;
    }

    int count_digits(int x)
    {
        if(x == 0)
            return 1;

        return log10(x) + 1;
    }
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
            return false;

        int digits_in_x = count_digits(x);

        int left_digit = digits_in_x-1;
        int right_digit = 0;

        while(right_digit<left_digit)
        {
            if(nth_digit(x, left_digit) != nth_digit(x, right_digit))
                return false;

            left_digit--;
            right_digit++;   
        }

        return true;

    }
};