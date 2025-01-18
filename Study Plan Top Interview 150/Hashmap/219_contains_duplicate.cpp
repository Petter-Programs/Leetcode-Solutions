class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        std::map<int, int> the_map;
        int lhs = 0;

        for(int rhs = 0; rhs<nums.size(); ++rhs)
        {
            if(rhs-lhs > k)
            {
                if(the_map.find(nums[lhs])->second == lhs)
                {
                    the_map.erase(nums[lhs]);
                }
                ++lhs;
            }

            if(the_map.find(nums[rhs])!=the_map.end())
                return true;

            the_map[nums[rhs]] = rhs;

            // cout << "added " << nums[rhs] << " idx " << the_map[nums[rhs]] << endl;
        }

        return false;

    }
};
