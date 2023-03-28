#include <iostream>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;


constexpr int m = 5;
mint dp[105][m][m][m];

int main() {
  ll n;
  cin >> n;

  dp[0][0][0][0] = 1;

  rep(len, n) rep(i, m) rep(j, m) rep(k, m) {
    for (ll l = 1; l < m; ++l) {
      if (j==1 and k==3 and l==2) continue;
      if (j==3 and k==1 and l==2) continue;
      if (j==1 and k==2 and l==3) continue;

      if (i==1 and j==3 and l==2) continue;
      if (i==1 and k==3 and l==2) continue;

      dp[len + 1][j][k][l] += dp[len][i][j][k];
    }
  }

  mint ans = 0;
  for (ll i = 1; i < m; ++i) {
    for (ll j = 1; j < m; ++j) {
      for (ll k = 1; k < m; ++k) ans += dp[n][i][j][k];
    }
  }

  cout << ans.val() << '\n';
  return 0;
}