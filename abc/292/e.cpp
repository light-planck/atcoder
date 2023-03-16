#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector edge(n, vector<ll>());
  rep(_, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
  }

  ll ans = 0;
  rep(s, n) {
    vector<bool> visited(n);
    visited[s] = true;

    queue<ll> que;
    que.emplace(s);
    while (not que.empty()) {
      ll v = que.front(); que.pop();

      for (auto to : edge[v]) {
        if (visited[to]) continue;

        visited[to] = true;
        que.emplace(to);
        ++ans;
      }
    }
  }

  cout << ans-m << '\n';
  return 0;
}