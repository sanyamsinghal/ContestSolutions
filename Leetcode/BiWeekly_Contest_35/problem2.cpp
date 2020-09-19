/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

class Solution {
   public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<ll> freq(n, 0);

        for (int i = 0; i < requests.size(); i++) {
            int start = requests[i][0];
            int end = requests[i][1];
            freq[start] += 1;
            if (end + 1 < n)
                freq[end + 1] += -1;
        }

        for (int i = 0; i < n; i++) {
            freq[i] = freq[i] + (i == 0 ? 0 : freq[i - 1]);
        }

        priority_queue<ll> pqelemes, pqfreq;
        ll sum = 0;
        for (int x : nums) {
            pqelemes.push(x * 1LL);
        }

        for (int i = 0; i < n; i++) {
            pqfreq.push(freq[i] * 1LL);
        }

        while (pqfreq.empty() == false) {
            ll cnt = pqfreq.top();
            pqfreq.pop();
            ll ele = pqelemes.top();
            pqelemes.pop();

            sum += cnt * ele;
            sum %= mod;
        }
        return sum;
    }
};