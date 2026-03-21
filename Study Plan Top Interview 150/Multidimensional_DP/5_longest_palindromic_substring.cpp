class Solution {
public:
    string longestPalindrome(string s) 
    {
        std::vector<std::vector<bool>> vec(s.size(), std::vector<bool>(s.size()));

        for(int i = 0; i<s.size(); ++i)
        {
            vec[i][i] = true;
        }

        int longest_start_idx = 0;
        int longest_end_idx = 0;

        int row = 0;
        int col = 1;
        int col_start = 1;

        // iterate one lr diagonal at a time starting from just right of center
        while(col < vec.size())
        {
            // each entry in vec (on right side) represents:
            // "is the string starting at i==row and ending at i==col a palindrome?"

            char start_letter = s[row];
            char end_letter = s[col];

            if(start_letter != end_letter)
                vec[row][col] = false;

            else
            {
                bool middle_palindrome = 0;
                int middle_start_idx = row+1;
                int middle_end_idx = col-1;

                if(middle_end_idx < middle_start_idx) 
                    middle_palindrome = true;
                
                else if(vec[middle_start_idx][middle_end_idx])
                    middle_palindrome = true;
                    
                vec[row][col] = middle_palindrome;

                if(middle_palindrome)
                {
                    if(col-row > longest_start_idx-longest_end_idx)
                    {
                        longest_start_idx = row;
                        longest_end_idx = col;
                    }
                }

            }

            row+=1;
            col+=1;

            if(col>=vec.size())
            {
                row = 0;
                col = ++col_start;
            }
        }
        
        return s.substr(longest_start_idx, (longest_end_idx-longest_start_idx)+1);
    }
};