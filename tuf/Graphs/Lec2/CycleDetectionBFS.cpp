// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<bool>vis;
    bool detect(int src, vector<vector<int>>& adj){
        queue<pair<int,int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            vis[node] = true;
            q.pop();
            
            for(auto child: adj[node]){
                if(!vis[child]){
                    q.push({child, node});
                }
                else if(parent != child){
                    return true;
                }
            }
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        const int n = (int)adj.size();
        vis.resize(n, false);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(detect(i, adj)){
                    return true;
                }
            }
        }
            
        return false;
        
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}