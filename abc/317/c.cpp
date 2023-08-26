#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector edge(N, vector<pair<ll, ll>>());
  rep(i, M) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    edge[a].emplace_back(b, c);
    edge[b].emplace_back(a, c);
  }

  ll ans = 0;
  vector<bool> seen(N);

  rep(i, N) {
    if (seen[i]) continue;

    ll max_cost = 0;

    auto dfs = [&](auto self, ll v, ll cost) -> void {
      seen[v] = true;

      max_cost = max(max_cost, cost);

      for (auto [to, c] : edge[v]) {
        if (seen[to]) continue;
        self(self, to, cost + c);
      }

      seen[v] = false;
    };

    dfs(dfs, i, 0);
    ans = max(ans, max_cost);
  }

  cout << ans << '\n';
}
