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
      ll nd = s[i] - '0';
      ll next_cnt = cnt;
      ll next_is_less = is_less;

      if (not d == 0) ++next_cnt;
      if (next_cnt > k) continue;

      if (not is_less) {
        if (d > nd) continue;
        if (d < nd) next_is_less = true;
      }

      dp[i + 1][next_cnt][next_is_less] += dp[i][cnt][is_less];
    }
  }

  ll ans = dp[n][k][0] + dp[n][k][1];
  cout << ans << "\n";
  return 0;
}