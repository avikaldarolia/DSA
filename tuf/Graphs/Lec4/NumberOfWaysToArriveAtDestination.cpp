// Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 + 7;
        vector<vector<pair<long long,long long>>> adj(n);
        vector<long long> dist(n, 1e12);
        vector<long long> ways(n, 0);

        for(auto &r: roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            long long u = pq.top().second;
            long long distance = pq.top().first;
            pq.pop();

            for(auto node: adj[u]){
                long long v = node.first;
                long long wt = node.second;
                long long currentDistance = (wt + distance);
                if(currentDistance < dist[v]){
                    dist[v] = currentDistance;
                    pq.push({currentDistance, v});
                    ways[v] = ways[u] % mod;
                }
                else if(currentDistance == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};