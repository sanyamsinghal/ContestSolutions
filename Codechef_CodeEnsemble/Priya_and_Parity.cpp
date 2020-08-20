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
const int N = 2 * 100000 + 9;

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

/* ---------------------Code--------------------  */
vector<vector<ll>> graph;
vector<bool> vis;
vector<ll> arr;

void dfs(ll node, ll &ans, ll parity)
{
    vis[node] = true;
    ans++;
    for (ll child : graph[node])
    {
        if (!vis[child] && popcount(arr[child]) % 2 == parity)
        {
            dfs(child, ans, parity);
        }
    }
}

void solve()
{

    ll n, m;
    cin >> n >> m;
    vis.clear();
    arr.clear();
    graph.clear();
    vis.resize(n + 1, false);
    arr.resize(n + 1);
    graph.resize(n + 1);

    loop(i, 1, n) cin >> arr[i];

    loop(i, 1, m)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll evenpop = 0, oddpop = 0;
    loop(i, 1, n)
    {
        if (!vis[i])
        {
            ll ans = 0;
            if (popcount(arr[i]) % 2 == 1)
            {
                dfs(i, ans, 1);
                oddpop = max(oddpop, ans);
            }
            else
            {
                dfs(i, ans, 0);
                evenpop = max(evenpop, ans);
            }
            // cout << endl;
        }
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll type, k;
        cin >> type >> k;

        ll kpp = popcount(k);
        if (type == 1)
        {
            if (kpp % 2 == 1)
            {
                cout << evenpop << endl;
            }
            else
            {
                cout << oddpop << endl;
            }
        }
        else
        {
            if (kpp % 2 == 1)
            {
                cout << oddpop << endl;
            }
            else
            {
                cout << evenpop << endl;
            }
        }
    }
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