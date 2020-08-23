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

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

class Solution
{
public:
    vector<int> graph[100005];
    int ind[100005] = {0};
    bool vis[100005];
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        memset(ind, 0, sizeof(ind));
        memset(vis, false, sizeof(vis));

        for (int i = 0; i <= n; i++)
            graph[i].clear();

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            ind[v]++;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (ind[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
