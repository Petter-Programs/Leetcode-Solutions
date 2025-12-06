struct LockedItem
{
    int cost;
    int profit;

    bool operator>(const LockedItem& other) const
    {
        return cost > other.cost;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        std::vector<int> avail_items;
        std::vector<LockedItem> locked_items;

        for(int i = 0; i<profits.size(); ++i)
        {
            if(capital[i] > w)
                locked_items.push_back({capital[i], profits[i]});

            else
            {
                avail_items.push_back(profits[i]);
            }
        }

        std::make_heap(locked_items.begin(), locked_items.end(), std::greater<LockedItem>());
        std::make_heap(avail_items.begin(), avail_items.end());

        int capit = w;

        while(k > 0 && avail_items.size() > 0)
        {
            capit += avail_items.front();

            std::pop_heap(avail_items.begin(), avail_items.end());
            avail_items.pop_back();
            --k;

            bool avail_items_unheaped = false;

            while(locked_items.size() > 0 && locked_items.front().cost <= capit)
            {
                avail_items.push_back(locked_items.front().profit);
                std::pop_heap(locked_items.begin(), locked_items.end(), std::greater<LockedItem>());
                locked_items.pop_back();
                avail_items_unheaped = true;
            }

            if(avail_items_unheaped)
                std::make_heap(avail_items.begin(), avail_items.end());
        }

        return capit;

    }
};