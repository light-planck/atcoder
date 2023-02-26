#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;


int main() {
  ll n;
  cin >> n;

  vector a(n, vector<ll>(2));
  rep(i, n) rep(j, 2) cin >> a[i][j];

  vector<mint> dp(2, 1);
  rep(i, n-1) {
    vector<mint> prev(2);
    swap(prev, dp);
    rep(j, 2) {
      rep(k, 2) {
        if (a[i+1][k] != a[i][j]) dp[k] += prev[j];
      }
    }
  }

  cout << (dp[0]+dp[1]).val() << '\n';
  return 0;
}