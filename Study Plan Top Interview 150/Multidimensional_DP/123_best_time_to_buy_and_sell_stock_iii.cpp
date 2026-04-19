class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit_after_buy1 = INT_MIN;
        int profit_after_buy2 = INT_MIN;

        int profit_after_sell1 = 0;
        int profit_after_sell2 = 0;

        for(auto& price : prices)
        {
            /* These two lines determine the maximum achievable profit
             * for every single point in the price array */
            profit_after_buy1 = std::max(profit_after_buy1, 0-price);
            profit_after_sell1 = std::max(profit_after_sell1, profit_after_buy1+price);

            /* These two lines determine the maximum achievable profit
             * of a transaction at each point given that the transaction
             * is funded by the optimal profit achievable so far */
            profit_after_buy2 = std::max(profit_after_buy2, profit_after_sell1-price);
            profit_after_sell2 = std::max(profit_after_sell2, profit_after_buy2+price);
        
            /* We could add an arbitrary number of extra transactions */
        }

        return profit_after_sell2;
    }

    /* Unfortunately O(N^2), but a valid solution: */
    int slow_maxProfit(vector<int>& prices) 
    {
        auto dp_1 = std::make_unique<int[]>(prices.size());
        auto dp_2 = std::make_unique<int[]>(prices.size());

        for(int i = 0; i < prices.size(); ++i)
        {
            for(int j = i; j < prices.size(); ++j)
            {
                // i = column = buy at
                // j = row = sell at

                int first_sale_best = i > 0 ? dp_1[i-1] : 0;

                int curr_val = prices[j] - prices[i] + first_sale_best;

                int dp2_left = dp_2[j];
                int dp2_up = j > 0 ? dp_2[j-1] : 0;

                dp_2[j] = std::max(std::max(dp2_up, dp2_left), curr_val);
            }

            for(int j = 0; j <= i; ++j)
            {
                int up_val = j < i ? dp_1[j] : 0;
                int left_val = j > 0 ? dp_1[j-1] : 0;
                int curr_val = prices[i]-prices[j];

                dp_1[j] = std::max(std::max(up_val, left_val), curr_val);
            }
            
        }

        return dp_2[prices.size()-1];
    }
};