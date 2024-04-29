void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int should_zero_top = 0;
    int should_zero_left = 0;

    for (int i = 0; i < *matrixColSize; i++) {
        if (matrix[0][i] == 0) {
            should_zero_top = 1;
            break;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            should_zero_left = 1;
            break;
        }
    }

    if (matrixSize > 1 && (*matrixColSize) > 1) {

        // Mark each row/column to be zeroed out
        for (int i = 1; i < matrixSize; i++) {
            for (int j = 1; j < *matrixColSize; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero out columns
        for (int i = 1; i < *matrixColSize; i++) {
            if (matrix[0][i] != 0)
                continue;

            for (int j = 1; j < matrixSize; j++) {
                matrix[j][i] = 0;
            }
        }

        // Zero out rows
        for (int i = 0; i < matrixSize; i++) {
            if (matrix[i][0] != 0)
                continue;

            for (int j = 1; j < *matrixColSize; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    if (should_zero_top) {
        for (int i = 0; i < *matrixColSize; i++) {
            matrix[0][i] = 0;
        }
    }

    if (should_zero_left) {
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}