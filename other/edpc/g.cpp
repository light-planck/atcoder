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
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> edge(n);
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    --x; --y;
    edge[x].emplace_back(y);
  }

  vector<ll> dp(n, -1);
  auto dfs = [&](auto dfs, ll v) -> ll {
    if (dp[v] != -1) return dp[v];

    ll res = 0;
    for (auto to : edge[v]) {
      auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
      chmax(res, dfs(dfs, to)+1);
    }

    return dp[v] = res;
  };

  ll ans = 0;
  rep(i, n) {
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    chmax(ans, dfs(dfs, i));
  }
  cout << ans << '\n';
  return 0;
}