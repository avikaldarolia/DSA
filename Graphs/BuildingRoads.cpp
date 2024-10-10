#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;

vector<int> parent;
vector<int> rr;

int findParent(int x){
    if(x == parent[x]){
        return x;
    }

    return parent[x] = findParent(parent[x]);
}

void Union(int x, int y){
    int px = findParent(x);
    int py = findParent(y);
    if(px == py){
        return;
    }

    if(rr[px] > rr[py]){
        parent[py] = px;
    }
    else if(rr[px] < rr[py]){
        parent[px] = py;
    }
    else{
        parent[py] = px;
        rr[px]++;
    }
}


void solveDSU(int n, int m){
    parent.resize(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    rr.resize(n + 1, 0);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(findParent(i) == i) {
            ans.push_back(i);
        }
    }

    int size = (int)ans.size();

    cout << size - 1 << endl;

    for(int i = 1; i < size; i++){
        cout << ans[i - 1] << " " << ans[i] << endl;
    }
}


void dfs(int start, vector<int> adj[], vector<bool>&vis){
    vis[start] = true;
    for(auto it: adj[start]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}


void solveDFS(int n, int m){
    vector<int> adj[n + 1];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    vector<pair<int,int>> ans;
    int p = -1;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            if(p != -1){
                ans.push_back({i + 1, p});
                p = i + 1;
            }
            else{
                p = i + 1;
            }

            dfs(i, adj, vis);
        }
    }

    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

int main(int argc, char const *argv[])
{   
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    // solveDSU(n, m);
    // solveDFS(n, m);

    return 0;
}
