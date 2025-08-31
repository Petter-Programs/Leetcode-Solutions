class Solution {
private:
    void dfs(std::vector<std::vector<int>>& sol, std::vector<int>& candidates, std::vector<int>& curr_combo, int current, int target, int curr_idx)
    {
        if(current >= target)
        {
            if(current == target)
            {
                sol.push_back(curr_combo);
            }

            return;
        }

        for(int i = curr_idx; i<candidates.size(); ++i)
        {
            curr_combo.push_back(candidates[i]);

            current+=candidates[i];

            dfs(sol, candidates, curr_combo, current, target, i);

            current-=candidates[i];

            curr_combo.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {

        std::vector<std::vector<int>> sol;

        std::vector<int> curr_combo;
        
        int current = 0;

        int curr_idx = 0;

        dfs(sol, candidates, curr_combo, current, target, curr_idx);

        return sol;
        
    }
};