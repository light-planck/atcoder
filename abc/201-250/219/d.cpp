#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int dp[301][301][301];
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  const int INF = 1e9;
  rep(i, n + 1) rep(j, x + 1) rep(k, y + 1) dp[i][j][k] = INF;
  dp[0][0][0] = 0;

  rep(i, n) rep(j, x + 1) rep(k, y + 1) {
    if (dp[i][j][k] == INF) continue;

    chmin(dp[i + 1][j][k], dp[i][j][k]);
    chmin(dp[i + 1][min(j + a[i], x)][min(k + b[i], y)], dp[i][j][k] + 1);
  }

  if (dp[n][x][y] == INF) {
    cout << -1 << "\n";
  }
  else {
    cout << dp[n][x][y] << "\n";
  }
  return 0;
}