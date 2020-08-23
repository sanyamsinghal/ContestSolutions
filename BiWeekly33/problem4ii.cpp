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
    int component[1000][1000];
    int cid = 1;
    int comp_size[1000] = {0};
    bool vis[1000][1000];
    bool instack[1000][1000];

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool dfs(vector<vector<char>> &grid, int i, int j, char gv, int val)
    {
        component[i][j] = val;
        vis[i][j] = true;
        instack[i][j] = true;
        // cout << i << " " << j << " ";
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == gv)
            {
                if (!vis[ni][nj])
                {
                    if (dfs(grid, ni, nj, gv, val + 1))
                        return true;
                }
                else if (instack[ni][nj])
                {
                    int diff = val - component[ni][nj] + 1;
                    if (diff >= 4)
                    {
                        // cout << ni << " " << nj << endl;
                        return true;
                    }
                }
            }
        }
        return instack[i][j] = false;
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        memset(component, 0, sizeof(component));
        memset(vis, false, sizeof(vis));
        memset(instack, false, sizeof(instack));
        int n = grid.size();
        if (n == 0)
            return false;
        int m = grid[0].size();
        if (m == 0)
            return false;

        if (n == 1 || m == 1)
            return false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                {
                    if (dfs(grid, i, j, grid[i][j], 1))
                    {
                        // cout << i << " " << j << endl;
                        return true;
                    }
                    // cout << endl;
                    // cid++;
                }
            }
        }
        return false;
    }
};

// [["b","a","c"],["c","a","c"],["d","d","c"],["b","c","c"]]
// b a c
//     c a c
//         d d c
//             b c c