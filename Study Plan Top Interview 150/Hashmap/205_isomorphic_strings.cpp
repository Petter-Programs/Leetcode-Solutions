class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Mappings from s to t
        std::map<char, char> mappings_s_to_t;
        std::map<char, char> mappings_t_to_s;

        std::string::iterator it_s = s.begin();
        for(std::string::iterator it_t = t.begin(); it_t != t.end(); ++it_t)
        {

            // No two characters may map to the same character
            // We're mapping b to b
            // Then we want to map d to b, but we can't, cus now there's two mappings to b

            if(mappings_s_to_t.find(*it_s) != mappings_s_to_t.end())
            {
                if(mappings_s_to_t[*it_s] == *it_t)
                {
                    ++it_s;
                    continue;
                }
                return false;
            }

            if(mappings_t_to_s.find(*it_t) == mappings_t_to_s.end())
            {
                mappings_s_to_t[*it_s] = *it_t;
                mappings_t_to_s[*it_t] = *it_s;
            }
            else
            {
                return false;
            }

            ++it_s;
        }

        return true;

    }
};