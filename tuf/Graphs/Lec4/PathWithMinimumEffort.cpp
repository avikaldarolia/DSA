// Link: https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:

    typedef pair<int, pair<int,int>> P;

    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<pair<int,int>> dir{{1,0}, {-1,0}, {0,-1}, {0,1}};
        const int n = heights.size();
        const int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        auto isSafe = [&](int nx, int ny){
            return 0 <= nx && nx < n && 0 <= ny && ny < m;
        };

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0,0}});
        dist[0][0] = 0;
        
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int dif = pq.top().first;
            pq.pop();

            for(auto &d: dir){
                int nx = x + d.first;
                int ny = y + d.second;
                if(isSafe(nx, ny)){
                    int maxDif = max(dif, abs(heights[x][y] - heights[nx][ny]));
                    if(dist[nx][ny] > maxDif){
                        dist[nx][ny] = maxDif;
                        pq.push({dist[nx][ny], {nx, ny}}); 
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};