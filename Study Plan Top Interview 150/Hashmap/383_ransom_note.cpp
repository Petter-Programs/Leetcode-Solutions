class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        std::unordered_map<char, int> map;

        for (char c = 'a'; c <= 'z'; ++c) 
            map[c] = 0;

        for(std::string::iterator it = magazine.begin(); it != magazine.end(); ++it)
        {
            map[*it]++;
        }

        for(std::string::iterator it = ransomNote.begin(); it != ransomNote.end(); ++it)
        {
            map[*it]--;

            if(map[*it] < 0)
                return false;
        }

        return true;

    }
};