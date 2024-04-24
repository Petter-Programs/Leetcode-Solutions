int lengthOfLongestSubstring(char* s)
{
    int longest = 0;

    if(*s == '\0')
        return longest;

    longest = 1;

    int length = strlen(s);

    int left = 0;

    int current_length = 1;

    for(int right = 1; right<length; right++)
    {
        char current = s[right];

        int duplicate_index = -1;

        for(int i = left; i<right; i++)
        {
            if(s[i] == current)
            {
                duplicate_index = i;
                break;
            }
        }

        if(duplicate_index == -1)
        {
            current_length++;
            if(current_length>longest)
                longest = current_length;
        }
        else
        {
            current_length -= duplicate_index-left;
            left = duplicate_index+1;
        }
    }

    return longest;
    
}