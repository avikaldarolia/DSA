// Link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<bool> dp(target + 1, false);
        dp[0] = true; 
        for(int i = 0; i < n; i++){
            int value = arr[i];
            for(int j = target; j >= 0; j--){
                if(dp[j] || (j - value >= 0 && dp[j - value])){
                    dp[j] = true;
                }
            }
       }
       
       return dp[target];
    
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends