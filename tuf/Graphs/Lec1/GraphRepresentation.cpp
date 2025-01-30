// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    // Code here
    vector<vector<int>> g(V);
    for(auto &e: edges){
        int u = e.first;
        int v = e.second;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    return g;
}