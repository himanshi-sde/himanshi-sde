//Problem Link: https://leetcode.com/problems/find-eventual-safe-states/description/?envType=study-plan-v2&envId=graph-theory

/*
We will use Topological Sort in this problem.
We will take use queue and store all the nodes with zero outdegree in it.
The nodes with zero outdegree are our safe nodes. Hence, we include it in our answer.
We we remove nodes with zero outdegree from graph, all the nodes which we connected to that node, their outdegree also decreases by one.
In last, if no node with outdegree zero is left, we stop our process.
*/


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int numNodes = graph.size();
    vector<vector<int>> reverseGraph(numNodes);
    vector<int> outDegree(numNodes), isSafe(numNodes), safeNodes;
    queue<int> nodesQueue;
    
    // Build the reverse graph and initialize outDegree array
    for (int node = 0; node < numNodes; ++node) {
        for (int neighbor : graph[node]) {
            reverseGraph[neighbor].push_back(node);
        }
        outDegree[node] = graph[node].size();
        if (outDegree[node] == 0) nodesQueue.push(node);  // Terminal nodes
    }
    
    // Process nodes in the queue
    while (!nodesQueue.empty()) {
        int currentNode = nodesQueue.front();
        nodesQueue.pop();
        isSafe[currentNode] = 1;
        for (int parent : reverseGraph[currentNode]) {
            if (--outDegree[parent] == 0) nodesQueue.push(parent);
        }
    }
    
    // Collect all safe nodes
    for (int node = 0; node < numNodes; ++node) {
        if (isSafe[node]) safeNodes.push_back(node);
    }
    
    return safeNodes;
}
