// Link: https://leetcode.com/problems/string-to-integer-atoi/

class Solution
{
public:
    int myAtoi(string s)
    {
        int itr = 0;
        while (itr < s.length() && s[itr] == ' ')
        {
            itr++;
        }

        int sign = 1;
        if (s[itr] == '+' || s[itr] == '-')
        {
            sign = s[itr] == '+' ? 1 : -1;
            itr++;
        }

        while (itr < s.length() && s[itr] == '0')
        {
            itr++;
        }

        int p = 10;
        long long int ans = 0;
        while (itr < s.length() && isdigit(s[itr]))
        {
            ans = ans * p + (s[itr] - '0');
            if (ans * sign >= INT_MAX || ans * sign <= INT_MIN)
            {
                ans = sign == -1 ? INT_MIN : INT_MAX;
                break;
            }

            itr++;
        }

        return ans * sign;
    }
};
