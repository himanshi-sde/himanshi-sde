
//Problem Link: https://leetcode.com/problems/number-of-closed-islands/
/*

1. Initialize the closed island count to 0.
2. Iterate through each cell in the grid.
3. Check if the cell is land (0).
4. Perform DFS to determine if the island is closed.
5. Increment the closed island count if the DFS confirms the island is closed.
6. Return the closed island count.*/

class Solution {
public:
    // Function to count the number of closed islands
    int closedIsland(vector<vector<int>>& grid) {
        int closedIslandCount = 0;

        // Iterate through each cell in the grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // If the cell is land (0), perform a DFS to check if it's a closed island
                if (grid[i][j] == 0) {
                    // Increment count if the DFS confirms it's a closed island
                    if (dfs(grid, i, j)) {
                        closedIslandCount++;
                    }
                }
            }
        }

        return closedIslandCount;
    }

private:
    // Depth-First Search (DFS) helper function to determine if an island is closed
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        // If the current cell is out of grid boundaries, it's not a closed island
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return false;
        }

        // If the current cell is water (1), it's part of the boundary, thus valid for a closed island
        if (grid[i][j] == 1) {
            return true;
        }

        // Mark the current land cell (0) as visited by setting it to 1
        grid[i][j] = 1;

        // Perform DFS in all four directions
        bool down = dfs(grid, i + 1, j);
        bool right = dfs(grid, i, j + 1);
        bool up = dfs(grid, i - 1, j);
        bool left = dfs(grid, i, j - 1);

        // An island is closed only if all four directions return true (i.e., all are bounded by water)
        return down && right && up && left;
    }
};
