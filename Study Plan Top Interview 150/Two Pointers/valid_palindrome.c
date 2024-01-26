bool isPalindrome(char* s)
{

int length = strlen(s);

int pointerOne = 0;
int pointerTwo = length;

while(pointerOne<pointerTwo)
{
    char firstSide = tolower(s[pointerOne]);

    if(!isalnum(firstSide))
    {
        pointerOne++;
        continue;
    }

    char secondSide = tolower(s[pointerTwo]);

    if(!isalnum(secondSide))
    {
        pointerTwo--;
        continue;
    }

    if(firstSide!=secondSide)
    {
        return false;
    }

    pointerTwo--;
    pointerOne++;

}

return true;

}