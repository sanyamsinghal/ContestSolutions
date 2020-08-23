/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;
#define ip(x) \
    ll x;     \
    cin >> x;
#define op(x) cout << x;
#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t) \
    int t;   \
    cin >> t while (t--)
#define triplet pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define loop(i, k, n) for (ll i = k; i <= n; i++)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)
#define init_arr(i, val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()
#define popcount __builtin_popcountll
const ll inf = 1e18;
const int N = 100001;

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

class Solution
{
public:
    int dp[501][501];
    int pre[501];

    int solve(vector<int> &arr, int low, int high)
    {
        if (low >= high)
        {
            return 0;
        }
        if (dp[low][high] != -1)
            return dp[low][high];

        int ans = INT_MIN;
        int left = 0;
        int sum = pre[high] - (low > 0 ? pre[low - 1] : 0);

        for (int k = low; k < high; k++)
        {
            left += arr[k];
            int right = sum - left;

            if (left > right)
            {
                int op1 = right + solve(arr, k + 1, high);
                ans = max(ans, op1);
            }
            else if (left < right)
            {
                int op2 = left + solve(arr, low, k);
                ans = max(ans, op2);
            }
            else
            {
                int op1 = right + solve(arr, k + 1, high);
                int op2 = left + solve(arr, low, k);
                ans = max(ans, max(op2, op1));
            }
        }
        return dp[low][high] = ans;
    }

    int stoneGameV(vector<int> &stoneValue)
    {
        memset(dp, -1, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        int n = stoneValue.size();

        for (int i = 0; i < n; i++)
        {
            pre[i] = stoneValue[i] + (i > 0 ? pre[i - 1] : 0);
        }

        int ans = solve(stoneValue, 0, n - 1);
        return ans;
    }
};