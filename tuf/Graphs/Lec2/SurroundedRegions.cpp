// Link: https://leetcode.com/problems/surrounded-regions/description

class Solution {
public:

    void dfs(vector<vector<char>>& board, int r, int c, int m, int n,vector<vector<bool>> &visited){
        visited[r][c] = true;

        auto isInside = [&](int r, int c){
            return r >= 0 && r < m - 1 && c >= 0 && c < n - 1;
        };

        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for(auto dir: directions){
            int newr = r + dir.first;
            int newc = c + dir.second;
            if(isInside(newr, newc) && !visited[newr][newc] && board[newr][newc] == 'O'){
                dfs(board, newr, newc, m, n, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        const int m = board.size();
        const int n = board[0].size();
        auto isAtBorder = [&](int r, int c){
            return r == 0 || r == m - 1 || c == 0 || c == n - 1;
        };

        vector<vector<bool>> visited(m,vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && board[i][j] == 'O' && isAtBorder(i,j)){
                    dfs(board, i, j, m, n, visited);
                }
            }
        }

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

    }
};