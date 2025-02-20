// Link: https://leetcode.com/problems/count-good-numbers/description/

class Solution {
    public:
        int MOD = 1e9 + 7;
        long long power(long long x, long long p){
            if(p == 0){
                return 1;
            }
    
            if(p % 2 == 0){
                return power((x * x) % MOD, p / 2);
            }
            return (power(x , p - 1) % MOD * x) % MOD;
        }
    
        int countGoodNumbers(long long n) {
            long long count_4 = n / 2;
            long long count_5 = n - count_4;
    
            long long ans = ((power(4LL, count_4) % MOD * power(5LL, count_5) % MOD) % MOD);
            return ans;
        }
};