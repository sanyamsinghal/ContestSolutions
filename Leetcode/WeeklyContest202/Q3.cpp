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

/* ---------------------Code--------------------  */
class Solution
{
public:
    bool ispossible(vector<ll> &arr, ll mid, ll m)
    {
        ll n = arr.size();
        ll prev = arr[0];
        ll count = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - prev >= mid)
            {
                count++;
                prev = arr[i];
            }
            if (count == m)
                return true;
        }

        return false;
    }

    int maxDistance(vector<int> &p, int m)
    {
        vector<ll> position;
        for (ll x : p)
            position.push_back(x);
        ll n = position.size();
        sort(sort_cut(position));

        ll low = 0, high = 1e9;
        ll ans = 0;

        while (low <= high)
        {
            ll mid = low + (high - low) / 2;

            if (ispossible(position, mid, m))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};