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
const ll inf = 1e18;
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
    string s;
    cin >> s;
    ll n = s.size();

    vector<ll> cons_ones;
    // cout << s << endl;
    for (int i = 0; i < n;)
    {
        int j;
        for (j = i; j < n && s[i] == s[j]; j++)
        {
        }
        // cout << i << " " << j << endl;
        if (s[i] == '1')
            cons_ones.push_back(j - i);
        i = j;
    }

    ll ans = 0;
    sort(sort_cut(cons_ones), greater<ll>());

    for (int i = 0; i < cons_ones.size(); i += 2)
        ans += cons_ones[i];

    cout << ans << endl;
}

int main()
{
    fastIO;

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}