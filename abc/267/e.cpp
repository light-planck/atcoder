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

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<ll>> edge(n);
  vector<ll> cost(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
    cost[u] += a[v];
    cost[v] += a[u];
  }

  using P = pair<ll, ll>;
  priority_queue<P, vector<P>, greater<P>> heap;
  rep(i, n) heap.emplace(cost[i], i);

  vector<ll> seen(n);
  ll ans = 0;

  while (not heap.empty()) {
    auto [c, v] = heap.top(); heap.pop();
    if (seen[v]) continue;

    seen[v] = true;
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    chmax(ans, c);

    for (auto to : edge[v]) {
      cost[to] -= a[v];
      heap.emplace(cost[to], to);
    }
  }

  cout << ans << '\n';
  return 0;
}