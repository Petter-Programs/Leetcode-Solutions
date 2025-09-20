class Solution {
private:
    void dfs(std::vector<std::string>& sol, std::string& curr, int n, int par_open, int par_close)
    {
        if(par_open+par_close == 2*n)
        {
            sol.push_back(curr);
            return;
        }

        if(par_open < n)
        {
            curr+="(";
            par_open++;
            dfs(sol, curr, n, par_open, par_close);
            curr.pop_back();
            par_open--;
        }

        if(par_open > par_close)
        {
            curr+=")";
            par_close++;
            dfs(sol, curr, n, par_open, par_close);
            curr.pop_back();
            par_close--;
        }

    }
public:
    vector<string> generateParenthesis(int n) 
    {
        std::vector<std::string> sol;
        std::string curr;

        int par_open = 0;
        int par_close = 0;

        dfs(sol, curr, n, par_open, par_close);

        return sol;

        // found a solution only when all parentheses are laid out
        // at each step theres two options, ( and )
        // BUT we can only take a ) step if there is a matching ( before
        // and we can only take a ( step if we still have )'s to give
    }
};