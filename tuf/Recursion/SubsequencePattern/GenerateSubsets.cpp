// Link: https://leetcode.com/problems/subsets/description/

class Solution {
    public:
        vector<vector<int>> res;
        void sol(vector<int>& nums, int i, vector<int> temp){
            if(i == nums.size()){
                res.push_back(temp);
                return;
            }
    
            sol(nums, i + 1, temp);
    
            temp.push_back(nums[i]);
            sol(nums, i + 1, temp);
            temp.pop_back();
        }
        
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> temp;
            sol(nums, 0, temp);
            return res;
        }
};

// OR

/**
 * void backtrack(int first, vector<int> curr, vector<int>& nums) {
        // Add the current combination to the output
        output.push_back(curr);
        
        // Explore further combinations
        for (int i = first; i < n; ++i) {
            // Add the next element to the current combination
            curr.push_back(nums[i]);
            // Recurse to form the next combination
            backtrack(i + 1, curr, nums);
            // Backtrack and remove the last element
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        backtrack(0, curr, nums); // Call once to generate all subsets
        return output;
    }
 */