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
ll dp[100005];
void dfs(vector<pll> graph[], map<ll, ll> &edc, ll node, ll par)
{
    int childs = 0;
    for (pll child : graph[node])
    {
        if (child.first != par)
        {
            dfs(graph, edc, child.first, node);
            dp[node] += dp[child.first];
            childs++;
        }
    }
    if (childs == 0)
        dp[node] = 1;
}

void dfs2(vector<pll> graph[], map<ll, ll> &edc, ll node, ll par)
{
    for (pll child : graph[node])
    {
        if (child.first != par)
        {
            edc[child.second] += dp[child.first];
            dfs2(graph, edc, child.first, node);
        }
    }
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    ll n, s;
    cin >> n >> s;
    vector<pll> graph[n + 1];
    vector<ll> edges;
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(wt);
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    map<ll, ll> edc;
    dfs(graph, edc, 1, 0);

    // for (int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << endl;

    dfs2(graph, edc, 1, 0);

    // for (auto it : edc)
    // {
    //     cout << it.first << " " << it.second << ",\n";
    // }

    ll ans = 0;
    priority_queue<vll> pq;
    ll sum = 0;
    for (ll i = 0; i < edges.size(); i++)
    {
        ll val = edc[i] * edges[i];
        sum += val;
        pq.push({val - (edc[i] * (edges[i] / 2LL)), i});
    }

    // cout << "total sum is :- " << sum << endl;
    while (sum > s)
    {
        vll curr = pq.top();
        pq.pop();
        // cout << sum << " " << curr[2] << endl;

        sum -= curr[0];
        ll id = curr[1];
        edges[id] /= 2LL;
        pq.push({edc[id] * edges[id] - (edc[id] * (edges[id] / 2)), id});
        ans++;
    }
    // cout << sum << endl;
    cout << ans << endl;
}

int main()
{
    fastIO;
    take_fileIO();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
//     a **************************************************************************************