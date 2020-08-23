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
    string thousandSeparator(int n)
    {
        string s = to_string(n);
        string res = "";

        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            res += s[i];
            cnt = (cnt + 1) % 3;
            if (cnt == 0 && i != 0)
            {
                res += ".";
            }
        }
        reverse(sort_cut(res));
        return res;
    }
};