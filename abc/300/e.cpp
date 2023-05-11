#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;


int main() {
  ll n;
  cin >> n;

  vector<mint> dp(n+1);
  dp[1] = 1;

  mint div = (mint)1 / 6;

  auto loop = [&]() {
    while (true) {
      vector<mint> prev(n+1);
      swap(prev, dp);

      for (ll j = 1; j <= n; ++j) {
        if (prev[j] == 0) continue;

        for (ll k = 1; k <= n; ++k) {
          if (j*k > n) return;

          dp[j*k] += prev[j] * div;
        }
      }
    }
  };
  loop();

  cout << dp[n].val() << '\n';
  return 0;
}