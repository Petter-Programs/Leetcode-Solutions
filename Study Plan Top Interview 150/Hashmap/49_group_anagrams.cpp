class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {

        std::map<std::array<int, 26>, std::vector<std::string>> results;

        for(auto it = strs.begin(); it != strs.end(); ++it)
        {
            std::string curr = *it;

            std::array<int, 26> mapping = {};
            
            for(auto it_str = curr.begin(); it_str != curr.end(); ++it_str)
            {
                mapping[*it_str-'a']++;
            }

            results[mapping].push_back(curr);
        }

        std::vector<std::vector<std::string>> formatted_results;
        
        for(auto it = results.begin(); it != results.end(); ++it)
        {
            formatted_results.push_back(it->second);
        }

        return formatted_results;
        
    }
};