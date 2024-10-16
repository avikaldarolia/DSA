#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;

int main(int argc, char const *argv[]){   
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    ll sum = 0;
    for(ll i = 0; i < n - 1; i++){
        ll x;
        cin >> x;
        sum += x;
    }

    cout << n * (n + 1)/2 - sum;
    
    return 0;
}
