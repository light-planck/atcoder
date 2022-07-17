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
#include <string>
#include <stack>
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

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  constexpr ll inf = 1e18;

  // dp[i][j]: 行動i(0 <= i < n)をjかい行った場合のコストの最小値
  vector dp = vector(n + 1, vector<ll>(2, inf));

  // 行動0をしない場合
  dp[1][0] = 0;
  for (ll i = 1; i < n; ++i) {

    // 行動iを行わない場合、行動i-1を行っている必要がある
    dp[i + 1][0] = dp[i][1];

    // 行う場合
    dp[i + 1][1] = min(dp[i][0], dp[i][1]) + a[i];
  }
  ll ans = dp[n][1];

  // 行動0をする場合
  dp = vector(n + 1, vector<ll>(2, inf));
  dp[1][1] = a[0];
  for (ll i = 1; i < n; ++i) {
    dp[i + 1][0] = dp[i][1];

    dp[i + 1][1] = min(dp[i][0], dp[i][1]) + a[i];
  }
  chmin(ans, min(dp[n][0], dp[n][1]));

  cout << ans << "\n";
  return 0;
}