/*
  User:- sanyam
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
#define loop(i, k, n) for(ll i=k; i<=n; i++)
#define loop2(i, k, n) for(ll i=k; i>=n; i--)

const ll inf = 1e18;
const int N =100001;

void take_fileIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    return;
}

/* ---------------------Code--------------------  */
char mat[2001][2001];
ll dp[2005][2005];
ll dp2[2005][2005];
ll dp3[2005][2005];
ll dp4[2005][2005];

ll solve(ll n, ll m) {
    ll ans=0;
    loop(i, 1, n) {
        loop(j, 1, m) {
            if (mat[i-1][j]==mat[i][j] && mat[i][j-1]==mat[i][j]) {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
            else
            {
                dp[i][j]=1;
            }
        }
    }

    loop2(i, n, 1) {
        loop2(j, m, 1) {
            if (mat[i+1][j]==mat[i][j] && mat[i][j+1]==mat[i][j]) {
                dp2[i][j] = 1 + min(dp2[i+1][j], dp2[i][j+1]);
            }
            else
            {
                dp2[i][j]=1;
            }
        }
    }

    loop(i, 1, n) {
        loop2(j, m, 1) {
            if (mat[i-1][j]==mat[i][j] && mat[i][j+1]==mat[i][j]) {
                dp3[i][j] = 1 + min(dp3[i-1][j], dp3[i][j+1]);
            }
            else
            {
                dp3[i][j]=1;
            }
        }
    }

    loop2(i, n, 1) {
        loop(j, 1, m) {
            if (mat[i+1][j]==mat[i][j] && mat[i][j-1]==mat[i][j]) {
                dp4[i][j] = 1 + min(dp4[i+1][j], dp4[i][j-1]);
            }
            else
            {
                dp4[i][j]=1;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ll curr = min(dp[i][j], min(dp2[i][j], min(dp3[i][j], dp4[i][j])));
            ans += curr;
        }
    }

    return ans;
}

int main() {
    fastIO;
    take_fileIO();

    ll n, m;
    cin>>n>>m;
    loop(i, 1, n) {
        loop(j, 1, m) {
            cin>>mat[i][j];
        }
    }

    cout<<solve(n, m);

    return 0;
}