// Link: https://leetcode.com/problems/subsets-ii/
class Solution {
    public:
        vector<vector<int>> res;
        set<vector<int>> hash;
        void sol(vector<int>& nums, int i, vector<int> temp){
            if(i == nums.size()){
                sort(temp.begin(), temp.end());
                if(!hash.contains(temp)){
                    hash.insert(temp);
                    res.push_back(temp);
                }
    
                return;
            }
    
            sol(nums, i + 1, temp);
            
            temp.push_back(nums[i]);
            sol(nums, i + 1, temp);
            temp.pop_back();
    
        }
    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<int> temp;
            sol(nums, 0, temp);
            return res;
        }
    };