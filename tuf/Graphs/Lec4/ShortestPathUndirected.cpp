// Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        const int n = adj.size();
        vector<int> distance(n, INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        distance[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto child: adj[node]){
                if(distance[child] == INT_MAX && distance[child] > (dist + 1)){
                    pq.push({dist + 1, child});
                    distance[child] = dist + 1;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }
        
        return distance;
    }
};