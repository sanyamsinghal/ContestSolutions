
/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

/* ---------------------Code--------------------  */

class Solution {
   public:
    bool containsPattern(vector<int>& arr, int m, int K) {
        int n = arr.size();
        int flag = 0;
        for (int i = 0; i <= n - m; i++) {
            vector<int> pattern;
            for (int j = i; j < i + m; j++) {
                pattern.push_back(arr[j]);
            }

            // cout << i << endl;
            // printVector(pattern);

            int patcnt = 0;
            int k = 0;
            while (k <= n - m) {
                int len = 0;
                for (int l = k; l < k + m; l++) {
                    if (arr[l] == pattern[len])
                        len++;
                    else
                        break;
                }
                if (len == m) {
                    patcnt++;
                    k = k + m;
                } else {
                    k++;
                    patcnt = 0;
                }
                if (patcnt >= K) {
                    break;
                }
            }
            // cout << "pat cnt is " << patcnt << endl;
            if (patcnt >= K) return true;
        }
        return false;
    }
};