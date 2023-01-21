#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector edge(n, vector<ll>());
  rep(i, n) rep(j, n) {
    if (s[i][j] == 'Y') edge[i].emplace_back(j);
  }

  constexpr ll inf = 1ll << 60;
  vector value(n, vector<ll>(n, inf));
  vector path(n, vector<ll>(n));

  rep(i, n) {
    vector<ll> dist(n, -1);
    dist[i] = 0;

    deque<ll> que;
    que.emplace_back(i);
    while (not que.empty()) {
      ll v = que.front(); que.pop_front();

      for (auto to : edge[v]) {
        if (dist[to] != -1) continue;

        que.push_back(to);
        ++dist[to];
      }
    }
  }

  ll q;
  cin >> q;

  while (q--) {
    ll u, v;
    cin >> u >> v;
    --u; --v;

    if (dist[u][v] == inf) cout << "Impossible" << '\n';
    else cout << path[u][v] << " " << -dist[u][v] << '\n';
  }
  return 0;
}