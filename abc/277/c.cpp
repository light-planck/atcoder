#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  auto chmax = [](auto& a, auto b) { if (a < b) a = b; };

  ll n;
  cin >> n;

  map<ll, vector<ll>> edge;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  map<ll, bool> seen;

  ll ans = -1;
  auto dfs = [&](auto dfs, ll v, ll p=-1) -> void {
    if (seen[v]) return;

    seen[v] = true;
    chmax(ans, v);

    if (edge[v].size() > 0) {
      for (auto to : edge[v]) {
        if (to == p) continue;
        dfs(dfs, to, v);
      }
    }
  };
  dfs(dfs, 0);

  cout << ans+1 << '\n';
  return 0;
}