#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 998244353;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // dp[i][j] a[i]まで操作したときの左端がjとなるような場合の数
  vector<vector<ll>> dp(n+1, vector<ll>(10));
  dp[0][a[0]] = 1;

  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < 10; j++) {

      // f
      (dp[i + 1][(j + a[i + 1]) % 10] += dp[i][j]) %= mod;
      
      // g
      (dp[i + 1][(j * a[i + 1]) % 10] += dp[i][j]) %= mod;
    }
  }

  for (int k = 0; k <= 9; k++) {
    cout << dp[n-1][k] << endl;
  }
  return 0;
}