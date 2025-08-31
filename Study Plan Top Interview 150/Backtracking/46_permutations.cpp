#define REMOVED -100

class Solution {
private:
    void dfs(vector<vector<int>>& sol, vector<int>& nums_remaining, vector<int>& permutation)
    {
        if(permutation.size() == nums_remaining.size())
        {
            sol.push_back(permutation);
            return;
        }

        for(int i = 0; i<nums_remaining.size(); ++i)
        {
            int number = nums_remaining[i];

            if(nums_remaining[i] == REMOVED)
                continue;

            nums_remaining[i] = REMOVED;

            permutation.push_back(number);

            dfs(sol, nums_remaining, permutation);

            permutation.pop_back();
            nums_remaining[i] = number;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> sol;

        vector<int> permutation;

        dfs(sol, nums, permutation);

        return sol;
    }
};