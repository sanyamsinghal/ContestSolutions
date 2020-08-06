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
/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
*/
const ll inf = 1e16;
const int N = 100001;
void take_fileIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return;
}

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

/* ---------------------Code--------------------  */

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> arr(n);
    loop(i, 0, n - 1) cin >> arr[i];

    ll dp[n + 1][2][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 0;
    dp[0][1][0] = arr[0];
    dp[0][1][1] = arr[0] * x;
    ll ans = max(0LL, max(arr[0], arr[0] * x));
    for (int i = 1; i < n; i++)
    {
        dp[i][0][0] = max(arr[i], max(dp[i - 1][0][0], dp[i - 1][1][1]) + arr[i]);
        dp[i][1][0] = max(arr[i], dp[i - 1][1][0] + arr[i]);
        dp[i][1][1] = max(arr[i] * x, max(dp[i - 1][1][0], dp[i - 1][1][1]) + arr[i] * x);
        ans = max(ans, max(dp[i][0][0], max(dp[i][1][0], dp[i][1][1])));
    }
    cout << ans << endl;
}

int main()
{
    fastIO;
    take_fileIO();

    solve();

    return 0;
}