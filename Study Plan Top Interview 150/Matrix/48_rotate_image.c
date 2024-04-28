void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int left = 0;
    int right = matrixSize-1;

    while(left<right)
    {
        for(int i = 0; i<right-left; i++)
        {
            int top = left;
            int bottom = right;

            int top_left = matrix[top][left+i];

            matrix[top][left+i] = matrix[bottom-i][left];
            matrix[bottom-i][left] = matrix[bottom][right-i];
            matrix[bottom][right-i] = matrix[top+i][right];
            matrix[top+i][right] = top_left;
        }

        left++;
        right--;
    }
    
}