// Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// User function Template for C++

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int> distance(V, INT_MAX);
        distance[0] = 0;
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
        }
        
        priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto &child: adj[node]){
                int childNode = child.first;
                int childwt = child.second;
                if(distance[childNode] == INT_MAX || (distance[childNode] > (dist + childwt))){
                    distance[childNode] = childwt + dist;
                    pq.push({distance[childNode], childNode});
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }
        
        return distance;
    }  
};