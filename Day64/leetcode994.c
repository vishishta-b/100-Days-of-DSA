#include <stdio.h>
#include <stdlib.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    
    // Array-based queue to store coordinates (r, c)
    // Max grid size is 10x10, so a size of 105 is safe.
    int queue[105][2]; 
    int front = 0, rear = 0;
    
    int fresh_count = 0;
    
    // Step 1: Initialize the queue with all initially rotten oranges
    // and count the total number of fresh oranges.
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 2) {
                queue[rear][0] = r;
                queue[rear][1] = c;
                rear++;
            } else if (grid[r][c] == 1) {
                fresh_count++;
            }
        }
    }
    
    // If there are no fresh oranges to begin with, it takes 0 minutes.
    if (fresh_count == 0) {
        return 0;
    }
    
    int minutes = 0;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // Step 2: Multi-source BFS
    while (front < rear && fresh_count > 0) {
        // Number of oranges rotting at the current minute
        int level_size = rear - front; 
        minutes++;
        
        for (int i = 0; i < level_size; i++) {
            // Dequeue the current rotten orange
            int r = queue[front][0];
            int c = queue[front][1];
            front++;
            
            // Check all 4 adjacent directions
            for (int d = 0; d < 4; d++) {
                int nr = r + directions[d][0];
                int nc = c + directions[d][1];
                
                // If the neighbor is within bounds and is a fresh orange
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // Mark as rotten
                    fresh_count--;    // Decrement the fresh count
                    
                    // Enqueue the newly rotted orange for the next minute
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                }
            }
        }
    }
    
    // Step 3: Check if all fresh oranges were successfully infected
    if (fresh_count == 0) {
        return minutes;
    } else {
        return -1; // Some oranges could not be reached
    }
}
