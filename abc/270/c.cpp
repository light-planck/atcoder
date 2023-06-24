#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n, x, y;
  cin >> n >> x >> y;
  --x;
  --y;

  vector edge(n, vector<ll>());
  rep(i, n - 1) {
    ll u, v;
    cin >> u >> v;
    --u;
    --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  vector<ll> path;

  auto dfs = [&](auto self, ll v, ll p = -1) -> void {
    path.emplace_back(v);

    if (v == y) {
      for (auto v : path)
        cout << v + 1 << ' ';
      cout << '\n';
      return;
    }

    for (auto to : edge[v]) {
      if (to == p)
        continue;

      self(self, to, v);
    }
    path.pop_back();
  };
  dfs(dfs, x);
  return 0;
}
