/*
  User:- sanyam
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define loop(i, k, n) for (ll i = k; i <= n; i += 1)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)
#define init_arr(i, val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()

const ll inf = 1e18;
const int N = 100001;

/* ---------------------Code--------------------  */

class Solution {
public:
  ll dp[100001][2];

  ll solve(ll n, bool alice) {
    if (n == 0) {
      return !alice;
    } else if (dp[n][alice] != -1)
      return dp[n][alice];

    ll ans = -1;
    for (ll i = 1; i * i <= n; i++) {
      ans = solve(n - i * i, !alice);
      if (ans == alice)
        break;
    }

    return dp[n][alice] = ans;
  }

  bool winnerSquareGame(int n) {
    fastIO;
    if (n == 1)
      return true;
    memset(dp, -1, sizeof(dp));
    bool alice = true;
    int ans = solve((ll)n, alice);
    return ans == 1;
  }
};