int climbStairs(int n) 
{
    int one_before = 1; // there is exactly 1 possible way to get to step zero; the base case
    int two_before = 1; // there is exactly 1 possible way to get to step one; take one step from base

    // skip calculation of how to get to step zero and step one as they are precomputed
    // this means we have n-1 calculations remaining
    for(int i = 0; i<n-1; i++)
    {
        int ways_to_step = one_before+two_before;
        two_before = one_before;
        one_before = ways_to_step;
    }

    return one_before;
}