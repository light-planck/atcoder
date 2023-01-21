#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  // i番目までみたときのお金の合計金額
  vector<ll> dp(x+1);
  dp[0] = true;

  rep(i, n) {
    vector<ll> prev(x+1);
    swap(prev, dp);

    for (ll j = 0; j <= x; ++j) {
      if (not prev[j]) continue;

      // 何枚選ぶか
      for (ll k = 0; k <= b[i]; ++k) {
        if (j + k*a[i] <= x) dp[j + k*a[i]] = true;
      }
    }
  }

  if (dp[x]) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}