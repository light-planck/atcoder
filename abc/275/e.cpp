#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;


int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  mint inv = (mint)1/m;
  vector<mint> dp(n+1);
  dp[0] = 1;

  rep(i, k) {
    vector<mint> prev(n+1);
    swap(prev, dp);

    for (ll j = 0; j <= n; ++j) {
      if (j == n) {
        dp[j] += prev[j];
        continue;
      }

      for (ll dice = 1; dice <= m; ++dice) {
        ll nj = j + dice;
        if (nj > n) nj = n - (nj-n);
        dp[nj] += prev[j] * inv;
      }
    }
  }

  cout << dp[n].val() << '\n';
  return 0;
}