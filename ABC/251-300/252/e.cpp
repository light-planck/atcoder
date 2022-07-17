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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  // <to, cost, idx>
  vector<vector<tuple<ll, ll, ll>>> edge(n);
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    edge[a].emplace_back(b, c, i);
    edge[b].emplace_back(a, c, i);
  }

  constexpr ll inf = 1e18;
  vector<ll> dist(n, inf);
  dist[0] = 0;

  // <dist, v>
  priority_queue<P, vector<P>, greater<P>> heap;
  heap.emplace(dist[0], 0);

  vector<ll> idx(n);
  while (!heap.empty()) {
    auto [d, v] = heap.top();
    heap.pop();

    if (d > dist[v]) continue;

    for (auto [to, cost, i] : edge[v]) {
      if (dist[to] > dist[v] + cost) {
        dist[to] = dist[v] + cost;
        heap.emplace(dist[to], to);
        idx[to] = i;
      }
    }
  }

  for (ll i = 1; i < n; ++i) {
    cout << idx[i] + 1 << "\n";
  }
  return 0;
}