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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  dsu uf(n);
  vector<P> edge;
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge.emplace_back(u, v);
    uf.merge(u, v);
  }

  // <leader, num_edge>
  vector<ll> num_edge(n);
  for (auto [u, v] : edge) {
    ++num_edge[uf.leader(u)];
  }

  vector<ll> num_vertices(n);
  rep(i, n) {
    ++num_vertices[uf.leader(i)];
  }

  mint ans = 1;
  rep(i, n) {
    ll e = num_edge[i];
    ll v = num_vertices[i];
    
    if (v == 0) continue;

    if (e == v) ans *= 2;
    else ans = 0;
  }

  cout << ans.val() << "\n";
  return 0;
}