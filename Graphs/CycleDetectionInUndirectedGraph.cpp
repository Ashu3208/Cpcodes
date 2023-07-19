// Given a undirected graph with N vertices and M edges find if it contains a cycle. The graphs can have multiple components.
#include <vector>

bool dfs(int source, const vector<vector<int>>& list, vector<bool>& visited, int parent) {
    visited[source] = true;
    for (auto nbr : list[source]) {
        if (!visited[nbr]) {
            if (dfs(nbr, list, visited, source)) {
                return true;
            }
        } else if (parent != nbr) {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int V, int m) {
    vector<bool> visited(V + 1, false);
    vector<vector<int>> list(V + 1);
    for (int i = 0; i < m; i++) {
        list[edges[i][0]].push_back(edges[i][1]);
        list[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i = 1; i <= V; ++i){
        if(!visited[i] ){
            if (dfs(i, list, visited, -1)) {
                return "Yes";
            }
         }
    }
   
        return "No";
 
}
