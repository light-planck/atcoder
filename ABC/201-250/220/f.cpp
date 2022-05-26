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

  ll n;
  cin >> n;

  vector<vector<ll>> edge(n);
  rep(i, n-1) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }


  // 各頂点の部分木のサイズ
  vector<ll> sub_size(n, 1);
  auto dfs1 = [&](auto dfs1, ll v, ll p=-1) -> void {
    for (auto to : edge[v]) {
      if (to == p) continue;

      dfs1(dfs1, to, v);

      sub_size[v] += sub_size[to];
    }
  };
  dfs1(dfs1, 0);


  // ans[0]を求める
  vector<ll> ans(n);
  auto dfs2 = [&](auto dfs2, ll v, ll d, ll p=-1) -> void {
    ans[0] += d;

    for (auto to : edge[v]) {
      if (to == p) continue;

      dfs2(dfs2, to, d+1, v);
    }
  };
  dfs2(dfs2, 0, 0);


  // ansを順に計算する
  auto dfs3 = [&](auto dfs3, ll v, ll p=-1) -> void {
    for (auto to : edge[v]) {
      if (to == p) continue;

      ans[to] = ans[v] + n - 2*sub_size[to];
      dfs3(dfs3, to, v);
    }
  };
  dfs3(dfs3, 0);


  for (auto x : ans) cout << x << "\n";
  return 0;
}