/*
  User:- sanyam
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ip(x)                                                                  \
  ll x;                                                                        \
  cin >> x;
#define op(x) cout << x;
#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t)                                                                   \
  int t;                                                                       \
  cin >> t while (t--)
#define triplet pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)
#define init_arr(i, val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()
#define debug1(x) cout << #x << " " << x << endl;
#define debug2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z     \
       << endl;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>

    PBDS;

const ll inf = 1e18;
const int N = 100001;

void take_fileIO() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  return;
}

void printvector(vector<ll> &v) {
  for (ll i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

/* ---------------------Code--------------------
  I was not able to solve this question during the contest, solved if  after
  that
*/

bool dfs(ll node, unordered_map<ll, vector<ll>> &graph, vector<bool> &vis,
         vector<bool> &instack, vector<ll> &ts) {
  vis[node] = true;
  instack[node] = true;

  for (ll child : graph[node]) {
    if (!vis[child]) {
      if (dfs(child, graph, vis, instack, ts))
        return true;
    } else if (instack[child]) {
      return true;
    }
  }

  ts.push_back(node);
  instack[node] = false;
  return false;
}

void solve() {
  vector<ll> ts;

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> edges(m, vector<ll>(3));
  unordered_map<ll, vector<ll>> graph;
  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    if (edges[i][0] == 1) {
      graph[edges[i][1]].push_back(edges[i][2]);
    }
    // cout << edges[i][0] << " " << edges[i][1] << " " << edges[i][2] << endl;
  }

  // debug1(1);

  vector<bool> vis(n + 1, false), instack(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (vis[i] == false) {
      if (dfs(i, graph, vis, instack, ts)) {
        cout << "NO\n";
        return;
      }
    }
  }
  // cout<<
  // reverse(sort_cut(ts));
  // debug1(3);
  vector<ll> prior(n + 1, INT_MAX);
  for (int i = 0; i < ts.size(); i++) {
    prior[ts[i]] = i;
  }

  // printvector(ts);
  // cout << endl;

  cout << "YES\n";
  for (int i = 0; i < edges.size(); i++) {
    if (edges[i][0] == 1)
      cout << edges[i][1] << " " << edges[i][2];
    else if (prior[edges[i][1]] > prior[edges[i][2]])
      cout << edges[i][1] << " " << edges[i][2];
    else
      cout << edges[i][2] << " " << edges[i][1];
    cout << endl;
  }
}

int main() {

  fastIO;
  // take_fileIO();
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}