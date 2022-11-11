#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };

  ll n, a, b, c;
  cin >> n >> a >> b >> c;

  vector<ll> l(n);
  rep(i, n) cin >> l[i];

  ll ans = 9e18;
  auto dfs = [&](auto dfs, ll i, ll cost, ll x, ll y, ll z) -> void {
    if (i == n) {
      if (x == 0 or y == 0 or z == 0) return;

      ll now = cost + abs(x-a) + abs(y-b) + abs(z-c);
      chmin(ans, now);
      return;
    }

    dfs(dfs, i+1, cost, x, y, z);

    ll ncost = cost;
    if (x > 0) ncost += 10;
    dfs(dfs, i+1, ncost, x+l[i], y, z);

    ncost = cost;
    if (y > 0) ncost += 10;
    dfs(dfs, i+1, ncost, x, y+l[i], z);

    ncost = cost;
    if (z > 0) ncost += 10;
    dfs(dfs, i+1, ncost, x, y, z+l[i]);
  };
  dfs(dfs, 0, 0, 0, 0, 0);

  cout << ans << '\n';
  return 0;
}