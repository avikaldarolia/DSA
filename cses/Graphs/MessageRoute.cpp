#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;

void bfs(vector<int> adj[], int start, int dest){
    queue<int> q;   
    q.push(start);
    
    int n = dest + 1;
    int level = 1;
    vector<int> dist(n, INT_MAX);
    dist[start] = level;

    vector<int> pp(n, -1);
    pp[start] = start;

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int node = q.front();
            q.pop();

            if(node == dest){
                cout << level << endl;
                int parent = dest;
                vector<int> result;
                while(parent != start){
                    result.push_back(parent);
                    parent = pp[parent];
                }

                result.push_back(start);
                
                for(int i = result.size() - 1; i >= 0; i--){
                    cout << result[i] + 1 << " ";
                }

                return;
            }

            for(auto &it: adj[node]){
                if(dist[it] > level + 1){
                    dist[it] = level + 1;
                    pp[it] = node;
                    q.push(it);
                }
            }
        }

        level++;
    }


    cout << "IMPOSSIBLE";
    return;
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


    bfs(adj, 0, n - 1);
    
    return 0;
}
