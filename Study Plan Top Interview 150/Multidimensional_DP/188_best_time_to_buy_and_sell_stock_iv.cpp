class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        if(k>prices.size()/2)
            k = prices.size()/2 + 1;

        auto best_profit_buy_at_k = std::make_unique<int[]>(k);
        auto best_profit_sell_at_k = std::make_unique<int[]>(k);

        std::fill_n(best_profit_buy_at_k.get(), k, INT_MIN);

        for(auto& p : prices)
        {
            for(int i = 0; i<k; ++i)
            {
                int best_profit_after_prev = i>0 ? best_profit_sell_at_k[i-1] : 0;

                best_profit_buy_at_k[i] = std::max(best_profit_buy_at_k[i], best_profit_after_prev - p);

                best_profit_sell_at_k[i] = std::max(best_profit_sell_at_k[i], best_profit_buy_at_k[i] + p);
            }
        }

        return best_profit_sell_at_k[k-1];
        
    }
};