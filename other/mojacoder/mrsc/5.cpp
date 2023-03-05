#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, s;
  cin >> n >> s;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> dp(n+1);
  rep(i, n) {
    vector<ll> prev(n+1);
    swap(prev, dp);
    rep(j, n+1) {
      dp[j] = prev[j];
      if (j+1 <= n) dp[j+1] = prev[j] + a[i];
    }
  }

  ll sum = accumulate(a.begin(), a.end(), 0ll);
  rep(i, n) {
    if (sum - dp[i] == s) {
      cout << i+1 << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';
  return 0;
}