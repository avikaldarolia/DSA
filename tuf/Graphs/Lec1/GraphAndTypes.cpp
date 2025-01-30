// Link: https://www.geeksforgeeks.org/problems/graph-and-vertices/1
#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;

long long count(int n){
    if(n <= 2){
        return n;
    }

    return pow(2, (n * (n - 1)) / 2);
}

int main(int argc, char const *argv[]){   
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    cout << count(n);
    return 0;
}
