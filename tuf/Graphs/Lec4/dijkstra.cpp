// Link: 

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue< pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                int newDistance = edgeWeight + distance;
                if(newDistance < dist[adjNode]){
                    dist[adjNode] = newDistance;
                    pq.push({newDistance, adjNode});
                }
            }
        }
        
        return dist;
    }
};