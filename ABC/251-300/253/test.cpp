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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m, k;
  cin >> n >> m >> k;

  if (k == 0) {
    mint ans = mint(m).pow(n);
    cout << ans.val() << "\n";
    return 0;
  }

  vector<vector<mint>> dp(n+1, vector<mint>(m + 1));
  rep(j, m+1) dp[1][j] = 1;
  // dp[0][0] = 0;

  for (ll i = 1; i < n; ++i) {
    vector<mint> s(m + 1);
    for (ll j = 0; j < m; ++j) s[j + 1] = s[j] + dp[i][j+1];

    auto sum = [&](ll l, ll r) -> mint {
      if (l > r) return 0;
      return s[r + 1] - s[l];
    };

    for (ll j = 1; j <= m; ++j) {
      ll l = max(1LL, j-k+1);
      ll r = min(m, j+k-1);
      dp[i + 1][j] = s.back() - (s[r] - s[l - 1]);
    }
  }

  // mint ans = 0;
  // for (ll j = 1; j <= m; ++j) ans += dp[n][j];
  // cout << ans.val() << "\n";

  rep(i, n+1) {
    rep(j, m+1) {
      cout << dp[i][j].val() << " ";
    }

    cout << "\n";
  }
  return 0;
}