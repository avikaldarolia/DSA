// Link: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    // bool dfs(vector<vector<int>>& graph, vector<int> &color, int i, int curColor){
    //     color[i] = curColor;

    //     for(auto &v: graph[i]){
    //         if(color[v] == curColor){
    //             return false;
    //         }

    //         if(color[v] == -1){
    //             int newColor = 1 - curColor;
    //             if(dfs(graph, color, v, newColor) == false){
    //                 return false;
    //             }
    //         }
    //     }

    //     return true;
    // }

    // bool bfs(vector<vector<int>>& graph, vector<int> &color, int i, int curColor){
    //     queue<int> q;
    //     q.push(i);
    //     color[i] = curColor;

    //     while(!q.empty()){
    //         int u = q.front();
    //         q.pop();
    //         for(auto &v: graph[u]){
    //             if(color[v] == color[u]){
    //                 return false;
    //             }
    //             if(color[v] == -1){
    //                 q.push(v);
    //                 color[v] = 1 - color[u];
    //             }
    //         }

    //     }

    //     return true;
    // }

    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py){
            return;
        }

        if(rank[px] > rank[py]){
            parent[py] = px;
        }
        else if(rank[px] < rank[py]){
            parent[px] = py;
        }
        else{
            parent[py] = px;
            rank[px]++;
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(int u = 0; u < n; u++){
            for(int &v: graph[u]){
                if(u < v){
                    int parent_u = find(u);
                    int parent_v = find(v);
                    if(parent_u == parent_v){
                        return false;
                    }

                    Union(u,v);
                }
            }
        }

        return true;
    }
};