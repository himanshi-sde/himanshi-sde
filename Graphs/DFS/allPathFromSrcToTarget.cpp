
// Problem Link: https://leetcode.com/problems/all-paths-from-source-to-target/description/?envType=study-plan-v2&envId=graph-theory

/*Approach Steps

1. Determine the target node as the last node in the graph.
2. Initialize `result` to store all valid paths and `tempVec` for the current path.
3. Implement the `dfs` function to explore paths recursively.
4. Add the current node to `tempVec`.
5. If the current node is the target, add `tempVec` to `result`.
6. Recursively call `dfs` for each neighbor if the target is not reached.
7. Backtrack by removing the current node from `tempVec` and return the result.*/


class Solution {
public:
    void dfs(int src,vector<vector<int>>&graph,int target,vector<vector<int>>& result,vector<int>&tempVec){

        tempVec.push_back(src);
        if(src==target) result.push_back(tempVec);
        else{
            for( auto node: graph[src])
                dfs(node,graph,target,result,tempVec);
        }
        tempVec.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target=graph.size()-1;
        vector<vector<int>>result;
        vector<int>tempVec;
        dfs(0,graph,target,result,tempVec);
        return result;
    }
};