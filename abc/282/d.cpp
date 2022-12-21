#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> edge(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  vector<ll> colors(n, -1);
  auto dfs = [&](auto dfs, ll v, ll color) -> pair<ll, ll> {
    colors[v] = color;

    auto [black, white] = make_pair(0ll, 0ll);
    if (color == 1) ++black;
    else ++white;

    for (auto to : edge[v]) {
      if (colors[to] == (color^1)) continue;
      if (colors[to] == color) {
        cout << 0 << '\n';
        exit(0);
      }

      auto [b, w] = dfs(dfs, to, (color^1));
      black += b; white += w;
    }

    return make_pair(black, white);
  };

  ll ans = n*(n-1)/2 - m;
  rep(i, n) {
    if (colors[i] != -1) continue;

    auto [black, white] = dfs(dfs, i, 0);
    ans -= black * (black-1) / 2;
    ans -= white * (white-1) / 2;
  }

  cout << ans << '\n';
  return 0;
}