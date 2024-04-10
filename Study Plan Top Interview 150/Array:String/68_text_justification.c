/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize)
{
    // Malloced to upper limit of size (each word is maxWidth)
    char** the_answer = malloc(sizeof(char*) * wordsSize);

    int wordIdx = 0;
    int rowIdx = 0;

    while(wordIdx < wordsSize)
    {

    the_answer[rowIdx] = malloc(sizeof(char) * maxWidth+1);
    
    char* current_word = words[wordIdx];
    int maxLength = maxWidth;
    int wordsThatFit = 0;

    while(maxLength>0 && wordIdx < wordsSize)
    {
        current_word = words[wordIdx];

        int length = getLengthOfWord(current_word);

        // There is already a word, so need to fit a space
        if(wordsThatFit>0)
            length++;

        if(maxLength >= length)
        {
            wordsThatFit++;
            wordIdx++;
            maxLength -= length;
        }
        else
        {
            break;
        }
    }
    
    int spacesToDistribute = maxLength;

    // Already includes a space for each word after first
    if(wordsThatFit>1)
        spacesToDistribute+=wordsThatFit-1;

    int spacePerWord, remainderToDistr = 0;

    if(wordsThatFit>1)
    {
        spacePerWord = spacesToDistribute / (wordsThatFit-1);
        remainderToDistr  = spacesToDistribute - (spacePerWord*(wordsThatFit-1));
    }
    else
    {
        spacePerWord = spacesToDistribute;
    }

    if(wordIdx != wordsSize)
    {
        int characterIdx = 0;
        int endOfCurrentWord = 0;
        int spaceLeft = spacePerWord;

        if(remainderToDistr > 0)
        {
            spaceLeft++;
            remainderToDistr--;
        }

        for(int i = 0; i<maxWidth; i++)
        {
            char* currentWord = words[wordIdx - wordsThatFit];
            char currentCharacter = currentWord[characterIdx];
            
            if(currentCharacter == '\0')
            {
                endOfCurrentWord = 1;
                currentCharacter = ' ';      
            }

            if(endOfCurrentWord && spaceLeft>1)
            {
                spaceLeft--;
            }
            else if(endOfCurrentWord)
            {
                wordsThatFit--;
                endOfCurrentWord = 0;
                spaceLeft = spacePerWord;

                if(remainderToDistr > 0)
                {
                    spaceLeft++;
                    remainderToDistr--;
                }

                the_answer[rowIdx][i] = currentCharacter;
                characterIdx = 0;
                continue;       
            }
            
            the_answer[rowIdx][i] = currentCharacter;

            if(currentWord[characterIdx] != '\0')
                characterIdx++;
        }
    }
    else
    {
        int characterIdx = 0;
        for(int i = 0; i<maxWidth; i++)
        {
            char currentCharacter;

            if(wordsThatFit>0)
            {
                char* currentWord = words[wordIdx-wordsThatFit];
                currentCharacter = currentWord[characterIdx];

                if(currentCharacter == '\0')
                {
                    currentCharacter = ' ';
                    characterIdx = 0;
                    the_answer[rowIdx][i] = currentCharacter;
                    wordsThatFit--;
                    continue;
                }
            }
            else
            {
                currentCharacter = ' ';
            }

            the_answer[rowIdx][i] = currentCharacter;
            characterIdx++;
        }

    }

    the_answer[rowIdx][maxWidth] = '\0';
    rowIdx++;
    }

    *returnSize = rowIdx;
    return the_answer;
    
}

int getLengthOfWord(char* the_word)
{
    int length = 0;

    while(*the_word != '\0')
    {
        length++;
        the_word++;
    }

    return length;    
}