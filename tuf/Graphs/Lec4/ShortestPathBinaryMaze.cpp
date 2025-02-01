// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0 || grid[0][0] != 0){
            return -1;
        }
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq;
        pq.push({0, {0,0}});

        vector<pair<int,int>> directions {{1,0}, {-1,0}, {0,1}, {0,-1}, {-1, -1}, {1,1}, {-1, 1}, {1, -1}};

        auto isSafe = [&](int nx, int ny){
            return 0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[0].size();
        };

        vector<vector<int>>dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        dist[0][0] = 0;

        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();

            for(auto dir: directions){
                int nx = dir.first + x;
                int ny = dir.second + y;

                if(isSafe(nx, ny) && grid[nx][ny] == 0 && (d + 1 < dist[nx][ny])){
                    dist[nx][ny] = d + 1;
                    pq.push({d + 1, {nx, ny}});
                }
            }
        }

        if(dist[grid.size() - 1][grid[0].size() - 1] == INT_MAX){
            return -1;
        }

        return dist[grid.size() - 1][grid[0].size() - 1] + 1;
    }
};