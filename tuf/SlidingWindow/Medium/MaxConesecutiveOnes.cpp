// Link: https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, ans = 0, zero = 0;

        while(r < nums.size()){
            if(nums[r] == 0){
                zero++;
            }

            // Shrink not more than the max ans.
            if(zero > k){
                if(nums[l] == 0){
                    zero--;
                }
                l++;
            }
            
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};