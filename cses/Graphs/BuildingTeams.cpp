#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;

bool dfs(vector<int> adj[], int s, vector<int> &color, int current){
    color[s] = current;

    for(auto &x: adj[s]){
        if(color[x] == -1){
            if(!dfs(adj, x, color, 3 - current)){
                return false;
            }
        }
        else if(color[x] == color[s]){
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{   
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int>adj[n];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n, -1);

    bool flag = false;
    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            if(!dfs(adj, i, color, 2)){
                cout << "IMPOSSIBLE\n";
                flag = true;
                break;
            }
        }
    }
    
    if(!flag){
        for(auto &x: color){
            cout << x << " ";
        }
    }

    return 0;
}
