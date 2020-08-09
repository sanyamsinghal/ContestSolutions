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

bool ispossible(set<pll> &s) {
    if (s.size()==0)
        return false;
    auto it = prev(s.end());
    ll f1 = (*it).first;
    if (f1>=8)
        return true;
    if (it==s.begin())   return false;

    auto it2 = prev(it);
    ll f2 = (*it2).first;
    if ((f1>=6 && f2>=2) || (f1>=4 & f2>=4))
        return true;
    if (it2==s.begin())   return false;

    auto it3 = prev(it2);
    ll f3 = (*it3).first;
    if (f1>=4 && f2>=2 && f3>=2)
        return true;
    return false;
}

void printSet(set<pll> &s) {
    for (auto it : s) {
        cout<<it.second<<" "<<it.first<<endl;
    }
}

void solve() {
    ll n;
    cin>>n;
    vector<ll>arr(n);
    set<pll>s;
    map<ll, ll>mp;
    for (int i=0; i<n; i++) {
        cin>>arr[i];
        mp[arr[i]]++;
    }

    for (auto it : mp) {
        s.insert({ it.second, it.first });
    }

    ll q;
    cin>>q;
    // printSet(s);
    for (int i=0; i<q; i++) {
        char symbol;
        cin>>symbol;
        ll curr;
        cin>>curr;

        ll freq = mp[curr];
        auto it = s.find({ freq, curr });
        if (it!=s.end())
            s.erase(it);
        if (symbol=='-')
            mp[curr]--;
        else
            mp[curr]++;

        // cout<<s.size()<<endl;
        s.insert({ mp[curr], curr });

        if (ispossible(s)) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
        // printSet(s);
    }


}


int main() {
    fastIO;
    take_fileIO();

    solve();

    return 0;
}

