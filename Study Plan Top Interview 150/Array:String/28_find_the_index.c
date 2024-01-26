int strStr(char* haystack, char* needle) {

    int index = 0;
    int localIndex = 0;
    char* needlePointer = needle;
    
    for(; *haystack!='\0'; haystack++)
    {
        if(*haystack == *needlePointer)
        {
            needlePointer++;
            localIndex++;
        }
        else
        {
            needlePointer = needle;

            if(localIndex>0)
            {
                haystack-=localIndex;
            }
            index++;
            localIndex = 0;
        }

        if(*needlePointer == '\0')
        {
            return index;
        }

    }

    return -1;

}