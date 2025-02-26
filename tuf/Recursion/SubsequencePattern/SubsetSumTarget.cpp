// Link: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9+7;
    // int ans;
    int sol(vector<int>& arr, int i, int target, vector<vector<int>>& dp){
        if(i >= arr.size()){
            if(target == 0){
                return 1;
            }
            else return 0;
        }
        
        if(target < 0){
            return 0;
        }
        
        if(dp[i][target] != -1){
            return dp[i][target];
        }
       
        int include = 0;
        if(target - arr[i] >= 0){
            include += sol(arr, i + 1, target - arr[i], dp);
        }
        
        int exclude = sol(arr, i + 1, target, dp);
        
        return dp[i][target] = include + exclude;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return sol(arr, 0, target, dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends