


// Leetcode Problem Link: https://leetcode.com/problems/number-of-islands/




class Solution {
public:
    // Depth-First Search to mark all parts of an island as visited
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& visited) {
        // Boundary and condition checks
        if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] == '0') {
            return;
        }

        // Mark the cell as visited by setting it to '0'
        grid[row][col] = '0';

        // Visit the neighboring cells
        dfs(grid, row + 1, col, visited); // down
        dfs(grid, row - 1, col, visited); // up
        dfs(grid, row, col + 1, visited); // right
        dfs(grid, row, col - 1, visited); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0)); // Initialize visited matrix

        // Iterate through each cell in the grid
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                // If a cell is part of an island, perform DFS and increment the island count
                if (grid[row][col] == '1') {
                    dfs(grid, row, col, visited);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};
