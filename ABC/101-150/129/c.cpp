#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> ok(n, true);
  rep(i, m) {
    int idx;
    cin >> idx;
    ok[idx] = false;
  }
  vector<ll> dp(n+2);
  dp[0] = 1;
  rep(i, n) {
    if (ok[i+1]) dp[i+1] += dp[i];
    dp[i+1] %= mod;
    if (ok[i+2]) dp[i+2] += dp[i];
    dp[i+2] % mod;
  }

  cout << dp[n] << endl;
  return 0;
}