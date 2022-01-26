#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;
const long long INF = 1LL<<60;

const int nmax = 110;
const int vmax = 100100;
//ll dp[nmax][vmax];
//ll wei[nmax], val[nmax];

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> wei(n), val(n);
  rep(i, n) cin >> wei[i] >> val[i];

  //dp[i][v] i-1番目までの品物を価値vとなるように選んだときの重さの最小値
  vector<vector<ll>> dp(n+1, vector<ll>(vmax));
  rep(i, n+1)rep(j, vmax) dp[i][j] = INF;
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int sumv = 0; sumv <= vmax; sumv++) {

      //追加する
      if (sumv - val[i] >= 0) {
        dp[i + 1][sumv] = min(dp[i + 1][sumv], dp[i][sumv - val[i]] + wei[i]);
      }

      //しない
      dp[i + 1][sumv] = min(dp[i + 1][sumv], dp[i][sumv]);
    }
  }

  //dp[n][0], dp[n][1], ... dp[n][1000]のうち、値がw以下となる最大のsumv
  ll ans = 0;
  for (int sumv = 0; sumv < vmax; sumv++) {
    if (dp[n][sumv] <= w) ans = sumv;
  }

  cout << ans << endl;
  return 0;
}