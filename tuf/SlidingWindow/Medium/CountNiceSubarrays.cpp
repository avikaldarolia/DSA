// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        long long codd = 0;
        m[0] = 1;
        int ans = 0;

        for(int i = 0; i < nums.size();i ++){
            if(nums[i] % 2 != 0){
                codd++;
            }

            int remove = codd - k;

            ans += m[remove];

            m[codd]++;
        }

        return ans;
    }
};