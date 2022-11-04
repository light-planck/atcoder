#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> edge(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  vector<ll> dist(n, -1);
  dist[0] = 0;

  deque<ll> que;
  que.emplace_back(0);

  while (not que.empty()) {
    ll v = que.front(); que.pop_front();
    if (dist[v] == 2) continue;

    for (auto to : edge[v]) {
      if (dist[to] != -1) continue;
      que.emplace_back(to);
      dist[to] = dist[v] + 1;
    }
  }

  if (dist[n-1] >= 0) cout << "POSSIBLE" << '\n';
  else cout << "IMPOSSIBLE" << '\n';
  return 0;
}