#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {

    int rows = matrixSize;
    int cols = *matrixColSize;

    *returnSize = cols;
    *returnColumnSizes = (int*)malloc(sizeof(int) * cols);

    int** result = (int**)malloc(sizeof(int*) * cols);
    
    for (int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;
        result[i] = (int*)malloc(sizeof(int) * rows);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    return result;
}
