#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<vector<int>> dp(h, vector<int>(w, -inf));
  dp[0][0] = 1;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        continue;
      }
      if (i - 1 >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
      }
      if (j - 1 >= 0) {
        dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
      }
    }
  }

  int ans = 0;
  rep(i, h) rep(j, w) ans = max(ans, dp[i][j]);
  cout << ans << "\n";
  return 0;
}