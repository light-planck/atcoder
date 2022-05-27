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


// https://note.com/momomo0214/n/n3795f9e2dc66
/*
逆から考える。右下→左上
点数 = 高橋 - 青木のスコア
dp[i][j]: (i, j)からゴールまでに獲得できる点数の総和
*/


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;

  vector<vector<ll>> a(h, vector<ll>(w));
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) {
      if (s[j] == '+') a[i][j] = 1;
      else a[i][j] = -1;
    }
  }

  // dp[i][j]: マス(i, j)からゴールまでに最適な行動を取ったときに得られる点数
  vector<vector<ll>> dp(h, vector<ll>(w));
  constexpr ll inf = 1e18;
  for (ll i = h-1; i >= 0; i--) {
    for (ll j = w-1; j >= 0; j--) {
      if (i == h-1 and j == w-1) continue;

      bool takahashi = (i+j) % 2 == 0;

      // 右に移動
      ll left;
      // 範囲外のとき
      if (j + 1 >= w) {
        if (takahashi) left = -inf;
        else left = inf;
      }
      // 範囲内
      else {
        left = dp[i][j + 1];
        if (takahashi) left += a[i][j + 1];
        else left -= a[i][j + 1];
      }

      // 下に移動
      ll down;
      // 範囲外
      if (i + 1 >= h) {
        if (takahashi) down = -inf;
        else down = inf;
      }
      else {
        down = dp[i + 1][j];
        if (takahashi) down += a[i + 1][j];
        else down -= a[i + 1][j];
      }

      // 更新
      if (takahashi) dp[i][j] = max(left, down);
      else dp[i][j] = min(left, down);
    }
  }

  if (dp[0][0] > 0) cout << "Takahashi" << "\n";
  else if (dp[0][0] < 0) cout << "Aoki" << "\n";
  else cout << "Draw" << "\n";
  return 0;
}