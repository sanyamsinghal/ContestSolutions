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
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;

    int start = 0;
    int flag = 0;
    int prev = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 1) {
        // continue;  nothing
      } else {
        if (flag == 0) {
          flag = 1;
          prev = i;
        } else {
          ans = max(ans, i - start - 1);
          start = prev + 1;
          prev = i;
        }
      }
      ans = max(ans, i + 1 - start - 1);
      cout << start << " " << i << endl;
      cout << flag << " " << ans << endl;
    }

    return ans;
  }
};