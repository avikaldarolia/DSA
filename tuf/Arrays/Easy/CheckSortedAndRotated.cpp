// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

class Solution {
public:
    bool check(vector<int>& nums) {
        bool once = false; int indx = -1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                if(once) return false;
                once = true;
            }
        }
        if(once && nums[0] < nums[nums.size() - 1]) return false;
        return true;
    }
};