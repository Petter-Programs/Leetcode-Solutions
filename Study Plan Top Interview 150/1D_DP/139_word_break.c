bool wordBreak(char* s, char** wordDict, int wordDictSize) 
{       
    int s_len = strlen(s);

    bool *dp_arr = calloc(s_len+1, sizeof(char));

    dp_arr[s_len] = true;

    for(int i = s_len-1; i>=0; i--)
    {
        for(int w = 0; w<wordDictSize; w++)
        {
            int w_len = strlen(wordDict[w]);
            if(w_len <= s_len-i && strncmp(wordDict[w], s+i, w_len) == 0)
            {
                dp_arr[i] = dp_arr[i+w_len];
            }
            
            if(dp_arr[i])
                break;
        }   
    }

    return dp_arr[0];
}