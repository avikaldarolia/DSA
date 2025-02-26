// Link: https://leetcode.com/problems/combination-sum/

class Solution {
    public:
        void sol(vector<int>& candidates, int target,vector<int> temp, vector<vector<int>> &ans, int idx){
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            
            for(int i = idx; i < candidates.size(); i++){
                if(target - candidates[i] >= 0){
                    temp.push_back(candidates[i]);
                    sol(candidates, target - candidates[i], temp, ans, i);
                    temp.pop_back();
                }
            }
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> temp;
            int idx = 0;
            sol(candidates, target, temp, ans, idx);
            return ans;
        }
    };