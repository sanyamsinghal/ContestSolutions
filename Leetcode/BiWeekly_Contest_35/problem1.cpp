/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

class Solution {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for (int l = 1; l <= n; l += 2) {
            for (int i = 0; i <= n - l; i++) {
                for (int j = i; j < i + l; j++) {
                    sum += arr[j];
                }
            }
        }
        return sum;
    }
};