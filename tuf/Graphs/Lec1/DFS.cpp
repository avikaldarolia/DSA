// Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void dfs(int src, vector<vector<int>>& adj,vector<bool> &vis, vector<int> &ans){
        vis[src] = true;
        ans.push_back(src);
        
        for(auto e: adj[src]){
            if(!vis[e]){
                dfs(e, adj, vis, ans);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        const int n = (int)adj.size();
        vector<int> ans;
        vector<bool> vis(n, false);
        dfs(0, adj, vis, ans);
        
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}