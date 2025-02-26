// Link: https://leetcode.com/problems/combination-sum-iii/

class Solution {
    public:
        vector<vector<int>> ans;
        void sol(int k, int n, int cur, vector<int> temp){
            if(k == 0){
                if(n == 0){
                    ans.push_back(temp);
                }
                return;
            }
    
            for(int i = cur; i <= 9; i++){
                if(n - i >= 0){
                    temp.push_back(i);
                    sol(k - 1, n - i, i + 1, temp);
                    temp.pop_back();
                }
            }
        }
    
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<int> temp;
            sol(k, n, 1, temp);
    
            return ans;
        }
    };