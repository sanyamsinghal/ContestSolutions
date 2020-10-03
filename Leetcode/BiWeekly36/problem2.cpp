#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    void print(deque<string> d) {
        while (d.empty() == false) {
            cout << d.front() << " ";
            d.pop_front();
        }
        cout << endl;
    }

    string createLastTime(string s) {
        int hh = stoi(s.substr(0, 2));
        int mm = stoi(s.substr(3));
        if (hh == 0) {
            return "00:00";
        } else {
            hh--;
            string hhp = ((hh >= 10) ? to_string(hh) : ("0" + to_string(hh)));
            hhp += s.substr(2);
            return hhp;
        }
    }

    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime) {
        vector<string> res;
        map<string, set<string>> mp;

        for (int i = 0; i < keyName.size(); i++) {
            mp[keyName[i]].insert(keyTime[i]);
        }

        for (auto &it : mp) {
            string name = it.first;
            set<string> &curr = it.second;
            int flag = 0;

            deque<string> d;
            // cout<<name<<endl;

            for (auto &i : curr) {
                string lasttime = createLastTime(i);
                while (!d.empty() && d.front() < lasttime) {
                    d.pop_front();
                }
                d.push_back(i);
                // print(d);
                if (d.size() >= 3) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1) {
                // cout<<
                res.push_back(name);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};