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

  ll h, w, a, b;
  cin >> h >> w >> a >> b;

  vector<vector<bool>> seen(h, vector<bool>(w));
  ll ans = 0;


  // func
  auto dfs = [&](auto dfs, ll i, ll j, ll x, ll y) -> void {
    if (x < 0 || y < 0) return;

    if (j == w) {
      ++i;
      j = 0;
    }

    if (i == h) {
      ++ans;
      return;
    }

    // スキップ
    if (seen[i][j]) {
      dfs(dfs, i, j+1, x, y);
      return;
    }

    seen[i][j] = true;

    // 半畳
    dfs(dfs, i, j+1, x, y-1);

    // 1畳
    // 右
    if (j+1 < w && !seen[i][j + 1]) {
      seen[i][j + 1] = true;
      dfs(dfs, i, j+1, x-1, y);
      seen[i][j + 1] = false;
    }
    // 下
    if (i+1 < h && !seen[i + 1][j]) {
      seen[i + 1][j] = true;
      dfs(dfs, i, j+1, x-1, y);
      seen[i + 1][j] = false;
    }

    seen[i][j] = false;
  };
  dfs(dfs, 0, 0, a, b);


  cout << ans << "\n";
  return 0;
}