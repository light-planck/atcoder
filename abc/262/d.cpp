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

  using mint = modint998244353;
  mint ans = 0;
  
  for (ll l = 1; l <= n; ++l) {
    // dp[j][k]: j個選んだときの総和%lがkのときの場合の数
    vector dp(l+1, vector<mint>(l));
    dp[0][0] = 1;

    rep(i, n) {
      vector prev(l+1, vector<mint>(l));
      swap(prev, dp);

      for (ll j = 0; j <= l; ++j) {
        for (ll k = 0; k < l; ++k) {
          // 選ばない
          dp[j][k] += prev[j][k];

          // 選ぶ
          if (j+1 <= l) dp[j+1][(k+a[i])%l] += prev[j][k];
        }
      }
    }

    ans += dp[l][0];
  }

  cout << ans.val() << '\n';
  return 0;
}