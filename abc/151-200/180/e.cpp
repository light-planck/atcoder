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

  ll n;
  cin >> n;

  vector<ll> x(n), y(n), z(n);
  rep(i, n) cin >> x[i] >> y[i] >> z[i];

  ll n2 = 1 << n;
  constexpr ll inf = 9e18;
  vector dp(n2, vector<ll>(n, inf));
  dp[0][0] = 0;

  vector dist(n, vector<ll>(n));
  rep(i, n) rep(j, n) {
    ll d = abs(x[j]-x[i]) + abs(y[j]-y[i]) + max(0LL, z[j]-z[i]);
    dist[i][j] = d;
  }
  rep(j, n) dp[1 << j][j] = dist[0][j];
  dist[0][0] = 0;

  rep(i, n2) rep(j, n) rep(k, n) {

    // j -> k
    // 部分集合iにjが含まれていない場合はスキップ
    if (not (i & (1<<j))) continue;

    // 部分集合iにkが含まれている場合はスキップ
    if (i & (1<<k)) continue;

    chmin(dp[i | (1<<k)][k], dp[i][j]+dist[j][k]);
  }

  cout << dp[n2 - 1][0] << "\n";
  return 0;
}