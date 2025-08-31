class Solution {
private:
void dfs(std::vector<std::vector<int>>& solution, std::vector<int>& curr_combo, int const target_length, int const maximum, int current_digit)
{
    if(curr_combo.size() == target_length)
    {
        solution.push_back(curr_combo);   
        return;
    }

    for(int i = current_digit+1; i<=maximum; ++i)
    {   
        curr_combo.push_back(i);

        dfs(solution, curr_combo, target_length, maximum, i);
        
        curr_combo.pop_back();
    }
}
public:
    vector<vector<int>> combine(int n, int k) 
    {   
        std::vector<std::vector<int>> solution;

        std::vector<int> curr_combo;

        dfs(solution, curr_combo, k, n, 0);

        return solution;
    }
};