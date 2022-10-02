#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, s;
  cin >> n >> s;

  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector dp(n+1, vector<ll>(s+1));
  dp[0][0] = 1;

  rep(i, n) {
    rep(j, s+1) {
      if (not dp[i][j]) continue;

      // 表
      if (j+a[i] <= s) dp[i+1][j+a[i]] = dp[i][j];

      // 裏
      if (j+b[i] <= s) dp[i+1][j+b[i]] = dp[i][j];
    }
  }

  if (not dp[n][s]) {
    cout << "No" << '\n';
    return 0;
  }

  cout << "Yes" << '\n';

  string ans = "";
  ll i = n-1; ll j = s;
  while (i >= 0 and j >= 0) {
    if (j-a[i] >= 0 and dp[i][j-a[i]]) {
      ans += "H";
      j -= a[i];
    }
    else {
      ans += "T";
      j -= b[i];
    }

    --i;
  }

  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}