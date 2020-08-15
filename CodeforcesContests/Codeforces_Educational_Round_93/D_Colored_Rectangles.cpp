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
#define loop(i, k, n) for (ll i = k; i <= n; i++)
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
const int N = 100001;
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
        cout << x << " ";
    cout << endl;
}

/* ---------------------Code--------------------  */
ll dp[300][300][300];

ll solvedp(vector<ll> &a, vector<ll> &b, vector<ll> &c, ll i, ll j, ll k)
{
    ll ec = (i >= a.size() ? 1 : 0) + (j >= b.size() ? 1 : 0) + (k >= c.size() ? 1 : 0);
    if (ec >= 2)
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    else
    {
        ll ans = 0;
        ll opab = (i >= a.size() || j >= b.size()) ? 0 : (a[i] * b[j] + solvedp(a, b, c, i + 1, j + 1, k));
        ll opac = (i >= a.size() || k >= c.size()) ? 0 : (a[i] * c[k] + solvedp(a, b, c, i + 1, j, k + 1));
        ll opbc = (j >= b.size() || k >= c.size()) ? 0 : (b[j] * c[k] + solvedp(a, b, c, i, j + 1, k + 1));

        ans = max(opab, max(opbc, opac));
        return dp[i][j][k] = ans;
    }
}

void solve2()
{
    memset(dp, -1, sizeof(dp));
    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<ll> a(n1), b(n2), c(n3);
    loop(i, 0, n1 - 1) cin >> a[i];
    loop(i, 0, n2 - 1) cin >> b[i];
    loop(i, 0, n3 - 1) cin >> c[i];

    sort(sort_cut(a), greater<ll>());
    sort(sort_cut(b), greater<ll>());
    sort(sort_cut(c), greater<ll>());

    ll res = solvedp(a, b, c, 0, 0, 0);
    // cout << "here\n";
    cout << res << endl;
}

void solve()
{
    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<ll> a(n1), b(n2), c(n3);
    loop(i, 0, n1 - 1) cin >> a[i];
    loop(i, 0, n2 - 1) cin >> b[i];
    loop(i, 0, n3 - 1) cin >> c[i];

    priority_queue<ll> pqa, pqb, pqc;

    loop(i, 0, n1 - 1) pqa.push(a[i]);
    // loop(i, n1, ms - 1) pqa.push(LONG_MIN);

    loop(i, 0, n2 - 1) pqb.push(b[i]);
    // loop(i, n2, ms - 1) pqb.push(LONG_MIN);

    loop(i, 0, n3 - 1) pqc.push(c[i]);
    // loop(i, n3, ms - 1) pqc.push(LONG_MIN);

    ll ans = 0;
    while (1)
    {
        ll elea = pqa.empty() ? LONG_MIN : pqa.top();
        ll eleb = pqb.empty() ? LONG_MIN : pqb.top();
        ll elec = pqc.empty() ? LONG_MIN : pqc.top();

        ll minc = 0;
        for (ll x : {elea, eleb, elec})
            if (x == LONG_MIN)
                minc++;
        if (minc >= 2)
            break;

        if (elea <= eleb && elea <= elec)
        {
            pqc.pop();
            pqb.pop();
            ans += eleb * elec;
            // cout << "1\n";
        }
        else if (eleb <= elec && eleb <= elea)
        {
            pqa.pop();
            pqc.pop();
            ans += elea * elec;
            // cout << "2\n";
        }
        else
        {
            pqa.pop();
            pqb.pop();
            ans += elea * eleb;
            // cout << "3\n";
        }
    }
    cout << ans << endl;
}

int main()
{
    fastIO;
    // take_fileIO();

    solve2();

    return 0;
}