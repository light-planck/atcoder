#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, c;
  cin >> n >> c;

  vector d(c, vector<ll>(c));
  rep(i, c) rep(j, c) cin >> d[i][j];

  vector color(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> color[i][j], --color[i][j];

  // cost[(i+j) % 3][c] : (i+j) % 3をすべて色kにするのに必要なコスト
  vector cost(3, vector<ll>(c));
  rep(i, n) rep(j, n) {
    rep(k, c) {
      cost[(i+j) % 3][k] += d[color[i][j]][k];
    }
  }

  ll ans = 1ll << 60;
  rep(c0, c) rep(c1, c) rep(c2, c) {
    if (c0 == c1 or c1 == c2 or c2 == c0) continue;

    ll tmp = cost[0][c0] + cost[1][c1] + cost[2][c2];

    auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
    chmin(ans, tmp);
  }

  cout << ans << '\n';
  return 0;
}