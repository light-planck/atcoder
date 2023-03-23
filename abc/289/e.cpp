#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


void solve() {
  ll n, m;
  cin >> n >> m;

  vector<ll> c(n);
  rep(i, n) cin >> c[i];

  vector edge(n, vector<ll>());
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  constexpr ll inf = 1ll << 60;
  vector dist(n, vector<ll>(n, inf));

  queue<pair<ll, ll>> que;
  auto push = [&](ll a, ll b, ll d) {
    if (dist[a][b] != inf) return;
    dist[a][b] = d;
    que.emplace(a, b);
  };
  push(0, n-1, 0);

  while (not que.empty()) {
    auto [a, b] = que.front(); que.pop();
    ll d = dist[a][b];

    for (auto na : edge[a]) {
      for (auto nb : edge[b]) {
        if (c[na] == c[nb]) continue;
        push(na, nb, d+1);
      }
    }
  }

  if (dist[n-1][0] == inf) cout << -1 << '\n';
  else cout << dist[n-1][0] << '\n';
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t;
  cin >> t;

  while (t--) solve();
  return 0;
}