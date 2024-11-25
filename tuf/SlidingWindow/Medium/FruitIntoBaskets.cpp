//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        // max 2 different values
        int l = 0, i = 0;
        int n = arr.size();
        unordered_map<int,int> taken; 
        
        int ans = 0;
        
        while(i < n){
            int val = arr[i];
            taken[val]++;
            
            if(taken.size() > 2){
            
                taken[arr[l]]--;
                if(taken[arr[l]] == 0){
                    taken.erase(arr[l]);
                }
                l++;
            }
            
            if(taken.size() <= 2){
                ans = max(ans, i - l + 1);    
            }
            
            i++;
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends