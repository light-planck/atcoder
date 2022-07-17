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
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector dp(h, vector<mint>(w));
  dp[0][0] = 1;

  vector x(h, vector<mint>(w));
  vector y(h, vector<mint>(w));
  vector z(h, vector<mint>(w));

  rep(i, h) rep(j, w) {
    if (i == 0 and j == 0) continue;
    if (s[i][j] == '#') continue;

    if (j - 1 >= 0) x[i][j] = x[i][j - 1] + dp[i][j - 1];
    if (i - 1 >= 0) y[i][j] = y[i - 1][j] + dp[i - 1][j];
    if (i-1 >= 0 and j-1 >= 0) z[i][j] = z[i - 1][j - 1] + dp[i - 1][j - 1];

    dp[i][j] = x[i][j] + y[i][j] + z[i][j];
  }

  cout << dp[h - 1][w - 1].val() << "\n";
  return 0;
}