// Link: https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>> &visited){
        visited[r][c] = true;
        vector<pair<int,int>> dir { {1,0}, {0,1}, {-1,0}, {0,-1}};

        auto isInside = [&](int r, int c){
            return r >= 0 && r <= grid.size() -1  && c >= 0 && c <= grid[0].size() - 1;
        };

        for(auto neigh: dir){
            int nr = r + neigh.first;   
            int nc = c + neigh.second;   
            if(isInside(nr, nc) && !visited[nr][nc] && grid[nr][nc] == 1){
                dfs(grid, nr, nc, visited);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        const int n = (int)grid.size();
        const int m = (int)grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        auto isAtBorder = [&](int r, int c){
            return r == 0 || r == n - 1  || c == 0 || c == m - 1;
        };

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && isAtBorder(i,j) && !visited[i][j]){
                    dfs(grid, i, j, visited);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};