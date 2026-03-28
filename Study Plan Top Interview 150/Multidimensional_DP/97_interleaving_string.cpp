class Solution {
private:
    bool dfs(int i1, int i2, std::string const& s1, std::string const& s2, std::string const& s3, std::vector<std::vector<bool>> &unvisited) {

        char s1_next = i1 < s1.size() ? s1[i1] : ' ';
        char s2_next = i2 < s2.size() ? s2[i2] : ' ';

        if(s1_next == ' ' && s2_next == ' ')
            return true;

        char s3_next = s3[i1+i2];

        if(s1_next == s3_next && unvisited[i1+1][i2])
        {
            bool success = dfs(i1+1, i2, s1, s2, s3, unvisited);

            if(success)
                return true;
        }

        if(s2_next == s3_next && unvisited[i1][i2+1])
        {
            bool success = dfs(i1, i2+1, s1, s2, s3, unvisited);

            if(success)
                return true;
        }

        unvisited[i1][i2] = false;
        return false;

    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s3.size() != s1.size() + s2.size())
            return false;
        
        if(s3.size() == 0)
            return true;

        std::vector<std::vector<bool>> unvisited(s1.size()+1, std::vector<bool>(s2.size()+1, true));

        bool possible = dfs(0, 0, s1, s2, s3, unvisited);

        return possible;
    }
};