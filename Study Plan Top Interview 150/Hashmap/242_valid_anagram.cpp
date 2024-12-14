class Solution {
public:
    bool isAnagram(string s, string t) {

        // create counts of each character in s
        // like [a, 2], [b, 1]
        // then go through t and decrement. If ever negative, reject
        // special case is when s.length() != t.length(), reject instantly

        // But we can be smarter and do the counts inside the one loop
        // Just need to keep track of whether or not we have non-matches
        // Though it seems this solution is slower for whatever reason

        if(s.length() != t.length())
            return false;

        std::map<char, int> s_counts;

        int negative_count = 0;

        std::string::iterator it_t = t.begin();
        for(std::string::iterator it_s = s.begin(); it_s != s.end(); ++it_s)
        {
            if(*it_s != *it_t)
            {
                s_counts[*it_s]++;
                s_counts[*it_t]--;

                if(s_counts[*it_s] == 0)
                    negative_count--;
                if(s_counts[*it_t] == -1)
                    negative_count++;
            }

            it_t++;
        }

        if(negative_count>0)
            return false;

        return true;

    }
};
