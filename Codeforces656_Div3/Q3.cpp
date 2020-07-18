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

bool increasing(vector<ll> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }
  return true;
}

ll solve() {
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  if (increasing(arr))
    return 0;

  ll pos1 = 1, pos2 = 1;
  int flag1 = 1, flag2 = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (flag1 == 1) {
      if (arr[i] <= arr[i + 1]) {
        pos1++;
      } else {
        flag1 = 0;
      }
    }

    if (flag2 == 1) {
      if (arr[i] >= arr[i + 1]) {
        pos2++;
      } else {
        flag2 = 0;
        pos2++;
      }
    } else if (flag2 == 0) {
      if (arr[i] <= arr[i + 1])
        pos2++;
      else {
        flag2 = -1;
      }
    }
  }

  return n - max(pos1, pos2);
}

int main() {
  fastIO;
  // take_fileIO();
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}