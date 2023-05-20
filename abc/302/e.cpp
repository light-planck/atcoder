#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;

  ll ans = n;
  vector edge(n, set<ll>());
  rep(i, q) {
    ll t;
    cin >> t;

    if (t == 1) {
      ll u, v;
      cin >> u >> v;
      --u; --v;

      if (edge[u].empty()) --ans;
      edge[u].emplace(v);
      if (edge[v].empty()) --ans;
      edge[v].emplace(u);
    }

    if (t == 2) {
      ll v;
      cin >> v;
      --v;

      for (auto to : edge[v]) {
        if (edge[to].size() == 1) ++ans;
        edge[to].erase(v);
      }

      if (not edge[v].empty()) ++ans;
      edge[v].clear();
    }

    cout << ans << '\n';
  }
  return 0;
}