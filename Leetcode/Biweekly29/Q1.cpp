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
    double average(vector<int>& salary) {
        int n = salary.size();

        double res = 0;
        sort(arr.begin(), arr.end());
        for(int i=1; i<n-1; i++) {
          res += (double)salary[i];
        }

        res = res/((double)n-2);
        return res;
    }
};
