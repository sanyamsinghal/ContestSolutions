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

/* ---------------------Code--------------------  */

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll mat[n + 1][m + 1], mat2[n + 1][m + 1];
    memset(mat, 0, sizeof(mat));

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            mat2[i][j] = s[j - 1] - '0';
        }
    }

    ll q;
    cin >> q;

    while (q--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        mat[x1][y1]++;
        if (y2 + 1 <= m)
            mat[x1][y2 + 1]--;
        if (x2 + 1 <= n)
            mat[x2 + 1][y1]--;
        if (x2 + 1 <= n && y2 + 1 <= m)
            mat[x2 + 1][y2 + 1]++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                // continue;
            }
            else if (i == 1)
                mat[i][j] = mat[i][j] + mat[i][j - 1];
            else if (j == 1)
                mat[i][j] = mat[i][j] + mat[i - 1][j];
            else
                mat[i][j] = mat[i][j] + mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << ((mat[i][j] + mat2[i][j]) % 2);
        }
        cout << endl;
    }
    return;
}

int main()
{
    fastIO;

    solve();
    return 0;
}

// Basic Overview
// mat[i][j] - contains the input values
// mat2[i][j] - contains the values after all the queries.
// - I am just adding 1 to all the elements in the submatrix from (x1,y1) to (x2,y2) in mat2[i][j]
// - So at the end if mat[i][j] + mat2[i][j] is odd then the value is 1 else it is zero
// - I hope you have got this

// Details
// - In 2d matrix mat2[][], if we do an update at (x1,y1) then it will be update in all the submatrics starting at (x1,y1) and ending at (n,m)
// - But here we want to update from (x1,y1) to (x2,y2).
// - I just added +1 to mat2[x1][x2] and -1 at mat2[x1][y2+1], mat2[x2+1][y1]
// - But after doing this it would have cause an extra -1 at some place so added +1 to mat2[x2+1][[y2+1] (Visualize this by drawing matrix and submatrix)

// So just at end check the sum if it is even or odd

// Prequisites :- How to make 2-D Prefix sum matrix and how it works (you can read about prefix arrays on GFG)
