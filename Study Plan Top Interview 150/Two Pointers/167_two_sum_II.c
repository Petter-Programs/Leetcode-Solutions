/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int *answer = malloc(sizeof(int)*2);

    int indexOne = 0;
    int indexTwo = numbersSize-1;

    int sum = numbers[indexOne]+numbers[indexTwo];

    while(sum!=target)
    {
        if(sum>target)
        {
            int currentNumber = numbers[indexTwo];
            while(numbers[indexTwo]==currentNumber)
                indexTwo--;
        }
        else
        {
            int currentNumber = numbers[indexOne];
            while(numbers[indexOne]==currentNumber)
                indexOne++;
        }

        sum = numbers[indexOne]+numbers[indexTwo];
    }

    answer[0] = indexOne+1;
    answer[1] = indexTwo+1;

    *returnSize = 2;
    return answer;

}