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

const ll inf = 1e18;
const int N =100001;

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

/* ---------------------Code--------------------  */
class Solution {
public:
    int longestAwesome(string s) {
        fastIO;
        int n = s.size();
        if (n<=1)    return n;
        int dp[1024];
        for (int i=0; i<=1024; i++)  dp[i] = n+1;;
        int mask = 0;
        int ans = 1;
        dp[0] = -1;
        for (int i=0; i<n; i++) {
            mask = (mask ^ (1<<(s[i]-'0')));
            if (i-dp[mask] > ans)
                ans = i-dp[mask];
            for (int j=0; j<10; j++) {
                int check = (mask^(1<<j));
                if (i-dp[check] > ans)
                    ans = i-dp[check];
            }
            if (dp[mask] > i)
                dp[mask] = i;
        }
        return ans;
    }
};