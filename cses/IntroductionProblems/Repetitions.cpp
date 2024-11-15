#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){   
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int len = 1;
    int ans = 1;
    for(int i = 1; i < (int)s.length(); i++){
        if(s[i] == s[i - 1]){
            len++;
        }
        else{
            ans = max(ans, len);
            len = 1;
        }
    }

    ans = max(ans, len);
    cout << ans << endl;
    return 0;
}
