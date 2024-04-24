int lengthOfLastWord(char* s)
{
    int lastLength = 0;
    int length = 0;

    for (; *s != '\0'; s++)
    {
        if(isspace(*s))
        {
            if(length>0)
                lastLength = length;
            
            length = 0;
        }
        else
        {
            length++;
        }
    }

    return length>0 ? length : lastLength;
}