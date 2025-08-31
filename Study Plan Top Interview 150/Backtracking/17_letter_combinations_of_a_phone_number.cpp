class Solution {
private:
    void dfs(std::string& curr, int digits_idx, std::string& digits, std::array<std::array<char, 4>, 8> const matrix, std::vector<std::string>& solution)
    {
        if(curr.length() == digits.length())
        {
            solution.push_back(curr);
            return;
        }

        char next_char_number = digits[digits_idx];
        int next_number = next_char_number - '0';
        int next_idx = next_number-2;

        for(int i = 0; i<4; ++i)
        {
            char c = matrix[next_idx][i];

            if(c != '-')
            {
                curr+=c;
                dfs(curr, digits_idx+1, digits, matrix, solution);
                curr.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) 
    {
        if(digits.length() == 0)
            return {};

        std::array<std::array<char, 4>, 8> matrix
        {{
            {{ 'a', 'b', 'c', '-' }},
            {{ 'd', 'e', 'f', '-' }},
            {{ 'g', 'h', 'i', '-' }},
            {{ 'j', 'k', 'l', '-' }},
            {{ 'm', 'n', 'o', '-' }},
            {{ 'p', 'q', 'r', 's' }},
            {{ 't', 'u', 'v', '-' }},
            {{ 'w', 'x', 'y', 'z' }}
        }};
    

    std::vector<std::string> solution;

    std::string curr = ""; 
    
    dfs(curr, 0, digits, matrix, solution);

    return solution;
    }
};