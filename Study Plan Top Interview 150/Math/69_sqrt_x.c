int mySqrt(int x) 
{
    long long res = 0;

    // For square root X with bits B, we need B/2 bits.
    // So for sqrt(INT_MAX) we need 32/2 = 16

    for(int i = 15; i>=0; i--)
    {
        long long mask = 1<<i;
        res |= mask;
        if(res*res > x)
            res ^= mask;
    }

    return res;
}