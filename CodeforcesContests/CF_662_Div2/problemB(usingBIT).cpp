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
const int N =100001*2+1;
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
ll BIT[N+5];

void update(ll num, ll val, ll end) {
    end  = N;
    while (num<=end) {
        BIT[num] += val;
        num += (num&(-num));
    }
}

ll query(ll freq) {
    ll res = 0;
    while (freq>0) {
        res += BIT[freq];
        freq -= (freq&(-freq));
    }
    return res;
}

ll queryresult(ll freq, ll end) {
    end = N;
    ll res =  query(end) - query(freq-1);
    return res;
}

void solve() {
    ll n;
    cin>>n;
    memset(BIT, 0, sizeof(BIT));
    vector<ll>arr(n);
    map<ll, ll>mp;
    for (int i=0; i<n; i++)
        cin>>arr[i], mp[arr[i]]++;

    for (auto it : mp) {
        update(it.second, 1, N);
    }

    ll q;
    cin>>q;
    for (ll i=0; i<q; i++) {
        char symbol;    cin>>symbol;
        ll data;    cin>>data;
        // cout<<symbol<<" " <<data<<endl;
        ll prevfreq = mp[data];
        if (prevfreq!=0)
            update(prevfreq, -1, n);
        ll currentfreq = prevfreq + (symbol=='-' ? -1 :1);
        mp[data] = currentfreq;
        if (currentfreq>0)
            update(currentfreq, 1, n);

        // for (int i=1; i<=8; i++)
        //     cout<<queryresult(i, N)<<" ";
        // cout<<endl;

        bool possible = false;
        possible = queryresult(8, n)>0 || (queryresult(6, n)>0 && (queryresult(2, n)-queryresult(6, n))>0);
        if (possible==false)
            possible = queryresult(4, n)>1 || (queryresult(4, n)>0 && (queryresult(2, n)-queryresult(4, n))>1);
        if (possible)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

}

int main() {
    fastIO;
    take_fileIO();

    solve();

    return 0;
}