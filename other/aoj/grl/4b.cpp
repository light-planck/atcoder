#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector edge(n, vector<ll>());
  rep(i, m) {
    ll s, t;
    cin >> s >> t;
    edge[s].emplace_back(t);
  }

  vector<bool> seen(n);
  vector<ll> ans;
  auto dfs = [&](auto dfs, ll v) -> void {
    seen[v] = true;
    for (auto to : edge[v]) {
      if (seen[to]) continue;
      dfs(dfs, to);
    }
    ans.emplace_back(v);
  };

  rep(i, n) {
    if (seen[i]) continue;
    dfs(dfs, i);
  }

  reverse(ans.begin(), ans.end());
  for (auto v : ans) cout << v << ' ';
  cout << '\n';
  return 0;
}