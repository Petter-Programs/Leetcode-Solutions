enum Direction { RIGHT, LEFT, UP, DOWN };

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize,
                 int* returnSize) {

    int size = matrixSize * *matrixColSize;

    int* output = malloc(sizeof(int) * size);
    *returnSize = size;

    int current_row = 0;
    int current_col = 0;

    enum Direction current_direction = RIGHT;

    for (int i = 0; i < size; i++) {

        output[i] = matrix[current_row][current_col];
        matrix[current_row][current_col] = INT_MIN;

        switch (current_direction) {
        case (RIGHT):
            if (current_col+1 < *matrixColSize &&
                matrix[current_row][current_col + 1] != INT_MIN) {
                current_col++;
            } else {
                current_direction = DOWN;
                current_row++;
            }
            break;
        case (LEFT):
            if (current_col > 0 &&
                matrix[current_row][current_col - 1] != INT_MIN) {
                current_col--;
            } else {
                current_direction = UP;
                current_row--;
            }
            break;
        case (UP):
            if (current_row > 0 &&
                matrix[current_row - 1][current_col] != INT_MIN) {
                current_row--;
            } else {
                current_direction = RIGHT;
                current_col++;
            }
            break;
        case (DOWN):
            if (current_row+1 < matrixSize &&
                matrix[current_row + 1][current_col] != INT_MIN) {
                current_row++;
            } else {
                current_direction = LEFT;
                current_col--;
            }
            break;
        }
    }

    return output;
}