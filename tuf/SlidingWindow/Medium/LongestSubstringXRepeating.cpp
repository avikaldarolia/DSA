// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0 || s.length() == 1){
            return s.length();
        }

        int i = 0, start = 0;
        int ans = 0;
        map<char, int> m;
        while(i < s.length()){
            if(m.find(s[i])!= m.end()){
                start = max(start, m[s[i]] + 1);
            }
            m[s[i]] = i;
            
            ans = max(ans, i - start + 1);
            i++;
        }
        return ans;
    }
};