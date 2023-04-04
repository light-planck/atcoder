#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;


bool ok(ll bit) {
  rep(i, 6) {
    bool a = false;
    if (bit & (1ll<<i)) a = true;
    bool b = false;
    if (bit & (1ll<<(i+1))) b = true;
    if (a and b) return false;
  }
  return true;
}


int main() {
  ll h, w, k;
  cin >> h >> w >> k;
  
  vector dp(h+1, vector<mint>(w));
  dp[0][0] = 1;

  rep(i, h) {
    rep(j, w) {
      if (dp[i][j] == 0) continue;

      for (ll bit = 0; bit < (1ll<<(w-1)); ++bit) {
        if (not ok(bit)) continue;

        if (j-1 >= 0 and (bit & (1ll<<(j-1)))) {
          dp[i+1][j-1] += dp[i][j];
        }
        else if (j+1 < w and (bit & (1ll<<j))) {
          dp[i+1][j+1] += dp[i][j];
        }
        else dp[i+1][j] += dp[i][j];
      }
    }
  }

  cout << dp[h][k-1].val() << '\n';
  return 0;
}