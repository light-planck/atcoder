#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


// https://kyo-pro.hatenablog.com/entry/ABC237E


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  vector<vector<ll>> edge(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  constexpr ll inf = 1e18;
  vector<ll> dist(n, inf);
  dist[0] = 0;

  priority_queue<P, vector<P>, greater<P>> heap;
  heap.emplace(0, 0);

  while (!heap.empty()) {
    auto [d, v] = heap.top();
    heap.pop();

    if (dist[v] < d) continue;

    for (auto to : edge[v]) {
      ll new_d = d;

      if (h[to] > h[v]) new_d += h[to] - h[v];

      if (new_d < dist[to]) {
        dist[to] = new_d;
        heap.emplace(dist[to], to);
      }
    }
  }

  ll ans = 0;
  rep(i, n) {
    chmax(ans, -(dist[i] - h[0] + h[i]));
  }

  cout << ans << "\n";
  return 0;
}