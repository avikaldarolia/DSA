// Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    string findOrder(vector<string> dict, int k) {
        // code here
        int N = dict.size();
        string ans = "";
        vector<int> adj[k];
        vector<int> in(k, 0);
        for(int j = 0; j < N - 1; j++){
            string small = dict[j];
            string big = dict[j + 1];
            
            for(int i = 0; i < min(small.length(), big.length()); i++){
                if(small[i] == big[i]){
                    continue;
                }
                else{
                    adj[small[i] - 'a'].push_back(big[i] - 'a');
                    break;
                }
            }
        }
        
        for(int i = 0; i < k; i++){
            for(auto j: adj[i]){
                in[j]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < k ; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            char cur = q.front();
            q.pop();
            
            ans += (char)(cur + 'a');
            
            for(auto ch: adj[cur]){
                in[ch]--;
                if(in[ch] == 0){
                    q.push(ch);
                }
            }
        }
        
        return ans.length() < k ? "" : ans;
        
    }
};


string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }
        int K;
        cin >> K;
        getchar();
        Solution obj;
        string ans = obj.findOrder(a, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[a.size()];
        std::copy(a.begin(), a.end(), temp);
        sort(temp, temp + a.size(), f);

        bool f = true;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != temp[i])
                f = false;

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
