bool isSubsequence(char* s, char* t) 
{
    while(*s != '\0')
    {
        if(*t == '\0')
            return false;

        if(*s == *t)
        { 
            s++;
        }

        t++;
    }

    return true;
    
}