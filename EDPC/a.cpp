#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

//メモ化再帰のとき
vector<int> h(100000);
vector<int> dp(100000);

int rec(int i) {

  //dp[i]が更新されていればそれを返す
  if (dp[i] < inf) return dp[i];

  //足場0までのコストは0
  if (i == 0) return 0;

  int ans = inf;

  //i-1 to i
  ans = min(ans, rec(i-1) + abs(h[i] - h[i-1]));
  
  //i-2 to i
  if (i > 1) {
    ans = min(ans, rec(i-2) + abs(h[i] - h[i-2]));
  }

  dp[i] = ans;
  return dp[i];
}

int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> h[i];
  rep(i, 100000) dp[i] = inf;
  dp[0] = 0;

  cout << rec(n-1) << endl;
  return 0;
}

//配るdp
/*
  for (int i = 0; i <= n-2; i++) {

    //足場iからi+1に移動
    dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));

    //足場iからi+2
    dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
  }

  //n-1番目の足場はn-3, n-2から移動できるが
  //i <= n-3のときn-1の足場はn-3からの移動だけしか計算できていない
  //n-2からn-1までの移動も計算したいので
  //dp.size() = n+1 としてi <= n-2まで回せば
  //dp[n-1] = min(dp[n-1], dp[n-2] + abs(h))でn-1の値が更新される

  //0-indexedなので求めるものは足場n-1までの最小値
*/

//もらうdp
/*
for (int i = 1; i < n; i++) {

    //足場1のときは0からの移動しかない
    if (i == 1) dp[i] = dp[0] + abs(h[i] - h[i-1]);
    else {

      //足場i-1からiまで移動するとき
      dp[i] = min(dp[i], dp[i-1] + abs(h[i] - h[i - 1]));

      //i-2からi
      dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
    }
  }
*/