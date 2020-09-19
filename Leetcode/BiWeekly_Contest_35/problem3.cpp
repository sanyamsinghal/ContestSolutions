/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

class Solution {
   public:
    int minSubarray(vector<int>& nums, int p) {
        vector<ll> arr;
        ll totalsum = 0;
        ll actual_to = 0;
        for (ll i = 0; i < nums.size(); i++) {
            arr.push_back(nums[i] * 1LL);
            totalsum += arr[i];
            actual_to += arr[i];
            totalsum %= p;
        }
        ll n = arr.size();

        if (totalsum == 0) return 0;
        if (actual_to < p) return -1;

        ll ans = INT_MAX, cs = 0;
        map<ll, ll> mp;
        mp[0] = -1;

        for (ll i = 0; i < arr.size(); i++) {
            ll x = arr[i];
            cs += x;
            cs %= p;

            ll reqd = (cs - totalsum + p) % p;
            if (mp.find(reqd) != mp.end()) {
                ans = min(ans, i - mp[reqd]);
            }
            mp[cs] = i;
        }

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};