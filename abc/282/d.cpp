#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


// 二部グラフでないグラフは、どのように辺を結んでも二部グラフになることはない。
// ans = 0

// 二部グラフの場合は、異なる色の頂点を結ぶと、二部グラフのままになる。
// ans = (異なる色の頂点を結ぶ新たな辺の本数)
// = (任意の2頂点を結ぶ辺の本数) - (同じ色同士の頂点を結ぶ辺の本数) - (既に結んである辺の本数)


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

  vector<ll> colors(n, -1);

  auto dfs = [&](auto dfs, ll v, ll color) -> pair<ll, ll> {
    // <black, white>
    pair<ll, ll> cnt = {0, 0};
    colors[v] = color;

    if (color == 1) ++cnt.first;
    else ++cnt.second;

    for (auto to : edge[v]) {
      if (to == v) continue;
      if (colors[to] == (color^1)) continue;
      if (colors[to] == color) {
        cout << 0 << '\n';
        exit(0);
      }

      auto [black, white] = dfs(dfs, to, (color^1));
      cnt.first += black; cnt.second += white;
    }

    return cnt;
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