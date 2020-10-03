#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> mat(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ele = min(rowSum[i], colSum[j]);
                rowSum[i] -= ele;
                colSum[j] -= ele;
                mat[i][j] = ele;
            }
        }

        return mat;
    }
};
