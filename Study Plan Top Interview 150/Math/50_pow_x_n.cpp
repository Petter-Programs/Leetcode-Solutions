class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n == 0)
            return 1;
        
        if(x == 0)
            return 0;

        int half_n = n/2;

        bool negative_exp = false;

        // do this abs() here to avoid overflow
        if(n < 0)
        {
            negative_exp = true;
            half_n = abs(half_n);
        }

        double extra_x = n % 2 == 0 ? 1 : x;
        double res = myPow(x, half_n);

        if(!negative_exp)
            return extra_x * res * res;
        return 1.0 / (extra_x * res * res);
    }

};