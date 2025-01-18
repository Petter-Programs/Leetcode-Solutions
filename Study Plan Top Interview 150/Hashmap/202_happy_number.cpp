class Solution {
public:

    int sumOfSquares(int the_number)
    {
        int sum = 0;
        while(the_number>0)
        {
            int last_digit = the_number%10;
            sum+=(last_digit*last_digit);
            the_number/=10;   
        }
        return sum;
    }

    bool isHappy(int n) 
    {
        std::set<int> the_set;

        int sum = sumOfSquares(n);

        while(sum != 1)
        {
            if(the_set.find(sum) == the_set.end())
                the_set.insert(sum);
            else
                return false;

            sum = sumOfSquares(sum);
        }

        return true;
    }
};