// Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        const int n = (int)adj.size();
        
        vector<int> bfs;
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int parent = q.front();
            q.pop();
            
            bfs.push_back(parent);
            
            for(auto &v: adj[parent]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
        return bfs;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends