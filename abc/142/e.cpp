#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector a(m, 0ll);
  vector bit(m, 0ll);
  rep(i, m) {
    ll b;
    cin >> a[i] >> b;
    rep(j, b) {
      ll c;
      cin >> c;
      --c;
      bit[i] |= 1ll << c;
    }
  }

  constexpr ll inf = 1ll << 60;
  vector dp(2, vector<ll>(1ll<<n, inf));
  dp[0][0] = 0; 

  rep(i, m) {
    vector prev(2, vector<ll>(1ll<<n, inf));
    swap(prev, dp);

    rep(j, 1ll<<n) {
      rep(k, 2) {
        if (prev[k][j] == inf) continue;
        dp[0][j] = min(dp[0][j], prev[k][j]);
        dp[1][j | bit[i]] = min(dp[1][j | bit[i]], prev[k][j] + a[i]);
      }
    }
  }

  ll idx = (1ll<<n) - 1;
  ll ans = min(dp[0][idx], dp[1][idx]);
  if (ans == inf) ans = -1;
  cout << ans << '\n';
  return 0;
}