// Link: https://www.geeksforgeeks.org/problems/number-of-provinces/1

class Solution {
public:
    void dfs(int src, vector<vector<int>>& isConnected, vector<bool> &vis){
        vector<int> row = isConnected[src];
        for(int i = 0; i < row.size(); i++){
            if(i != src && row[i] == 1 && !vis[i]){
                vis[i] = true;
                dfs(i, isConnected, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        const int n = isConnected.size();
        vector<bool>vis(n, false);

        for(int i = 0; i < n; i++){
            if(vis[i]){
                continue;
            }

            vis[i] = true;
            ans++;
            dfs(i, isConnected, vis);
        }
        
        return ans;
    }
};