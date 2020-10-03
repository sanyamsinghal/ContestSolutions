#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pll pair<ll, ll>

class Solution {
   public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> res;
        map<ll, ll> served;

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        set<ll> s;
        for (ll i = 0; i < k; i++) {
            s.insert(i);
        }

        for (int i = 0; i < arrival.size(); i++) {
            while (pq.empty() == false && pq.top().first <= arrival[i]) {  //think about equality
                s.insert(pq.top().second);
                pq.pop();
            }

            ll id = i % k;
            auto it = s.find(id);
            if (it != s.end()) {
                served[id]++;
                pq.push({arrival[i] + load[i], id});
                // cout<<i<<" "<<(*it)<<endl;
                s.erase(it);
            } else {
                auto it2 = s.upper_bound(id);
                if (it2 != s.end()) {
                    served[*it2]++;
                    pq.push({arrival[i] + load[i], *it2});
                    // cout<<i<<" "<<(*it2)<<endl;
                    s.erase(it2);
                } else {
                    auto it3 = s.lower_bound(0);
                    if (it3 != s.end()) {
                        served[*it3]++;
                        pq.push({arrival[i] + load[i], *it3});
                        // cout<<i<<" "<<(*it3)<<endl;
                        s.erase(it3);
                    }
                }
            }
        }

        ll mxs = 0;
        for (auto it : served) {
            mxs = max(mxs, it.second);
        }
        for (auto it : served) {
            if (it.second == mxs) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};