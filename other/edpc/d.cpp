#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

/*
int wei[110], val[110];
ll dp[110][100100];
*/

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> wei(n), val(n);
  rep(i, n) cin >> wei[i] >> val[i];
  vector<vector<ll>> dp(n+10, vector<ll>(w+10));
  
  //dp[i][w]はval[0], ... val[i-1]を選んだときのwを超えない最大値
  for (int i = 0; i < n; i++) {
    for (int sumw = 0; sumw <= w; sumw++) {

      //dp[i+1][w]はval[i]を選ぶか選ばないか
      if (sumw - wei[i] >= 0) {
        dp[i + 1][sumw] = max(dp[i + 1][sumw], dp[i][sumw - wei[i]] + val[i]);
      }
      
      //選ばないとき
      dp[i + 1][sumw] = max(dp[i + 1][sumw], dp[i][sumw]);
    }
  }

  cout << dp[n][w] << endl;
  return 0;
}