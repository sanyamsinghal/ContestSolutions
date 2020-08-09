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
    bool check(char a, char b) {
        if ((isupper(a) && islower(b) && tolower(a)==tolower(b)) || (islower(a) && isupper(b) && tolower(a)==tolower(b)))
            return true;
        return false;
    }

    string makeGood(string s) {
        stack<char>st;
        int n = s.size();

        for (int i=0; i<n; i++) {
            if (st.empty()==false && check(st.top(), s[i]))
                st.pop();
            else
                st.push(s[i]);
        }

        string ans = "";
        while (st.empty()==false)
        {
            ans += st.top();
            st.pop();
        }
        reverse(sort_cut(ans));
        return ans;
    }
};