int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int totalElements = rows * cols;
    int* result = (int*)malloc(sizeof(int) * totalElements);
    *returnSize = 0;

    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (*returnSize < totalElements) {
        for (int j = left; j <= right && *returnSize < totalElements; j++)
            result[(*returnSize)++] = matrix[top][j];
        top++;

        for (int i = top; i <= bottom && *returnSize < totalElements; i++)
            result[(*returnSize)++] = matrix[i][right];
        right--;

        for (int j = right; j >= left && *returnSize < totalElements; j--)
            result[(*returnSize)++] = matrix[bottom][j];
        bottom--;

        for (int i = bottom; i >= top && *returnSize < totalElements; i--)
            result[(*returnSize)++] = matrix[i][left];
        left++;
    }

    return result;
}
