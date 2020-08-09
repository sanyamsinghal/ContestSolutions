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
    char shift(char c) {
        if (c=='z')  return 'a';
        return (char)((c-'a' + 1));
    }

    bool canConvertString(string s, string t, int k) {
        int n = s.size();
        int m = t.size();

        if (n!=m)    return false;
        map<int, int>mp;
        ll ans = 0;
        for (int i=0; i<n; i++) {
            if (s[i]!=t[i]) {
                ll rots = (26+t[i]-s[i])%26;
                mp[rots]++;
            }
        }

        for (auto it : mp) {
            cout<<it.first<<" " <<it.second<<endl;
        }

        for (auto it : mp) {
            int freq = it.second;
            for (ll i=0; i<freq; i++) {
                ans = max(ans, ((26*i)+it.first));
                if (ans>k)
                    return false;
            }
        }

        return true;
    }
};