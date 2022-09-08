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

  auto dijkstra = [&]() {
    constexpr ll inf = 9e18;
    vector<ll> dist(n, inf);
    dist[k] = 0;

    priority_queue<P, vector<P>> heap;
    heap.emplace(dist[k], k);

    while (not heap.empty()) {
      auto [d, v] = heap.top(); heap.pop();

      if (dist[v] < d) continue;

      for (auto [to, c] : edge[v]) {
        if (dist[to] > dist[v] + c) {
          dist[to] = dist[v] + c;
          heap.emplace(dist[to], to);
        }
      }
    }

    return dist;
  };

  auto dist = dijkstra();
  while (q--) {
    ll x, y;
    cin >> x >> y;
    --x; --y;
    cout << dist[x]+dist[y] << '\n';
  }
  return 0;
}