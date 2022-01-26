#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }

  //dp[i][act]はi日目の幸福度の最大値
  //actはi日目にとった活動を示す0, 1, 2 = a, b, c
  vector<vector<ll>> dp(n+1, vector<ll>(3));
  
  //dp[i][0] -> dp[i+1][1], dp[i+1][2]
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k) continue;
        dp[i+1][k] = max(dp[i+1][k], dp[i][j] + a[i][k]);
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < 3; i++) ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}