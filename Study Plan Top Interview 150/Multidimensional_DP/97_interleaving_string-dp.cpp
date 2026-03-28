class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.size() + s2.size() != s3.size())
            return false;

        if(s1 == s3 || s2 == s3)
            return true;

        std::vector<bool> dp(s2.size()+1, false);

        for(int i = s1.size(); i>=0; --i)
        {
            for(int j = s2.size(); j>=0; --j)
            {
                int k = i+j;

                if(k==s3.size())
                {
                    // first square
                    dp[j] = true;
                    continue;
                }

                bool can_go_right = dp[j+1];
                bool can_go_down = dp[j];

                if(!can_go_right && !can_go_down)
                {
                    dp[j] = false;
                    continue;
                }

                char target = s3[k];
                
                char down_char = s1[i];
                char right_char = s2[j];

                if((can_go_right && target == right_char) || (can_go_down && target == down_char))
                {
                    dp[j] = true;
                }
                else
                {
                    dp[j] = false;
                }
            }
        }

        return dp[0];
    }
};