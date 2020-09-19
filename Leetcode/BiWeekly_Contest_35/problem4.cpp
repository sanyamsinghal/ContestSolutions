#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

class Solution {
   public:
    bool isPrintable(vector<vector<int>> &targetGrid) {
        int n = targetGrid.size();
        int m = targetGrid[0].size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int col = targetGrid[i][j];
                if (mp.find(col) == mp.end()) {
                    mp[col] = {i, j, i, j};
                } else {
                    mp[col][0] = min(mp[col][0], i);
                    mp[col][1] = min(mp[col][1], j);
                    mp[col][2] = max(mp[col][2], i);
                    mp[col][3] = max(mp[col][3], j);
                }
            }
        }

        int count = mp.size();
        for (int i = 0; i < count && mp.size() != 0; i++) {
            vector<int> found;
            for (auto &it : mp) {
                int valid = true;
                vector<int> &curr = it.second;
                for (int x = curr[0]; x <= curr[2]; x++) {
                    for (int y = curr[1]; y <= curr[3]; y++) {
                        if (targetGrid[x][y] != it.first && targetGrid[x][y] != -1) {
                            valid = false;
                            break;
                        }
                        if (valid == false)
                            break;
                    }
                }

                if (valid) {
                    found.push_back(it.first);
                    for (int x = curr[0]; x <= curr[2]; x++) {
                        for (int y = curr[1]; y <= curr[3]; y++) {
                            targetGrid[x][y] = -1;
                        }
                    }
                }
            }
            if (found.empty()) {
                return false;
            } else {
                for (auto &f : found)
                    mp.erase(f);
            }
        }

        return true;
    }
};