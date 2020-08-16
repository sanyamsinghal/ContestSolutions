class Solution
{
public:
    unordered_map<int, int> dp;

    int solve(int n)
    {
        if (n <= 1)
            return n;
        if (dp.find(n) != dp.end())
            return dp[n];
        else
        {
            return dp[n] = 1 + min(n % 2 + solve(n / 2), n % 3 + solve(n / 3));
        }
    }

    int minDays(int n)
    {
        return solve(n);
    }
};