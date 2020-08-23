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
const ll inf = 1e18;
const int N = 100001;

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

class Solution
{
public:
    void update(vector<int> &sectors, int start, int end, int n)
    {
        while (start != end)
        {
            sectors[start]++;
            start++;
            if (start > n)
                start = 1;
        }
        // sectors[start]++;
    }

    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        vector<int> sectors(n + 1, 0);
        int ans = 0;
        for (int i = 1; i < rounds.size(); i++)
        {
            int start = rounds[i - 1];
            int end = rounds[i];
            update(sectors, start, end, n);
        }
        sectors[rounds.back()]++;

        vector<int> res;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, sectors[i]);
            cout << sectors[i] << " ";
        }
        for (int i = 1; i <= n; i++)
        {
            if (sectors[i] == ans)
                res.push_back(i);
        }
        return res;
    }
};