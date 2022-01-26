#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  string t = "chokudai";

  // dp[i][j] : s[i]までを使ってchokudaiのj文字目まで選ぶ通り数
  vector<vector<int>> dp(n+1, vector<int>(9));
  // i = 0, 1 <= j sから0文字をとってtとするのは不可能、0
  // j = 0 chokudaiの0文字目まではsから何も選んでいない状態ゆえ、1
  rep(i, n+1) dp[i][0] = 1;

  // s[i] != t[j] 文字が異なると下線は引けないのでdp[i][j] = dp[i-1][j]
  // s[i] == t[j] dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 8; j++) {
      if (s[i-1] != t[j-1]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
    }
  }
  
  cout << dp[n][8] << endl;
  return 0;
}