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

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n= nums.size();
        int start=-1;
        map<int, vector<int>>mp;
        mp[0].push_back(-1);
        int cs = 0;
        int ans = 0;
        for (int i=0; i<n; i++) {
            cs += nums[i];

            if (mp.find(cs-target)!=mp.end()) {
                if (mp[cs-target].back()>=start) {
                    ans++;
                    start = i;
                }
            }
            mp[cs].push_back(i);
        }

        return ans;
    }
};