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
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> dp(n+1);
  rep(i, n+1) dp[i] = inf;
  dp[0] = 0;
  rep(i, n-1) {
    dp[i+1] = min(dp[i+1], dp[i] + abs(a[i+1] - a[i]));
    dp[i+2] = min(dp[i+2], dp[i] + abs(a[i+2] - a[i]));
  }
  cout << dp[n-1] << endl;
  return 0;
}