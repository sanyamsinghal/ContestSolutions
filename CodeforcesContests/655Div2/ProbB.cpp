/*
  User:- sanyam
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ip(x)                                                                  \
  ll x;                                                                        \
  cin >> x;
#define op(x) cout << x;
#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t)                                                                   \
  int t;                                                                       \
  cin >> t while (t--)
#define triplet pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)
#define init_arr(i, val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()
#define debug1(x) cout << #x << " " << x << endl;
#define debug2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z     \
       << endl;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>

    PBDS;

const ll inf = 1e18;
const int N = 100001;

void take_fileIO() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  return;
}

/* ---------------------Code--------------------  */

vector<ll> primes;
bool p[1000001];

bool isPrime(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

void sieve() {

  for (ll i = 2; i <= 1000000; i++) {
    if (p[i]) {
      primes.push_back(i);
      for (ll j = 2 * i; j <= 1000000; j += i) {
        p[j] = false;
      }
    }
  }
}

map<ll, ll> findFactors(ll n) {
  ll i = 0;
  map<ll, ll> ans;
  while (n > 1 && p[n] == false) {
    while (n % primes[i] == 0) {
      n = n / primes[i];
      ans[primes[i]]++;
    }
    i++;
  }

  if (n != 1)
    ans[n]++;
  return ans;
}

void solve() {
  ll n;
  cin >> n;

  if (n % 2 == 0) {
    cout << n / 2 << " " << n / 2 << endl;
    return;
  }

  if (isPrime(n)) {
    cout << 1 << " " << (n - 1) << endl;
  }

  map<ll, ll> facts = findFactors(n);
  ll ans = 1;

  ll low = (*facts.lower_bound(0LL)).first;
  facts[low]--;

  for (auto x : facts) {
    ll num = x.first;

    while (facts[num]--) {
      ans = ans * num;
    }
  }

  vector<ll> anss = {ans, n - ans};
  sort(sort_cut(anss));
  cout << anss[0] << " " << anss[1] << endl;
}

int main() {
  fastIO;
  // take_fileIO();
  memset(p, true, sizeof(p));
  sieve();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}