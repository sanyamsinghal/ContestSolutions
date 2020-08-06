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
ll x, y, z;

bool match(vector<ll> &curr) {
  return x == max(curr[0], curr[1]) && y == max(curr[0], curr[2]) &&
         z == max(curr[1], curr[2]);
}

bool recursion(vector<ll> &curr) {
  if (curr.size() == 3) {
    return match(curr);
  } else {
    curr.push_back(x);
    if (recursion(curr))
      return true;
    curr.pop_back();

    curr.push_back(y);
    if (recursion(curr))
      return true;
    curr.pop_back();

    curr.push_back(z);
    if (recursion(curr))
      return true;
    curr.pop_back();
    return false;
  }
}

void solve() {
  cin >> x >> y >> z;

  ll a = INT_MIN;
  ll b = INT_MIN;
  ll c = INT_MIN;

  vector<ll> curr;
  bool ans = recursion(curr);
  if (ans == false) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << curr[0] << " " << curr[1] << " " << curr[2] << endl;
  }
  return;
}

int main() {
  fastIO;
  // take_fileIO();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}