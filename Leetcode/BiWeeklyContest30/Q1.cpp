/*
  User:- sanyam
*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
#define loop(i, k, n) for(ll i=k; i<=n; i+=1)
#define loop2(i, k, n) for(ll i=k; i>=n; i--)
#define init_arr(i,val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()

const ll inf = 1e18;
const int N =100001;

/* ---------------------Code--------------------  */

class Solution {
public:
    map<string, string>months = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"},
     {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, 
     {"Dec", "12"}};
    // vector<string>dates = {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"};
    
    string reformatDate(string date) {
        int n = date.size();
        vector<string>v;
        string curr="";
        
        for(int i=0; i<n; i++) {
            if(date[i]==' ') {
                v.push_back(curr);
                curr ="";
            }
            else
                curr += date[i];
        }
        
        if(curr!="")
            v.push_back(curr);
        
        string mm = to_string(find(sort_cut(months), v[1]) - months.begin() + 1);
        string dd = v[0];
        if(dd.size()<2)
          dd = "0" + dd;
        dd.pop_back();
        dd.pop_back();
        string yyyy = v[2];
        return yyyy + "-" + mm + "-" + dd;
    }
};
