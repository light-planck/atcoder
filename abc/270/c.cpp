#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, x, y;
  cin >> n >> x >> y;
  --x; --y;

  vector<vector<ll>> edge(n);
  rep(i, n-1) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  vector<ll> path = {x};

  auto dfs = [&](auto dfs, ll v, ll p) -> void {
    if (path.back() == y) {
      for (auto x : path) cout << x+1 << '\n';
      return;
    }

    if ((ll)path.size() == n) return;

    for (auto to : edge[v]) {
      if (to == p) continue;

      path.emplace_back(to);
      dfs(dfs, to, v);
      path.pop_back();
    }
  };
  // vector<ll> path = {x};
  dfs(dfs, x, -1);

  ll m = path.size();
  rep(i, m-1) cout << path[i] << '\n';
  return 0;
}