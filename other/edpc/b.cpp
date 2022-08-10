#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  //dpのサイズはノード数+遷移数は欲しい
  vector<int> dp(n+k);
  rep(i, n+k) dp[i] = inf;
  dp[0] = 0;
  for (int i = 0; i <= n - 2; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i+j] = min(dp[i+j], dp[i] + abs(h[i] - h[i+j]));
    }
  }
  cout << dp[n-1] << endl;
  return 0;
}