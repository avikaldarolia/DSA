// User function Template for C++
// Link : https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0

class Solution {
  public:
    int  largest(vector<int> &arr){
        int n=arr.size();
         int ans=arr[0];
         for(int i=1;i<n;i++){
             if(arr[i]>ans)
             ans=arr[i];
         }
         
        return ans; 
    }
};