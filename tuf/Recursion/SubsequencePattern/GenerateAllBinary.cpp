// Link: https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<string> ans;
    void sol(string s, int num){
        if(num == 0){
            ans.push_back(s);
            return;
        }
        
        char last = s.back();
        if(last == '1'){
            s += '0';
            sol(s, num - 1); 
            s.pop_back();
        }
        else{
            s += '0';
            sol(s, num - 1);   
            s.pop_back();
            s += '1';
            sol(s, num - 1);
            s.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        sol("0", num - 1);
        sol("1", num - 1);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends