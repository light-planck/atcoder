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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  using P = pair<ll, ll>;
  vector edge(n, vector<P>());
  rep(i, n-1) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    edge[a].emplace_back(b, c);
    edge[b].emplace_back(a, c);
  }

  ll q, k;
  cin >> q >> k;
  --k;

  constexpr ll inf = 9e18;
  vector<ll> dist(n, inf);
  dist[k] = 0;

  auto dfs = [&](auto dfs, ll v, ll p=-1) -> void {
    for (auto [to, c] : edge[v]) {
      if (to == p) continue;

      dist[to] = dist[v] + c;
      dfs(dfs, to, v);
    }
  };
  dfs(dfs, k);

  while (q--) {
    ll x, y;
    cin >> x >> y;
    --x; --y;
    cout << dist[x]+dist[y] << '\n';
  }
  return 0;
}