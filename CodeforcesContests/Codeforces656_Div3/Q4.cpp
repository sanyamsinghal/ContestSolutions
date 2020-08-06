/*
  User:- sanyam
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ip(x)                                                                  \
  ll x;                                                                        \
  cin >> x;
#define op(x) cout << x;
#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t)                                                                   \
  int t;                                                                       \
  cin >> t while (t--)
#define triplet pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)
#define init_arr(i, val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()
#define debug1(x) cout << #x << " " << x << endl;
#define debug2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z     \
       << endl;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>

    PBDS;

const ll inf = 1e18;
const int N = 100001;

void take_fileIO() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  return;
}

/* ---------------------Code--------------------  */

ll unmatch_count(string &s, ll i, ll j, ll level) {
  ll ans = 0;
  for (ll k = i; k <= j; k++) {
    if (level != (s[k - 1] - 'a'))
      ans++;
  }
  return ans;
}

ll recursion(string &s, ll i, ll j, ll level) {
  if (i == j) {
    ll ret = ((s[i - 1] - 'a') != level);
    // cout << "base case " << s[i - 1] << " and level is " << level
    //      << " and return valiues is " << ret << endl;
    return ret;
  } else if (i > j)
    return INT_MAX;

  // else if(dp)

  else {
    ll op1 = INT_MAX;
    ll op2 = INT_MAX;
    ll mid = (i+j)/2;
    // op1
    op1 = unmatch_count(s, i, mid, level) +
          recursion(s, mid+1, j, level + 1);

    // op2
    op2 = unmatch_count(s, mid + 1, j, level) +
          recursion(s, i, mid, level + 1);
    // cout << i << " " << j << " " << op1 << " " << op2 << endl;
    return min(op1, op2);
  }
}

void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  // cout << ("hello1\n");
  ll ans = recursion(s, 1, n, 0);
  // cout << ("hell02\n");
  cout << ans << endl;
  return;
}

int main() {
  fastIO;
  // take_fileIO();
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}