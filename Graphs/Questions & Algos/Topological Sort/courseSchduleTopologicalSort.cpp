
//Problem Link: https://leetcode.com/problems/course-schedule-ii/description/

/*### Approach:

1. **Graph Representation and Indegree Initialization:**
   - Represent the graph using an adjacency list and initialize indegrees for each course.

2. **Form the Graph:**
   - Populate the adjacency list based on the prerequisites and calculate the indegree for each course.

3. **Initialize Queue:**
   - Add courses with no prerequisites to the queue.

4. **Topological Sorting using BFS:**
   - Process the courses in the queue, adding them to the result list and decrementing the indegrees of their dependent courses. Add dependent courses with zero remaining prerequisites to the queue.

5. **Check for Valid Ordering:**
   - Return the result list if all courses can be finished, otherwise return an empty list.
   
   */

class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(N);                   // Adjacency list to represent the graph
        vector<int> ans, indegree(N, 0);                // indegree[i] denotes the number of prerequisites for the ith course

        // Form the graph and calculate indegrees
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);            // Add edge from pre[1] to pre[0]
            indegree[pre[0]]++;                         // Increment the indegree of course pre[0]
        }

        // Initialize the queue with courses having no prerequisites
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the courses in topological order
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);                         // Add the current course to the result list

            for (auto nextCourse : graph[cur]) {
                if (--indegree[nextCourse] == 0) {      // If the next course has no remaining prerequisites,
                    q.push(nextCourse);                 // add it to the queue
                }
            }
        }

        // Check if a valid ordering exists
        if (ans.size() == N) {
            return ans;                                 // Return the ordering if all courses can be finished
        }
        
        return {};                                      // Return an empty list if not all courses can be finished
    }
};
