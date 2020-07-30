/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;
#define ip(x) \
    ll x;     \
    cin >> x;
#define op(x) cout << x;
#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t) \
    int t;   \
    cin >> t while (t--)
#define triplet pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)
#define init_arr(i, val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()
/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
*/
const ll inf = 1e18;
void take_fileIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return;
}

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x;
    cout << endl;
}
const int N = 2*100000+1;
/* ---------------------Code--------------------  */

ll dp[N];

void dfs(ll node, ll par, vector<ll> &p, map<ll, vector<ll>> &graph) {
    dp[node] = p[node-1];
    for(ll child : graph[node]) {
        if(child!=par) {
            dfs(child, node, p, graph);
            dp[node] += dp[child];
        }
    }
}

bool dfs2(ll node, map<ll, vector<ll>> &graph, vector<ll> &hpeeps, ll par=0) {
    ll par_happiness = hpeeps[node-1];
    ll childs_happiness = 0;

    for(ll child : graph[node]) {
        if(par!=child) {
            if(dfs2(child, graph, hpeeps, node)==false) return false;
            childs_happiness += hpeeps[child-1];
        }
    }
    if(childs_happiness>par_happiness)  return false;
    return true;
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    map<ll, vector<ll>>graph;
    ll n, m;
    cin>>n>>m;

    vector<ll>p(n,0), h(n,0);
    for(int i=0; i<n; i++)
        cin>>p[i];
    for(int i=0; i<n; i++)
        cin>>h[i];

    for(int i=1; i<n; i++) {
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0, p, graph);

    // for(int i=1; i<=n; i++) cout<<dp[i]<<" ";
    // cout<<endl;

    int flag=1;
    vector<ll>hpeeps(n+1, 0);
    for(int i=0; i<n; i++) {
        if(dp[i+1]%2==0) {
            if(h[i]%2!=0 || h[i]>dp[i+1] || h[i]<-dp[i+1]) {
                flag=0;
                // cout<<i<<endl;
                break;
            }
        }
        else {
            if(h[i]%2==0 || h[i]>dp[i+1] || h[i]<-dp[i+1]) {
                // cout<<i<<endl;
                flag=0;
                break;
            }
        }
        hpeeps[i] = dp[i+1] - (dp[i+1] - h[i])/2;
    }
    
    // for(int i=0; i<n; i++)  cout<<hpeeps[i]<<" ";
    // cout<<endl;
    
    if(flag==0) {
        cout<<"NO\n";
        return;
    }

    bool res = dfs2(1, graph, hpeeps);
    if(res==false)   cout<<"NO\n";
    else    cout<<"YES\n";

    

}

int main()
{
    fastIO;
    // take_fileIO();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}