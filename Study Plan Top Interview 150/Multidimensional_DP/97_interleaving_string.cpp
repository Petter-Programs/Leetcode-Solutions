class Solution {
private:
    std::string make_identifier(std::string& s1, std::string& s2)
    {
        return s1 + std::to_string(s1.size()) + s2;
    }
private:
    bool dfs(std::string& s1, std::string& s2, std::string&s3, std::unordered_map<std::string, bool> &cache) {

        if(s3.empty())
        {
            return true;
        }
        
        char s1_next = !s1.empty() ? s1.back() : ' ';
        char s2_next = !s2.empty() ? s2.back() : ' ';
        char s3_next = s3.back();

        if(s1_next == s3_next)
        {
            s1.pop_back();
            s3.pop_back();

            std::string const identifier = make_identifier(s1, s2);

            if(!cache.contains(identifier))
            {
                bool success = dfs(s1, s2, s3, cache);

                if(success)
                    return true;
                
                // failed path
                cache[identifier] = false;

            }

            s1.push_back(s1_next);
            s3.push_back(s3_next);
        }

        if(s2_next == s3_next)
        {
            s2.pop_back();
            s3.pop_back();

            std::string const identifier = make_identifier(s1, s2);

            if(!cache.contains(identifier))
            {
                bool success = dfs(s1, s2, s3, cache);

                if(success)
                    return true;
                
                // failed path
                cache[identifier] = false;

                s2.push_back(s2_next);
                s3.push_back(s3_next);
            }
        }

        return false;

    }
public:
    bool isInterleave(string s1, string s2, string s3) {

        if(s3.size() != s1.size() + s2.size())
            return false;
        
        if(s3.size() == 0)
            return true;

        std::reverse(s1.begin(), s1.end());
        std::reverse(s2.begin(), s2.end());
        std::reverse(s3.begin(), s3.end());

        std::unordered_map<std::string, bool> cache;

        bool possible = dfs(s1, s2, s3, cache);

        return possible;
    }
};