// Link: https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        const int n = graph.size();
        vector<int> in(n, 0);
        vector<vector<int>> rev(n);
        for(int i = 0; i < n; i++){
            in[i] += graph[i].size();
            for(auto &v: graph[i]){
                rev[v].push_back(i);
            }
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();

            ans.push_back(top);

            for(auto &v: rev[top]){
                in[v]--;
                if(in[v] == 0){
                    q.push(v);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};