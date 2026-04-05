#include <stdbool.h>
#include <stdlib.h>

/**
 * Recursive DFS helper function to visit rooms.
 */
void dfs(int** rooms, int roomsSize, int* roomsColSize, int currentRoom, bool* visited) {
    // Mark the current room as visited
    visited[currentRoom] = true;

    // Look at all the keys available in the current room
    for (int i = 0; i < roomsColSize[currentRoom]; i++) {
        int key = rooms[currentRoom][i];
        
        // If we have a key to a room we haven't visited yet, go there
        if (!visited[key]) {
            dfs(rooms, roomsSize, roomsColSize, key, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    // Allocate a visited array for 'n' rooms
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    
    // Start the traversal from Room 0
    dfs(rooms, roomsSize, roomsColSize, 0, visited);
    
    // After DFS, check if any room remains unvisited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return false; // Found a room we couldn't reach
        }
    }
    
    free(visited);
    return true; // All rooms visited
}
