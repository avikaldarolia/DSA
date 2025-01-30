// Link: https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(m == 1 && n == 1){
            return grid[0][0] == 1 ? -1 : 0;
        }

        vector<pair<int,int>> dir {{0,1}, {1,0}, {-1,0}, {0,-1}};
        queue<pair<int,int>> q;
        
        int fresh = 0, rotten = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    rotten++;
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }

        if(fresh == 0){
            return 0;
        }

        int time = 0;
        while(!q.empty()){
            int cnt = q.size();
            while(cnt--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(auto &d: dir){
                    int nx = x + d.first;
                    int ny = y + d.second;
                    if(nx >= 0 && nx < n && ny >= 0 & ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = -1;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }

            time++;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return --time;
    }   
};