#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector graph(n, vector<ll>());
  set<pair<ll, ll>> edge;
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    --x; --y;
    graph[x].emplace_back(y);
    edge.emplace(x, y);
  }

  vector<ll> idx;
  vector<bool> seen(n);
  auto dfs = [&](auto dfs, ll v) -> void {
    seen[v] = true;
    for (auto to : graph[v]) {
      if (seen[to]) continue;
      dfs(dfs, to);
    }
    idx.emplace_back(v);
  };

  rep(i, n) {
    if (seen[i]) continue;
    dfs(dfs, i);
  }
  reverse(idx.begin(), idx.end());

  rep(i, n-1) {
    if (not edge.count({idx[i], idx[i+1]})) {
      cout << "No" << '\n';
      return 0;
    }
  }

  vector<ll> ans(n);
  rep(i, n) ans[idx[i]] = i + 1;

  cout << "Yes" << '\n';
  for (auto v : ans) cout << v << ' ';
  cout << '\n';
  return 0;
}