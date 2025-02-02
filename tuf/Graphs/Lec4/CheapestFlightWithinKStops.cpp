// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        
        for(auto &f: flights){
            int u =f[0];
            int v = f[1];
            int wt = f[2];
            adj[u].push_back({v, wt});
        }


        queue<pair<int,int>> q;
        q.push({src, 0});
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        int steps = 0;

        while(!q.empty() && steps <= k){
            int N = q.size();

            while(N--){
                int u = q.front().first;
                int dist = q.front().second;
                q.pop();

                for(auto child:  adj[u]){
                    int v = child.first;
                    int wt = child.second;
                    if(distance[v] > dist + wt){
                        distance[v] = dist + wt;
                        q.push({v, dist + wt});
                    }
                }
            }

            steps++;
        }

        if(distance[dst] == INT_MAX){
            return -1;
        }

        return distance[dst];
    }
};