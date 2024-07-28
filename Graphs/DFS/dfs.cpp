
// DFS of a Graph

void dfs(vector<vector<int>> &graph, int s, vector<bool> &vis){
    // s is source
        vis[s] = true;
        for(int i = 0; i < graph[s].size(); i++){
            if(!vis[graph[s][i]]){
                dfs(graph, graph[s][i], vis);
            }
        }
    }