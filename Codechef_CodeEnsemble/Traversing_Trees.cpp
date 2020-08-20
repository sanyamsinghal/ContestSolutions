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
ll dp[300001];
ll parent[300001];
bool vis[300001];

ll dfs(vector<vector<ll>> &graph, ll node, ll par, ll pos)
{
    if (pos % 2 == 1)
    {
        ll retval = 0;
        for (ll child : graph[node])
        {
            if (par == child)
                continue;

            if (!vis[child])
            {
                retval += dfs(graph, child, node, pos + 1);
            }
            else
            {
                retval += dp[child];
                dp[child] = 0;
            }
        }
        return retval;
    }
    else
    {
        vis[node] = true;
        for (ll child : graph[node])
        {
            if (par == child)
                continue;
            dp[node] += dfs(graph, child, node, pos + 1);
        }
        ll temp = dp[node];
        if (pos > 0)
            dp[node] = 0;
        return temp;
    }
}

void dfs_parent(vector<vector<ll>> &graph, ll node, ll par)
{
    vis[node] = true;
    parent[node] = par;
    for (ll child : graph[node])
    {
        if (par == child)
            continue;
        if (!vis[child])
        {
            dfs_parent(graph, child, node);
        }
    }
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    memset(parent, -1, sizeof(parent));
    memset(vis, false, sizeof(vis));
    ll n, m, q;
    cin >> n >> q;

    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    m = n - 1;
    vector<vector<ll>> graph(n + 1);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs_parent(graph, 1, parent[1]);

    // for (int i = 1; i <= n; i++)
    //     cout << parent[i] << " ";
    // cout << endl;

    memset(vis, false, sizeof(vis));

    for (ll i = 1; i <= q; i++)
    {
        ll qnode;
        cin >> qnode;
        // for (int i = 1; i <= n; i++)
        //     cout << dp[i] << " ";
        // cout << endl;
        if (!vis[qnode])
            dfs(graph, qnode, parent[qnode], 0);
    }

    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    cout << endl;
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