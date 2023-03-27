#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<pair<ll, ll>> edge;
  vector graph(n, vector<ll>());
  rep(i, n-1) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    edge.emplace_back(a, b);
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  vector par(n, 0ll);
  vector add(n, 0ll);

  auto dfs = [&](auto self, ll v, ll p=-1) -> void {
    par[v] = p;
    if (p != -1) add[v] += add[p];

    for (auto to : graph[v]) {
      if (to == p) continue;
      self(self, to, v);
    }
  };

  // 根付き木にする（parentの設定）
  dfs(dfs, 0);
  ll add_all = 0;

  ll q;
  cin >> q;

  while (q--) {
    ll t, e, x;
    cin >> t >> e >> x;
    --e;
    const auto [a, b] = edge[e];

    if (t == 1) {
      if (par[b] == a) {
        add_all += x;
        add[b] -= x;
      }
      else add[a] += x;
    }
    if (t == 2) {
      if (par[b] == a) add[b] += x;
      else {
        add_all += x;
        add[a] -= x;
      }
    }
  }

  // 累積和をとる
  dfs(dfs, 0);

  for (auto x : add) cout << x+add_all << '\n';
  return 0;
}