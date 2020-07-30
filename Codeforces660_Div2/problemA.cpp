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
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
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
    ll n;
    cin >> n;
    vector<int> ans = {
        6,
        10,
        14, 15,
        21, 33};
    ll a = -1, b = -1, c = -1, d = -1;
    int flag = 0;
    for (int i = 0; i <= ans.size() - 3; i++)
    {
        for (int j = i + 1; j <= ans.size() - 2; j++)
        {
            for (int k = j + 1; k <= ans.size() - 1; k++)
            {
                d = n - ans[i] - ans[j] - ans[k];
                // cout << d << endl;
                if (d > 0 && d != ans[i] && d != ans[j] && d != ans[k])
                {
                    a = ans[i], b = ans[j], c = ans[k];
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            break;
    }

    if (flag == 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        cout << a << " " << b << " " << c << " " << d << endl;
    }
}

int main()
{
    fastIO;
    // take_fileIO();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}