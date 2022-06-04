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


void dfs(ll i, ll bit, ll a, ll b) {
  if (i == h * w)
  if (a) {

  }
  if (b) {
    
  }
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h, w, a, b;
  cin >> h >> w >> a >> b;

  
  ll ans = 0;
  auto dfs = [&](auto dfs, ll i, ll bit, ll x, ll y) -> void {
    if (i == h*w) {
      ++ans;
      return 0;
    }

    // iのマスが既に埋まっている
    if (bit & (1 << i)) dfs(dfs, i+1, bit, x, y);

    // 1畳
    if (x) {
      // 横にはみ出る
      if (i % w < w) {
        dfs(dfs, i+1, bit + (i << w), x-1, y);
      }

      // 下にはみ出る
      if ((i << w) < h) {
        dfs(dfs, i+1, bit + (), x-1, y);
      }
    }

    // 半畳
    if (y) {
      dfs(dfs, i+1, bit + (1 << i), a, b-1);
    }
  };
  dfs(dfs, 0, 0, a, b);

  
  cout << ans << "\n";
  return 0;
}