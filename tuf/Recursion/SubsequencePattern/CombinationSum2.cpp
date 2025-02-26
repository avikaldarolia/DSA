// Link: https://leetcode.com/problems/combination-sum-ii/

class Solution {
    public:
        set<vector<int>> hash;
        void sol(vector<int>& candidates, int target, vector<int> temp, int idx, vector<vector<int>> &ans){
            if(target == 0){
                if(!hash.count(temp)){
                    hash.insert(temp);
                    ans.push_back(temp);
                }
                return;
            }
    
            if(idx >= candidates.size()){
                return;
            }
    
            int last = -1; // Remove duplicate comparisions.
            for(int i = idx; i < candidates.size(); i++){
                if(target - candidates[i] < 0){
                    break;
                }
    
                if(candidates[i] == last){
                    continue;
                }
    
                temp.push_back(candidates[i]);
                sol(candidates, target - candidates[i], temp, i + 1, ans);
                temp.pop_back();
    
                last = candidates[i];
            }
        }
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> temp;
            sort(candidates.begin(), candidates.end());
            sol(candidates, target, temp, 0, ans);
            return ans;
        }
    };