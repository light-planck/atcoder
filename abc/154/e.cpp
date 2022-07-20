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


// dp[i][j][l]: i番目まで決めたとき、0でない数字がj個であるときの場合の数。
// ただし、その数がn以下であるかどうか確定しているか(l = false or true)の情報を持つ。
ll dp[101][4][2];


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  ll k;
  cin >> k;

  ll n = s.size();
  dp[0][0][0] = 1;

  rep(i, n) rep(cnt, 4) rep(is_less, 2) {
    rep(d, 10) {
      ll si = s[i] - '0';
      ll next_cnt = cnt;
      ll next_is_less = is_less;

      // 0でない数字をカウントし、kを超えたらスキップ
      if (not d == 0) ++next_cnt;
      if (next_cnt > k) continue;

      // n以下が確定している場合、その後もn以下であるので
      // n以下であるか不明の場合のみを考える。
      if (not is_less) {

        // nより大きくなる場合はスキップ
        if (d > si) continue;

        // nより小さくなる場合はis_less = true
        if (d < si) next_is_less = true;

        // d == siの場合は現時点ではn以下になることが保証されない
      }

      dp[i + 1][next_cnt][next_is_less] += dp[i][cnt][is_less];
    }
  }

  ll ans = dp[n][k][0] + dp[n][k][1];
  cout << ans << "\n";
  return 0;
}