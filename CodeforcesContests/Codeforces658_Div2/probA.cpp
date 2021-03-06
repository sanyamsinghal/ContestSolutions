/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;
#define ip(x) \
      ll x;   \
      cin >> x;
#define op(x) cout << x;
#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t) \
      int t; \
      cin >> t while (t--)
#define triplet pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                      \
      ios_base::sync_with_stdio(0); \
      cin.tie(0);                   \
      cout.tie(0);
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)
#define init_arr(i, val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()
/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
*/
const ll inf = 1e18;
const int N = 100001;
void take_fileIO()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
      return;
}

/* ---------------------Code--------------------  */

void solve()
{
      ll n, m;
      cin >> n >> m;
      vector<ll> a(n), b(m);
      unordered_set<ll> s;
      ll ans = -1;
      ll possible = 0;
      for (ll i = 0; i < n; i++)
            cin >> a[i], s.insert(a[i]);
      for (ll i = 0; i < m; i++)
      {
            cin >> b[i];
            if (s.find(b[i]) != s.end())
            {
                  possible = 1;
                  ans = b[i];
            }
      }

      if (possible == 1)
      {
            cout << "YES\n";
            cout << "1 " << ans << endl;
      }
      else
      {
            cout << "NO\n";
      }
      return;
}

int main()
{
      fastIO;
      // take_fileIO();

      ll t;
      cin >> t;
      while (t--)
      {
            solve();
      }

      return 0;
}