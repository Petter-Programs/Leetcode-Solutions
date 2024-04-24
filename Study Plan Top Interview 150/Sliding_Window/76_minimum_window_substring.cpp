// create first window by growing
// once we have a match, we never need to expand again
// only move window rightwards

class Solution {
public:
    string minWindow(string s, string t) {

        std::unordered_map<char, int> char_count;
        int total_char_count = 0;

        std::string sub_string = "";

        if (t.length() > s.length())
            return sub_string;

        for (char c : t) {
            char_count[c]++;
            total_char_count++;
        }

        int left = 0;
        int right = -1;

        int length = static_cast<int>(s.length());

        bool have_first_sub_string = false;
        int idx1 = -1;
        int idx2 = -1;

        while (right <= length) {

            bool shrunk = false;

            if (have_first_sub_string && right > left) {

                char curr = s[left];

                left++;

                auto it = char_count.find(curr);

                if (it != char_count.end()) {
                    char_count[curr]++;
                    if (char_count[curr] > 0)
                        total_char_count++;
                }

                if (total_char_count == 0) {

                    if(idx2-idx1 > right-left)
                    {
                        idx1 = left;
                        idx2 = right;
                        shrunk = true;
                    }
                }
            }

            if (!shrunk) {
                right++;

                if(right>=length)
                    break;

                char curr = s[right];

                auto it = char_count.find(curr);

                if (it != char_count.end()) {
                    char_count[curr]--;
                    if (char_count[curr] >= 0)
                        total_char_count--;

                    if (!have_first_sub_string && total_char_count == 0) {

                        have_first_sub_string = true;
                        idx1 = left;
                        idx2 = right;
                    }
                }
            }
        }

        if(have_first_sub_string)
            sub_string = s.substr(idx1, idx2 - idx1 + 1);

        return sub_string;
    }
};