// Link: https://leetcode.com/problems/flood-fill/
class Solution {
public:
    vector<pair<int,int>> dir{{1,0},{0,1},{0,-1},{-1,0}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<bool>>&vis){
        vis[sr][sr] = true;
        image[sr][sc] = color;

        auto isInside = [&](int r, int c){
            return r >= 0 && c >= 0 && r < image.size() && c < image[0].size();
        };

        for(auto d: dir){
            int nr = d.first + sr;
            int nc = d.second + sc;
            if(isInside(nr, nc) && !vis[nr][nc]){
                dfs(image, nr, nc, color, vis);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), false));
        vector<vector<int>> ans = image;
        dfs(image, sr, sc, color, vis);
        return image;
    }
};