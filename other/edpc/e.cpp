#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, cap;
  cin >> n >> cap;

  vector<ll> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];

  // dp[i][j] i番目の品物まで見たときの価値の総和がjのときの重さの最小値
  ll max_v = 1e5;
  constexpr ll inf = 9e18;
  vector<ll> dp(max_v+1, inf);
  dp[0] = 0;

  rep(i, n) {
    vector<ll> prev(max_v+1, inf);
    swap(prev, dp);

    for (ll j = 0; j <= max_v; ++j) {
      auto chmin = [](auto& a, auto b) { if (a > b) a = b; };

      chmin(dp[j], prev[j]);
      if (j+v[i] <= max_v) chmin(dp[j+v[i]], prev[j]+w[i]);
    }
  }

  ll ans = 0;
  for (ll i = max_v; i >= 0; --i) {
    if (dp[i] <= cap) {
      ans = i;
      break;
    }
  }

  cout << ans << '\n';
  return 0;
}