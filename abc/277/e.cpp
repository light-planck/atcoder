#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector edge(2*n, vector<pair<ll, ll>>());
  rep(_, m) {
    ll u, v, a;
    cin >> u >> v >> a;
    --u; --v;

    if (a == 0) {
      edge[u+n].emplace_back(v+n, 1);
      edge[v+n].emplace_back(u+n, 1);
    }
    else {
      edge[u].emplace_back(v, 1);
      edge[v].emplace_back(u, 1);
    }
  }

  rep(_, k) {
    ll u;
    cin >> u;
    --u;
    edge[u].emplace_back(u+n, 0);
    edge[u+n].emplace_back(u, 0);
  }

  constexpr ll inf = 1e12;
  vector<ll> dist(2*n, inf);
  dist[0] = 0;

  deque<ll> deq;
  deq.emplace_back(0);
  while (not deq.empty()) {
    ll v = deq.front(); deq.pop_front();

    for (auto [to, cost] : edge[v]) {
      if (dist[to] > dist[v]+cost) {
        dist[to] = dist[v] + cost;
        if (cost == 0) deq.emplace_front(to);
        else deq.emplace_back(to);
      }
    }
  }

  ll ans = min(dist[n-1], dist[2*n-1]);
  if (ans == inf) ans = -1;
  cout << ans << '\n';
  return 0;
}