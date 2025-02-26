// Link: https://leetcode.com/problems/generate-parentheses/

class Solution {
    public:
        vector<string> res;
        void sol(string s, int open, int close, int n){
            if(open > n || close > open){
                return;
            }
    
            if(open == n && close == n){
                res.push_back(s);
                return;
            }
    
            if(close < n){
                s += ')';
                sol(s, open, close + 1, n);
                s.pop_back();
            }
    
            s += '(';
            sol(s, open + 1, close, n);
            s.pop_back();
        }
        
        vector<string> generateParenthesis(int n) {
            sol("", 0, 0, n);
            return res;
        }
};