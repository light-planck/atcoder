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

  //dp[i]はi円となる最小の硬化の枚数
  vector<int> dp(n+100);

  //dp[i]の最大値はすべて1円で払ったときなのでdp[i] = i
  rep(i, (int)dp.size()) dp[i] = i;

  //dp[i]をdp[n]まで回す
  for (int i = 0; i < n; i++) {

    //6, 6^2, ...を試す
    //dp[i]からdp[i+6^x]
    //dp[i] + 1はpow6硬貨1枚
    for (int pow6 = 6; i + pow6 <= n; pow6 *= 6) {
      dp[i+pow6] = min(dp[i+pow6], dp[i] + 1);
    }

    //9^x
    for (int pow9 = 9; i + pow9 <= n; pow9 *= 9) {
      dp[i+pow9] = min(dp[i+pow9], dp[i] + 1);
    }
  }

  cout << dp[n] << endl;
  return 0;
}