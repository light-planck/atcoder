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

  ll H, W, m;
  cin >> H >> W >> m;

  vector<ll> h(H), w(W);
  set<P> bomb;
  rep(_, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    ++h[a];
    ++w[b];
    bomb.emplace(a, b);
  }

  ll h_max = 0;
  rep(i, H) chmax(h_max, h[i]);
  set<ll> i_bomb;
  rep(i, H) {
    if (h[i] == h_max) i_bomb.emplace(i);
  }

  ll w_max = 0;
  rep(i, W) chmax(w_max, w[i]);
  set<ll> j_bomb;
  rep(i, W) {
    if (w[i] == w_max) j_bomb.emplace(i);
  }

  ll ans = h_max + w_max;
  for (auto i : i_bomb) {
    for (auto j : j_bomb) {
      if (not bomb.count({i, j})) {
        cout << ans << "\n";
        return 0;
      }
    }
  }

  cout << ans-1 << "\n";
  return 0;
}