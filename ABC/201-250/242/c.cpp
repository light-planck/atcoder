#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


const int MOD = 998244353;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<vector<ll>> dp(n + 1, vector<ll>(10));
  rep(j, 10) dp[1][j] = 1;

  for (ll i = 0; i < n; ++i) {
    for (ll j = 1; j <= 9; ++j) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;

      if (j - 1 >= 1) {
        dp[i + 1][j] += dp[i][j - 1];
        dp[i + 1][j] %= MOD;
      }
      if (j + 1 <= 9) {
        dp[i + 1][j] += dp[i][j + 1];
        dp[i + 1][j] %= MOD;
      }
    }
  }

  ll ans = 0;
  rep(j, 10) {
    ans += dp[n][j];
    ans %= MOD;
  }
  cout << ans << "\n";
  return 0;
}