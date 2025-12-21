class Solution {
public:
    int mySqrt(int x) 
    {
        int left = 0;
        int right = 46340; // int(sqrt(INT_MAX))

        while(right >=left)
        {
            int mid = left + (right-left)/2;

            int res = mid*mid;
            
            if(res == x)
                return mid;
            
            if(res > x)
                right = mid-1;
            else
                left = mid+1;
        }

        return left-1;
    }
};