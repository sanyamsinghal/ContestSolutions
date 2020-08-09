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
    string invert(string &s) {
        string res = "";
        for (char c : s) {
            res += (c=='1' ? '0' : '1');
        }
        reverse(sort_cut(res));
        return res;
    }

    char findKthBit(int n, int k) {
        string s="0";

        for (int i=2; i<=n; i++) {
            s = s + "1" + invert(s);
        }
        cout<<s<<endl;
        return s[k-1];
    }
};

// S1 = "0"
// S2 = "011"
// S3 = "0111001"
// S4 = "011100110110001"