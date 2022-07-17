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

  ll n;
  cin >> n;

  //edge[i] = <to, cost>
  vector<vector<P>> edge(n);
  rep(i, n-1) {
    ll u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w);
  }

  vector<ll> ans(n);


  // dfs(v, color, parent)
  auto dfs = [&](auto dfs, ll v, ll color, ll parent=-1) -> void {
    ans[v] = color;

    for (auto [to, w] : edge[v]) {
      if (to == parent) continue;

      if (w % 2 == 1) dfs(dfs, to, 1-color, v);
      else dfs(dfs, to, color, v);
    }
  };
  dfs(dfs, 0, 0);


  for (auto v : ans) cout << v << "\n";
  return 0;
}