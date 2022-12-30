#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // dp[i][j]: i = sum%n, j = 選んだ個数のときの場合の数
  vector dp(n, vector<ll>(n+1));
  dp[0][0] = 1;

  rep(i, n) {
    vector prev(n, vector<ll>(n+1));
    swap(prev, dp);

    for (ll j = 0; j < n; ++j) {
      for (ll k = 0; k <= n; ++k) {
        // 選ばない
        dp[j][k] += prev[j][k];

        // 選ぶ
        if (k+1 <= n) dp[(j+a[i]) % (i+1)][k+1] += prev[j][k];
      }
    }
  }

  using mint = modint998244353;
  mint ans = 0;
  rep(j, n) for (ll k = 1; k <= n; ++k) {
    if (dp[j][k] % k == 0) ans += (mint)dp[j][k];
  }
  cout << ans.val() << '\n';
  return 0;
}