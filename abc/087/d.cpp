#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  // <v, to, cost>
  vector edge(n, vector<pair<ll, ll>>());
  rep(i, m) {
    ll l, r, d;
    cin >> l >> r >> d;
    --l; --r;
    edge[l].emplace_back(r, d);
    edge[r].emplace_back(l, -d);
  }

  vector<ll> x(n, -1);
  vector<bool> seen(n);
  rep(i, n) {
    if (seen[i]) continue;
    x[i] = 0;

    auto dfs = [&](auto dfs, ll v) -> void {
      seen[v] = true;

      for (auto [to, d] : edge[v]) {
        if (seen[to]) {
          if (x[to]-x[v] != d) {
            cout << "No" << '\n';
            exit(0);
          }
        }
        else {
          x[to] = x[v] + d;
          dfs(dfs, to);
        }
      }
    };

    dfs(dfs, i);
  }

  cout << "Yes" << '\n';
  return 0;
}