#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
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

  vector<vector<P>> edge(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    edge[a].emplace_back(b, i);
    edge[b].emplace_back(a, i);
  }

  vector<ll> edge_color(n - 1);


  auto dfs = [&](auto dfs, ll v, ll p=-1, ll p_color=0) -> void {
    ll color = 1;
    if (color == p_color) ++color;

    for (auto nv : edge[v]) {
      ll to = nv.first;
      ll id = nv.second;

      if (to == p) continue;

      if (color == p_color) ++color;
      edge_color[id] = color;

      dfs(dfs, to, v, color);
      
      ++color;
    }
  };
  dfs(dfs, 0);


  // 最大次数
  ll k = 0;
  rep(i, n) chmax(k, (ll)edge[i].size());
  cout << k << "\n";

  for (auto c : edge_color) cout << c << "\n";
  return 0;
}