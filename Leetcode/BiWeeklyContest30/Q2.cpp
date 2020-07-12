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
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    vector<ll> subsums;

    for (int i = 0; i < n; i++) {
      ll sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j] * 1LL;
        sum = sum % mod;
        subsums.push_back(sum);
      }
    }
    sort(sort_cut(subsums));

    // for(int i)

    ll ans = 0;
    for (int i = left - 1; i <= right - 1; i++) {
      ans = ans + subsums[i];
      ans = ans % mod;
    }
    return ans;
  }
};