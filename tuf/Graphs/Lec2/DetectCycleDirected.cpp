// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &path){
        vis[node] = true;
        path[node] = true;
        for(auto child: adj[node]){
            if(!vis[child]){
                if(dfs(child, adj, vis, path)){
                    return true;
                }
            }
            // if visited
            else{
                // check for path is marked or not
                if(path[child]){
                    return true;
                }
            }
        }
        path[node] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V, false);
        vector<bool> path(V, false);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                path[i] = true;
                if(dfs(i,adj,vis, path)){
                    return true;
                }
            }
        }
        
        return false;
    }
};