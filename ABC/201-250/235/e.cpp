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
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m, q;
  cin >> n >> m >> q;

  // <cost, u, v, idx>
  vector<tuple<ll, ll, ll, ll>> edge;
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    edge.emplace_back(c, a, b, -1);
  }
  rep(i, q) {
    ll u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    edge.emplace_back(w, u, v, i);
  }
  sort(rng(edge));

  vector<bool> ans(q);
  dsu uf(n);

  for (auto [cost, u, v, idx] : edge) {

    // 辺がeiのとき
    if (idx != -1) {
      if (!uf.same(u, v)) {

        // Gにeiは追加しない
        // uf.merge(u, v);
        
        ans[idx] = true;
      }
    }

    // Gの辺のとき
    else {
      if (!uf.same(u, v)) {
        uf.merge(u, v);
      }
    }
  }

  rep(i, q) {
    if (ans[i]) cout << "Yes" << "\n";
    else cout << "No" << "\n";
  }
  return 0;
}