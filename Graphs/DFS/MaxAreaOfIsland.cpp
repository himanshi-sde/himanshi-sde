
// leetcode problem Link: https://leetcode.com/problems/max-area-of-island/description/


class Solution {
public:
    // Depth-First Search (DFS) to calculate the area of an island
    void dfs(vector<vector<int>>& grid, int row, int col, int& currentArea) {
        // Boundary and condition checks
        if (row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0 || grid[row][col] == 0) {
            return;
        }

        // Mark the cell as visited by setting it to 0
        grid[row][col] = 0;
        currentArea++;

        // Visit neighboring cells (down, up, right, left)
        dfs(grid, row + 1, col, currentArea);
        dfs(grid, row - 1, col, currentArea);
        dfs(grid, row, col + 1, currentArea);
        dfs(grid, row, col - 1, currentArea);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        // Iterate through each cell in the grid
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    int currentArea = 0;
                    dfs(grid, row, col, currentArea); // Calculate area of the current island
                    maxArea = max(maxArea, currentArea); // Update maxArea if currentArea is larger
                }
            }
        }

        return maxArea;
    }
};
