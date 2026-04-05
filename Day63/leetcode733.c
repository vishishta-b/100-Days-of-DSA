#include <stdio.h>
#include <stdlib.h>

/**
 * Helper function to perform DFS and fill colors.
 */
void dfs(int** image, int row, int col, int rows, int cols, int oldColor, int newColor) {
    // Boundary check and color check
    if (row < 0 || row >= rows || col < 0 || col >= cols || image[row][col] != oldColor) {
        return;
    }

    // Fill the current pixel with the new color
    image[row][col] = newColor;

    // Recursively fill 4-directional neighbors
    dfs(image, row + 1, col, rows, cols, oldColor, newColor); // Down
    dfs(image, row - 1, col, rows, cols, oldColor, newColor); // Up
    dfs(image, row, col + 1, rows, cols, oldColor, newColor); // Right
    dfs(image, row, col - 1, rows, cols, oldColor, newColor); // Left
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int rows = imageSize;
    int cols = imageColSize[0];
    int oldColor = image[sr][sc];

    // If the starting pixel is already the target color, no work is needed.
    // This also prevents infinite recursion.
    if (oldColor != color) {
        dfs(image, sr, sc, rows, cols, oldColor, color);
    }

    // Set return parameters for LeetCode's judge
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }

    return image;
}
