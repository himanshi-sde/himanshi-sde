
// Problem Link: https://leetcode.com/problems/rotting-oranges/

/*
### Approach:

1. **Initialize Directions:**
   - A direction vector is used to easily find all four adjacent cells (up, down, left, right).

2. **Grid Dimensions:**
   - Retrieve the number of rows (`m`) and columns (`n`).

3. **Queue Initialization:**
   - Initialize a queue to perform BFS.
   - Count the number of fresh oranges.

4. **Initialize Rotten Oranges and Count Fresh Oranges:**
   - Add all initially rotten oranges to the queue.
   - Count the total number of fresh oranges.

5. **Breadth-First Search (BFS):**
   - Process the queue level by level, which corresponds to each minute passing.
   - For each rotten orange, check its four adjacent cells.
   - If an adjacent cell has a fresh orange, rot it, add it to the queue, and decrement the fresh orange count.

6. **Calculate Minutes:**
   - Increment the minute counter after processing all oranges at the current level of BFS.
   - If there are still fresh oranges left after BFS, return `-1`.
   - If no oranges were initially present, return `0`. Otherwise, return the total minutes calculated.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> direction = {-1, 0, 1, 0, -1}; // Directions to find all 4 adjacent coordinates
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int freshOranges = 0; // To keep track of all fresh oranges

        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        int minutes = -1; // Initializing to -1 because we increment time after each step

        // Perform BFS to rot adjacent fresh oranges
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> current = q.front();
                q.pop();

                // Check all 4 directions
                for (int i = 0; i < 4; ++i) {
                    int newRow = current.first + direction[i];
                    int newCol = current.second + direction[i + 1];

                    // If the adjacent cell has a fresh orange, rot it
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        freshOranges--; // Decrement fresh oranges count
                    }
                }
            }
            minutes++; // Increment minutes after processing one level of BFS
        }

        // If there are still fresh oranges left, return -1
        if (freshOranges > 0) {
            return -1;
        }

        // If no oranges were initially present, it would take 0 minutes
        return (minutes == -1) ? 0 : minutes;
    }
};
