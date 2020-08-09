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

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<char>st;
        int ans = 0;

        for (int i=0; i<n; ) {
            if (s[i]=='(') {
                st.push(s[i]);
                i++;
            }
            else {
                if (i+1<n && s[i+1]==')') { //just checking if the second closing bracket present
                    i = i+2;
                    if (st.empty()) // if not present then increase count for it
                        ans++;
                    else    // if present then just skip and pop '('
                        st.pop();
                }
                else {//so if it is not present then we need to add 1 or 2 on the basis if '(' is present or not at stack top
                    if (st.empty())
                        ans+=2;
                    else {
                        ans++;
                        st.pop();
                    }
                    i++;
                }
            }
        }

        while (st.empty()==false) { //so for remaining opening brackets pop them 
            st.pop();
            ans += 2;
        }

        return ans;
    }
};