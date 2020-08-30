
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
#define popcount __builtin_popcountll

void printVector(vector<ll>& v) {
    for (ll x : v) cout << x << " ";
    cout << endl;
}

/* ---------------------Code--------------------  */

class Solution {
   public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = 0;
        map<int, int> mp;
        mp[0] = -1;
        int negc = 0, zeros = 0, start = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                negc++;
            else if (nums[i] == 0) {
                mp.clear();
                mp[0] = i;
                negc = 0;
            }

            if (negc % 2 == 0 && mp.find(0) != mp.end()) {
                int poss_ans = i - mp[0];
                ans = max(ans, poss_ans);
            } else if (negc % 2 == 1 && mp.find(1) != mp.end()) {
                int poss_ans = i - mp[1];
                ans = max(ans, poss_ans);
            }
            if (mp.find(negc % 2) == mp.end()) {
                mp[negc % 2] = i;
            }
            cout << ans << endl;
        }
        return ans;
    }
};
