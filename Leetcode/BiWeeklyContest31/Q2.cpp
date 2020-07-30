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

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        ll ans = 0;
        ll cs = 0;
        ll os = 0, es = 0;
        for (int i = 0; i < n; i++)
        {
            cs += arr[i];

            if (cs % 2 == 0)
            {
                ans = (ans % mod + os % mod) % mod;
            }
            else
            {
                ans = (ans % mod + es % mod) % mod;
            }
            if (ans[i] % 2 == 1)
                ans++;
            if (cs % 2)
                os++;
            else
                es++;
        }
        return ans;
    }
};