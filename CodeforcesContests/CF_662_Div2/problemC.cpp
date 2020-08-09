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


bool leastInterval(vector<ll>& arr, ll mid) {
    ll N = arr.size();
    ll maxf=0;
    map<ll, ll>freq;
    for (int i=0; i<N; i++) {
        freq[arr[i]]++;
        maxf = max(maxf, freq[arr[i]]);
    }

    vector<pll>farr;
    for (auto it : freq) {
        farr.push_back({ it.second, it.first });
    }

    sort(sort_cut(farr), greater<pll>());
    ll count=0;
    for (int i=0; i<farr.size() && farr[i].first==maxf; i++) {
        count++;
    }

    ll ret = (farr[0].first-1)*(mid+1) + count;
    return max(ret, N)==N;

}

void solve() {
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for (int i=0; i<n; i++)
        cin>>arr[i];

    ll low=0, high=n-2;
    ll ans  = 0;
    while (low<=high)
    {
        ll mid = low + (high-low)/2;
        if (leastInterval(arr, mid)) {
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }

    cout<<ans<<endl;
}

int main() {
    fastIO;
    take_fileIO();

    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }


    return 0;
}