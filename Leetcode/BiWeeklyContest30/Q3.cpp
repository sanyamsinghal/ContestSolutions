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
  ll solve(vector<int> &nums, ll left, ll right, ll count) {
    if (count == 3) {
      return abs(nums[right] - nums[left]);
    }

    else {
      ll op1 = solve(nums, left + 1, right, count + 1);
      ll op2 = solve(nums, left, right - 1, count + 1);

      return min(op1, op2);
    }
  }

  int minDifference(vector<int> &nums) {
    int n = nums.size();
    if (n <= 4)
      return 0;
    sort(sort_cut(nums));
    ll ans = solve(nums, 0, n - 1, 0);
    return ans;
  }
};