

// leetcode problem link: https://leetcode.com/problems/keys-and-rooms/




class Solution {
public:
    // Depth-First Search (DFS) to explore all accessible rooms from the starting room
    void dfs(vector<vector<int>>& rooms, int currentRoom, vector<bool>& visited) {
        // Mark the current room as visited
        visited[currentRoom] = true;

        // Visit all rooms that can be accessed with the keys in the current room
        for (int i = 0; i < rooms[currentRoom].size(); i++) {
            int nextRoom = rooms[currentRoom][i];
            if (!visited[nextRoom]) {
                dfs(rooms, nextRoom, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false); // Initialize visited rooms tracker

        // Start DFS from room 0
        dfs(rooms, 0, visited);

        // Check if all rooms have been visited
        for (int i = 0; i < rooms.size(); i++) {
            if (!visited[i]) {
                return false; // If any room is not visited, return false
            }
        }

        return true; // All rooms have been visited
    }
};
