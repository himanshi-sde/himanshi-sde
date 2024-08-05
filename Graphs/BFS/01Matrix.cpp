
// Problem Link: https://leetcode.com/problems/01-matrix/description/


/*

1. Initialize a Queue for BFS: Create a queue to hold cells for breadth-first search (BFS).
2. Mark Distance for Zero Cells: Set the distance for all cells with value `0` to `0` and add them to the queue.
3. Initialize Distance for Other Cells: Set the distance for all other cells to `-1` (indicating they haven't been visited yet).
4. Perform BFS:** Use BFS to explore each cell level by level:
   - For each cell in the queue, check its neighbors (up, down, left, right).
   - If a neighbor hasn't been visited, update its distance and add it to the queue.
5. Return the Distance Matrix: Once BFS completes, the distance matrix will contain the shortest distance from each cell to the nearest `0` cell.

This ensures that each cell's distance is calculated efficiently, with BFS ensuring exploration in increasing order of distance.
*/

class Solution {
public:
    // Function to check if a cell (i, j) is within the matrix boundaries
    bool isValid(int i, int j, int m, int n) {
        return !(i >= m || j >= n || i < 0 || j < 0);
    }

    // Directions array to move up, down, left, and right
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Queue to perform BFS
        queue<pair<int, int>> q;
        vector<vector<int>> distance(m, vector<int>(n, -1));

        // Initialize queue with all zero cells and set their distance to 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }

        // Perform BFS
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            for (auto& direction : directions) {
                int newRow = current.first + direction[0];
                int newCol = current.second + direction[1];

                // If the new cell is within boundaries and hasn't been visited
                if (isValid(newRow, newCol, m, n) && distance[newRow][newCol] == -1) {
                    q.push({newRow, newCol});
                    distance[newRow][newCol] = distance[current.first][current.second] + 1;
                }
            }
        }

        return distance;
    }
};
