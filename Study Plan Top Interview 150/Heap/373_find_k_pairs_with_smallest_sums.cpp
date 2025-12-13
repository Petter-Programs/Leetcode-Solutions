class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {

    auto cmp = [&](const std::vector<int>& a, const std::vector<int>& b)
    {
        int val_a = nums1[a[0]] + nums2[a[1]];
        int val_b = nums1[b[0]] + nums2[b[1]];

        return val_a > val_b;
    };

    std::vector<std::vector<int>> smallest;

    // Indexes
    std::vector<std::vector<int>> options;

    options.push_back({0, 0});

    while(smallest.size() < k)
    {
        std::vector<int> curr = options.front();

        int x = curr[0];
        int y = curr[1];

        smallest.push_back({nums1[x], nums2[y]});
        
        std::pop_heap(options.begin(), options.end(), cmp);
        options.pop_back();

        if(y == 0 && x < nums1.size()-1)
        {
            options.push_back({x+1, y});
            std::push_heap(options.begin(), options.end(), cmp);
        }

        if(y < nums2.size()-1)
        {
            options.push_back({x, y+1});
            std::push_heap(options.begin(), options.end(), cmp);
        }
    }

    return smallest;


    }
};