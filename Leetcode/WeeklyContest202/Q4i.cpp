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

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

class Solution
{
public:
    int minDays(int n)
    {

        queue<int> q;
        q.push(n);
        int level = 0;
        map<int, bool> vis;
        vis[n] = true;

        while (q.empty() == false)
        {
            int s = q.size();
            for (int i = 1; i <= s; i++)
            {
                int curr = q.front();
                q.pop();
                cout << curr << " ";
                if (curr == 0)
                    return level;

                if (curr % 3 == 0 && vis[curr / 3] == false)
                {
                    q.push(curr / 3);
                    vis[curr / 3] = true;
                }
                if (curr % 2 == 0 && vis[curr / 2] == false)
                {
                    vis[curr / 2] = true;
                    q.push(curr / 2);
                }
                if (vis[curr - 1] == false)
                {
                    vis[curr - 1] = true;
                    q.push(curr - 1);
                }
            }
            level++;
        }

        return level;
    }
};

// 10
// 6
// 1
// 56
// 94523
// 74535
// 9209408
// 6128305