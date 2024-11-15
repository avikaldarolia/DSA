#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;

int main(int argc, char const *argv[])
{   
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if(n == 2 || n == 3){
        cout << "NO SOLUTION";
    }
    else{
        for(int i = 2; i <= n; i += 2){
            cout << i << " ";
        }
        
        for(int i = 1; i <= n; i += 2){
            cout << i << " ";
        }

    }
    
    return 0;
}
