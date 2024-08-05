
// Problem Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

/*
Initialize Result:

Start by setting the result (res) to 0. This will store the maximum time required to inform all employees.
Iterate Through Each Employee:

Loop through all employees from 0 to n-1.
Depth-First Search (DFS):

For each employee, perform a DFS to calculate the total time needed to inform that employee.
If the employee's manager is not yet informed (manager[i] != -1), recursively calculate the time to inform the manager and add it to the employee's inform time.
Mark the manager as informed by setting manager[i] = -1.
Update Result:

After the DFS, update the result (res) with the maximum time obtained from the DFS.
Return Result:

Finally, return the result (res), which represents the maximum time required to inform all employees.
*/

class Solution {
public:
    // Function to calculate the total time needed to inform all employees
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        
        // Iterate through each employee to calculate the maximum time required to inform them
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(i, manager, informTime));
        }
        
        return res;
    }

private:
    // Depth-First Search (DFS) to calculate the total inform time for a given employee
    int dfs(int i, vector<int>& manager, vector<int>& informTime) {
        // If the current employee's manager has not been processed yet
        if (manager[i] != -1) {
            // Recursively calculate the inform time for the manager and add it to the current employee's inform time
            informTime[i] += dfs(manager[i], manager, informTime);
            // Mark the manager as processed
            manager[i] = -1;
        }
        
        // Return the total inform time for the current employee
        return informTime[i];
    }
};
