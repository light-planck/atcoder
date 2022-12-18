#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> edge(n);
  dsu uf(n);

  // <leader, edge>
  map<ll, ll> graph;

  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  vector<ll> colors(n);

  auto dfs = [&](auto dfs, ll v, ll c) -> bool {
    colors[v] = c;
    for (auto to : edge[v]) {
      if (colors[to] == c) return false;
      if (colors[to] == 0 and not dfs(dfs, to, -c)) return false;
    }
    return true;
  };

  auto is_partial = [&]() {
    return dfs(dfs, 0, 1);
  };

  if (is_partial()) {
    ll b = accumulate(colors.begin(), colors.end(), 0) + n;
    b /= 2;
    ll w = n-b;
    cout << b*w - m << '\n';
  }
  else {
    cout << 0 << '\n';
  }
  return 0;
}