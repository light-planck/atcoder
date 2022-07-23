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

  ll n, m;
  cin >> n >> m;

  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  vector<ll> c(m), y(m);
  rep(i, m) cin >> c[i] >> y[i];

  map<ll ,ll> mp;
  rep(i, m) chmax(mp[c[i]], y[i]);

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
  // dp[1][1] = x[0];

  for (ll i = 0; i < n; ++i) {
    rep(j, i+1) {
      // 裏
      chmax(dp[i + 1][0], dp[i][j]);

      // 表
      ll ndp = dp[i][j] + x[i];
      if (j + 1 <= n) {
        if (mp.count(j + 1)) ndp += mp[j + 1];

        chmax(dp[i + 1][j + 1], ndp);
      }
    }
  }

  ll ans = 0;
  rep(j, n+1) chmax(ans, dp[n][j]);
  cout << ans << "\n";
  return 0;
}