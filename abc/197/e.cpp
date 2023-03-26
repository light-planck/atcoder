#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  constexpr ll inf = 1ll << 60;
  vector lr(n, pair<ll, ll>(inf, -inf));
  rep(i, n) {
    ll x, c;
    cin >> x >> c;
    --c;
    auto& [l, r] = lr[c];
    l = min(l, x);
    r = max(r, x);
  }

  vector dp(2, 0ll);
  pair<ll, ll> prev_lr = {0, 0};
  rep(i, n) {
    const auto [l, r] = lr[i];

    if (l == inf) continue;

    vector prev(2, inf);
    swap(prev, dp);

    rep(j, 2) {
      ll x = 0;
      const auto [pl, pr] = prev_lr;
      if (j == 0) x = pl;
      else x = pr;

      dp[0] = min(dp[0], prev[j] + abs(x-r) + r-l);
      dp[1] = min(dp[1], prev[j] + abs(x-l) + r-l);
    }

    prev_lr = {l, r};
  }

  const auto [pl, pr] = prev_lr;
  dp[0] += abs(pl); dp[1] += abs(pr);
  cout << min(dp[0], dp[1]) << '\n';
  return 0;
}