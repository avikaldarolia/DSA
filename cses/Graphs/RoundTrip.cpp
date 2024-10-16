#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;
int sv, ev;

bool dfs(vector<int>adj[], int p, int cur, vector<bool>&vis, vector<int> &parent){
    parent[cur] = p;
    vis[cur] = true;

    for(auto &it: adj[cur]){
        if(it == p){
            continue;
        }

        if(vis[it]){
            sv = it;
            ev = cur;
            return true;
        }

        if(!vis[it]){
           if(dfs(adj, cur, it, vis, parent)){
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[]){   
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int>adj[n + 1];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    bool ok = false;
    
    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        if(!vis[i] && dfs(adj, -1, i, vis, parent)){
            ok = true;
            vector<int> ans;
            ans.push_back(ev);
            int itr = ev;
            while(itr != sv){
                ans.push_back(parent[itr]);
                itr = parent[itr];
            }
            ans.push_back(ev);

            cout << ans.size() << endl;
            for(auto &x: ans){
                cout << x << " ";
            }
            break;
        }
    }
    
    if(!ok){
        cout << "IMPOSSIBLE";
    }

    return 0;
}
