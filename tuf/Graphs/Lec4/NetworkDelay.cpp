// Link: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &t: times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        queue<int> q;
        q.push(k);

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop();

                for(auto &ch: adj[u]){
                    int v = ch.first;
                    int wt = ch.second;
                    int time = wt + dist[u];
                    if(dist[v] > time){
                        dist[v] = time;
                        q.push(v);
                    }
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? - 1 : ans;
    }
};