/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;
#define ip(x) \
  ll x;       \
  cin >> x;
#define op(x) cout << x;
#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t) \
  int t;     \
  cin >> t while (t--)
#define triplet pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                  \
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
const int N = 100001;
void take_fileIO()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  return;
}

/* ---------------------Code--------------------  */

void changetoreverse(string &s, int last)
{
  for (int i = 0; i <= last; i++)
  {
    s[i] = ((s[i] == '1') ? '0' : '1');
  }
  int i = 0;
  while (i <= last)
  {
    char c = s[i];
    s[i] = s[last];
    s[last] = c;
    i++;
    last--;
  }
}

void solve()
{
  ll n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  vector<int> ans;
  for (ll last = n - 1; last >= 0; last--)
  {
    if (a[last] == b[last])
    {
      // cout << last << " 0\n";
      continue;
    }
    else
    {
      // cout << last << " 1\n";
      if (b[last] == '1')
      {
        if (a[0] == '0')
        {
          changetoreverse(a, last);
          ans.push_back(last + 1);
        }
        else
        {
          a[0] = '0';
          changetoreverse(a, last);
          ans.push_back(1);
          ans.push_back(last + 1);
        }
      }
      else
      {
        if (a[0] == '1')
        {
          changetoreverse(a, last);
          ans.push_back(last + 1);
        }
        else
        {
          a[0] = '1';
          changetoreverse(a, last);
          ans.push_back(1);
          ans.push_back(last + 1);
        }
      }
    }
  }
  // cout << a << endl;
  // cout << b << endl;

  cout << ans.size() << " ";
  for (int x : ans)
    cout << x << " ";
  cout << endl;
}

int main()
{
  fastIO;
  // take_fileIO();
  ll t;
  cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}