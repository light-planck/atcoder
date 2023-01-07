#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector edge(n, vector<ll>());
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  ll limit = 1e6;
  ll ans = 0;

  vector<bool> seen(n);
  auto dfs = [&](auto dfs, ll v) -> void {
    if (ans == limit) return;

    seen[v] = true;
    ++ans;

    for (auto to : edge[v]) {
      if (seen[to]) continue;
      dfs(dfs, to);
    }

    seen[v] = false;
  };
  dfs(dfs, 0);

  cout << ans << '\n';
  return 0;
}