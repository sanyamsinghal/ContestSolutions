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
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)
#define init_arr(i, val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()
const ll inf = 1e18;
const int N = 100001;

class Solution
{
public:
    int numSplits(string s)
    {
        int n = s.size();
        if (n <= 1)
            return 0;
        int ans = 0;
        set<char> st, end;
        vector<int> pre(n, 0), suff(n, 0);
        for (int i = 0; i < n; i++)
        {
            st.insert(s[i]);
            pre[i] = st.size();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            end.insert(s[i]);
            suff[i] = end.size();
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (pre[i] == suff[i + 1])
                ans++;
        }
        return ans;
    }
};