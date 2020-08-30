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
/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
*/
const ll inf = 1e18;
const int N = 100001;

void printVector(vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

class Solution {
   public:
    ll dp[1005][1005];

    ll ncr(ll n, ll r) {
        if (n == r || r == 0) return 1;
        if (r > n - r) r = n - r;

        if (dp[n][r] != -1) return dp[n][r];

        ll ans = (ncr(n - 1, r - 1) % mod + ncr(n - 1, r) % mod) % mod;
        return dp[n][r] = ans;
    }

    ll solve(vector<int>& nums) {
        if (nums.size() <= 1) return 1;

        vector<int> left, right;
        for (int id = 1; id < nums.size(); id++) {
            if (nums[id] > nums[0]) {
                right.push_back(nums[id]);
            } else if (nums[id] < nums[0])
                left.push_back(nums[id]);
        }
        ll m = left.size();
        int n = right.size();

        ll ans = (solve(left) % mod * solve(right) % mod) % mod *
                 ncr(m + n, n) % mod;
        return ans % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        memset(dp, -1, sizeof(dp));
        ll ans = solve(nums);
        if (ans == 1)
            return 0;
        else
            ans--;
        return ans;
    }
};