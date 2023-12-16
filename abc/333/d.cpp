#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector edge(N, vector<ll>());
  rep(i, N - 1) {
    ll u, v;
    cin >> u >> v;
    --u;
    --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  if (ssize(edge[0]) <= 1) {
    cout << 1 << '\n';
    exit(0);
  }

  vector<ll> sums;
  for (auto s : edge[0]) {
    ll sum = 0;

    auto dfs = [&](auto self, ll v, ll p) -> void {
      for (auto u : edge[v]) {
        if (u == p) continue;

        self(self, u, v);
      }

      ++sum;
    };

    dfs(dfs, s, 0);
    sums.emplace_back(sum);
  }

  cout << accumulate(sums.begin(), sums.end(), 0ll) -
              *ranges::max_element(sums) + 1
       << '\n';
}
