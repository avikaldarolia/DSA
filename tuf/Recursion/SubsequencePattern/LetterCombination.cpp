// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
    public:
    
        vector<string> sol(string digits, int idx, unordered_map<int, vector<string>> m){
            if(idx >= digits.length()){
                return {};
            }
    
            if(idx == digits.length() - 1){
                return m[digits[idx] - '0'];
            }
    
            vector<string> faith = sol(digits, idx + 1, m);
            vector<string> exp;
    
            for(auto val: m[digits[idx] - '0']){
                for(auto it: faith){
                    exp.push_back(val + it);
                }
            }
    
            return exp;
        }
    
        vector<string> letterCombinations(string digits) {
            unordered_map<int, vector<string>> m;
            m[2] = {"a", "b", "c"};
            m[3] = {"d", "e", "f"};
            m[4] = {"g", "h", "i"};
            m[5] = {"j", "k", "l"};
            m[6] = {"m", "n", "o"};
            m[7] = {"p", "q", "r", "s"};
            m[8] = {"t", "u", "v"};
            m[9] = {"w", "x", "y", "z"};
            int idx = 0;
            return sol(digits, idx, m);
        }
    };