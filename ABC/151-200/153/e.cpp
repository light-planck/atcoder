#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h, n;
  cin >> h >> n;

  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  const int INF = 1e9;
  vector<vector<ll>> dp(n + 1, vector<ll>(h + 1, INF));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < h + 1; ++j) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j] = min(dp[i + 1][max(j - a[i], 0LL)] + b[i], dp[i][j]);
    }
  }

  cout << dp[n][h] << "\n";
  return 0;
}