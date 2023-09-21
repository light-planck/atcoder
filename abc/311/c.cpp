#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector edge(N, vector<ll>());
  rep(i, N) {
    ll a;
    cin >> a;
    --a;
    edge[i].emplace_back(a);
  }

  vector<bool> seen(N);

  auto dfs = [&](auto self, ll v, vector<ll> path) -> void {
    if (ssize(path) > 1 and v == path[0]) {
      cout << ssize(path) << '\n';
      for (auto x : path) cout << x + 1 << '\n';
      exit(0);
    }

    for (auto to : edge[v]) {
      auto new_path = path;
      path.emplace_back(to);
      self(self, to, new_path);
    }

    path.pop_back();
    seen[v] = true;
  };

  rep(i, N) {
    if (not seen[i]) dfs(dfs, i, {i});
  }
}
