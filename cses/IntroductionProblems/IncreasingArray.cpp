#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(int argc, char const *argv[])
{   
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a){
        cin >> x;
    }

    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i - 1]){
            ans += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    
    cout << ans;
    return 0;
}
