// Link: https://leetcode.com/problems/powx-n/
class Solution {
    public:
        unordered_map<double, double> dp;
        double myPow(double x, int n) {
            if(n == 0){
                return 1;
            }
            if(n == 1){
                return x;
            }
    
            if(dp.find(n) != dp.end()){
                return dp[n];
            }
    
            long long N = n;
    
            if(n < 1){
                x = 1 / x;
                N = abs(N);
            }
    
    
            return dp[N] = myPow(x, N / 2) * myPow(x, N - (N / 2));
        }
};