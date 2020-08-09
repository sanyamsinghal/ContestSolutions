/*
  User:- sanyam
*/
#include<bits/stdc++.h>
using namespace std;
#define ip(x) ll x; cin>>x;
#define op(x) cout<<x;
#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t) int t;	cin>>t while(t--)
#define triplet pair<int,pair<int,int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
#define loop(i, k, n) for(ll i=k; i<=n; i++)
#define loop2(i, k, n) for(ll i=k; i>=n; i--)
#define init_arr(i,val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()


class Solution {
public:
    int dp[102][102];

    int solve(vector<int> &cuts, int low, int high) {
        if (low+1==high) return 0;
        else if (dp[low][high]!=-1)
            return dp[low][high];

        else {
            int ans = INT_MAX;
            for (int i=low+1; i<high; i++) {
                int curr = cuts[high]-cuts[low] + solve(cuts, low, i) + solve(cuts, i, high);
                ans = min(ans, curr);
            }
            return dp[low][high] = ans;
        }
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin(), cuts.end());
        return solve(cuts, 0, cuts.size()-1);
    }
};