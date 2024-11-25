// Link: https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> m;
        int cursum = 0, ans = 0;
        m[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            cursum += nums[i];
            int remove = cursum - goal;
            ans += m[remove];
            m[cursum]++;
        }
        return ans;
    }
};