class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    // assume you have 11
    // to get to 11, you had to take 1, 2, or 5
    // so you were at 10, 9, or 6
    // [9, 8, 5], [8, 7, 4], [1, 4, 5]

    /* worst case scenario, need "amount" steps, therefore set amount+1 as default */
    std::vector<int> arr(amount+1, amount+1);

    arr[amount] = 0;

    for(int i = amount-1; i>=0; --i)
    {
        for(auto const& c : coins) {

            /* prevent overflow */
            if(c > amount)
                continue;

            if(i+c <= amount && (i+c == amount || arr[i+c] != 0))
            {
                arr[i] = std::min(arr[i], arr[i+c] + 1);
            }
        }
    }

    if(arr[0] == amount+1)
        return -1;

    return arr[0];

    }
};