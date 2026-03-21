#define INVALID_CHAR ' '

char* longestPalindrome(char* s) 
{    
    int longest_seen = 1;
    size_t len = strlen(s);
    char last_char = INVALID_CHAR;

    int word_idx_start = 0;
    int word_idx_end = 0;

    bool more_than_one_char = false;
    for(int i = 1; i<len; i++)
    {
        if(s[i-1] != s[i])
        {
            more_than_one_char = true;
            break;
        }
    }

    if(!more_than_one_char)
        return s;

    for(int i = 0; i<len; i++)
    {
        char curr_char = s[i];
        char next_char = i < len-1 ? s[i+1] : INVALID_CHAR;

        int curr_len = 1;
        int left_idx = i;
        int right_idx = i;

        while(left_idx-1 >= 0 && right_idx+1 <=len-1
                && s[left_idx-1] == s[right_idx+1])
        {
            left_idx--;
            right_idx++;
            curr_len+=2;
        }

        if(curr_len > longest_seen)
        {
            longest_seen = curr_len;
            word_idx_start = left_idx;
            word_idx_end = right_idx;
        }

        if(last_char == curr_char)
        {
            curr_len = 2;
            left_idx = i-1;
            right_idx = i;
        }

        while(left_idx-1 >= 0 && right_idx+1 <=len-1
                && s[left_idx-1] == s[right_idx+1])
        {
            left_idx--;
            right_idx++;
            curr_len+=2;
        }

        if(curr_len > longest_seen)
        {
            longest_seen = curr_len;
            word_idx_start = left_idx;
            word_idx_end = right_idx;
        }

        last_char = s[i];
    }

    int needed_len = (word_idx_end - word_idx_start) + 2;
    char *result = malloc(needed_len);

    memcpy(result, s+word_idx_start, needed_len-1);    
    result[needed_len-1] = '\0';

    return result;

}