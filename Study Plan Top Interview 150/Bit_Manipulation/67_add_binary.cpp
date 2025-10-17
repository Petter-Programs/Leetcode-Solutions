class Solution {
public:
    string addBinary(string a, string b) 
    {
        int a_idx = a.size()-1;
        int b_idx = b.size()-1;

        int carry = 0;
        std::string answer = "";

        while(a_idx >=0 || b_idx >=0)
        {
            char *a_pointer = a_idx >= 0 ? &a[a_idx] : NULL;
            char *b_pointer = b_idx >= 0 ? &b[b_idx] : NULL;

            int a_digit = a_pointer && *a_pointer == '1' ? 1 : 0;
            int b_digit = b_pointer && *b_pointer == '1' ? 1 : 0;

            int sum = a_digit + b_digit + carry;

            carry = sum / 2;

            if(sum % 2 == 0)
                answer+="0";

            else
                answer+="1";

            a_idx--;
            b_idx--;
        }

        if(carry != 0)
        {
            answer+="1";
        }

        std::reverse(answer.begin(), answer.end());
        return answer;
        
    }
};