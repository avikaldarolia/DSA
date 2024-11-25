// Link: https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> f(26, 0);

        int l = 0, r = 0, mx = 0, ans = 0;

        while(r < s.length()){
            // update frequency
            f[s[r] - 'A']++;

            // now get the maxFrequency in current window;
            int mx = *max_element(f.begin(), f.end());

            if((r - l + 1) - mx <= k){
                ans = max(ans, r - l + 1);
            }
            else{
                f[s[l] - 'A']--;
                l++;
            }

            r++;
        }

        return ans;
    }
};