#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector graph(n, vector<bool>(n));
  vector edge(n, vector<ll>());
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    graph[u][v] = true;
    edge[u].emplace_back(v);
  }

  ll ans = 0;

  auto merge = [&](auto merge, ll u, ll v) -> void {
    // cout << "merge u, v: " << u+1 << " " << v+1 << endl;
    ++ans;
    graph[u][v] = true;
    for (auto to : edge[v]) {
      if (not graph[u][to]) merge(merge, u, to);
    }
  };

  rep(i, n) {
    for (auto v : edge[i]) {
      if (i == v) continue;
      for (auto to : edge[v]) {
        if (v == to) continue;
        if (i == to) continue;

        if (not graph[i][to]) {
          merge(merge, i, to);
        }
      }
    }
  }

  cout << ans << '\n';
  return 0;
}