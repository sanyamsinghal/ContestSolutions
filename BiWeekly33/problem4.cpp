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

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(vector<vector<char>> &grid, int i, int j, char gv)
    {
        vis[i][j] = true;
        component[i][j] = cid;
        comp_size[cid]++;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && !vis[ni][nj] && grid[ni][nj] == gv)
            {
                dfs(grid, ni, nj, gv);
            }
        }
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        memset(component, 0, sizeof(component));
        memset(vis, false, sizeof(vis));
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
                    dfs(grid, i, j, grid[i][j]);
                    cid++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << component[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int id = component[i][j];
                if (comp_size[id] < 4)
                    continue;

                int up = (i - 1 < 0 ? INT_MIN : component[i - 1][j]);
                int down = component[i + 1][j];
                int left = (j - 1 < 0 ? INT_MIN + 10 : component[i][j - 1]);
                int right = component[i][j + 1];

                int cnt = 0;
                for (int x : {up, left, down, right})
                {
                    if (x == id)
                    {
                        cnt++;
                    }
                }
                if (cnt >= 2)
                    return true;
                // if (i == 0)
                // {
                //     if (id == component[i + 1][j] && component[i][j + 1] == id)
                //         return true;
                // }
                // else if (i == n - 1)
                // {
                //     if (id == component[i - 1][j] && id == component[i][j + 1] == id)
                // }
                // else if (j == 0)
                // {
                // }
                // else if (j == m - 1)
                // {
                // }
                // else
                // {
                // }
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