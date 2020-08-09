//similar to problem 4 but easier

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
/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
*/
const ll inf = 1e18;
const int N =100001;
void take_fileIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    return;
}

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

/* ---------------------Code--------------------  */

class Solution {
public:
    bool isvowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int findTheLongestSubstring(string s) {
        int n = s.size();
        map<ll, ll>dp;
        dp[0]=-1;
        ll mask = 0;
        ll ans = 0;
        for (ll i=0; i<n; i++) {
            if (isvowel(s[i])) {
                mask = (mask ^ (1<<(s[i]-'a')));
            }

            if (dp.find(mask)!=dp.end()) {
                ans = max(ans, i-dp[mask]);
            }
            else {
                dp[mask] = i;
            }
            // cout<<i<<" "<<s[i]<<" "<<ans<<endl;
        }

        return ans;
    }
};