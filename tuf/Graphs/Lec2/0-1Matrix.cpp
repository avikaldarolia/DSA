// Link: https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        vector<pair<int,int>> dir{ {0,1}, {1,0}, {-1,0}, {0,-1}};

        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        int distance = 0;

        while(!q.empty()){
            int cnt = q.size();
            while(cnt--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(auto d: dir){
                    int nr = d.first + r;
                    int nc = d.second + c;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] != 0){
                        mat[nr][nc] = 0;
                        q.push({nr, nc});
                        ans[nr][nc] = distance + 1;
                    }
                }
            }

            distance++;
        }


        return ans;
    }
};