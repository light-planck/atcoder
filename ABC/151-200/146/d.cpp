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


// struct Edge{
//   ll to, id;

//   Edge(ll to, ll id) : to(to), id(id) {};
// };


void print_vec1(string name, vector<ll> v) {
  cout << name << ": ";
  
  for (ll i = 0; i < (ll)v.size(); i++) {
    if (i) cout << " ";
    cout << v[i];
  }

  cout << "\n";
}


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

  vector<ll> ans(n - 1, 0);

  ll cnt = 0;
  vector<ll> tmp(1);


  auto dfs = [&](auto dfs, ll v, ll p, ll p_color) -> void {
    ++cnt;
    tmp[0] = cnt;
    // cout << "v: " << v << "\n";

    ll color = 1;
    if (color == p_color) ++color;

    for (auto u : edge[v]) {
      ll to = u.first;
      ll id = u.second;

      if (to == p) continue;

      // cout << "to: " << to << "\n";

      ans[id] == color;

      print_vec1("ans", ans);

      dfs(dfs, to, v, color);

      ++color;
      if (color == p_color) ++color;
    }
  };


  dfs(dfs, 0, -1, 0);

  // 最大次数
  ll k = 0;
  rep(i, n) chmax(k, (ll)edge[i].size());
  cout << k << "\n";

  // for (auto c : ans) cout << c << "\n";
  cout << tmp[0] << "\n";
  return 0;
}