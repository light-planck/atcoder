#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector edge(N, vector<ll>());
  rep(i, M) {
    ll a, b;
    cin >> a >> b;
    --a;
    --b;
    edge[a].emplace_back(b);
  }

  rep(i, N) {
    vector<bool> seen(N);

    auto dfs = [&](auto self, ll v) -> void {
      seen[v] = true;

      for (auto to : edge[v]) {
        if (seen[to]) continue;
        self(self, to);
      }
    };
    dfs(dfs, i);

    bool ok = true;
    rep(j, N) {
      if (!seen[j]) ok = false;
    }
    if (not ok) continue;

    if (ok) {
      cout << i + 1 << '\n';
      exit(0);
    }
  }

  cout << -1 << '\n';
}
