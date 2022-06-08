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

  // <to, cost>
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

    for (auto e : edge[i]) heap.emplace(e.second, e.first);

    while (!heap.empty()) {
      auto [d, v] = heap.top(); heap.pop();

      if (dist[v] <= d) continue;

      dist[v] = d;
      for (auto e : edge[v]) heap.emplace(d+e.second, e.first);
    }

    ll ans = dist[i];
    if (ans == inf) ans = -1;
    cout << ans << "\n";
  }
  return 0;
}