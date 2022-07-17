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

  vector<vector<P>> edge(n);
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    edge[a].emplace_back(b, c);
  }

  constexpr ll inf = 1e18;
  rep(i, n) {
    vector<ll> dist(n, inf);
    priority_queue<P, vector<P>, greater<P>> heap;

    // 頂点iに隣接する頂点を追加
    for (auto e : edge[i]) {
      ll to = e.first;
      ll cost = e.second;
      heap.emplace(cost, to);
    }

    while (!heap.empty()) {
      auto [d, v] = heap.top(); heap.pop();

      if (dist[v] <= d) continue;

      dist[v] = d;
      
      for (auto e : edge[v]) {
        ll to = e.first;
        ll cost = e.second;
        heap.emplace(d+cost, to);
      }
    }

    if (dist[i] == inf) cout << -1 << "\n";
    else cout << dist[i] << "\n";
  }
  return 0;
}