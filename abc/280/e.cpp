#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;


int main() {
  ll n, p;
  cin >> n >> p;

  using mint = modint998244353;
  vector<mint> dp(n+1);
  dp[0] = 0; dp[1] = 1;

  rep(i, n-1) {
    dp[i+2] = 1;
    dp[i+2] += (1 - (mint)p/100) * dp[i+1];
    dp[i+2] += ((mint)p/100) * dp[i];
  }

  cout << dp[n].val() << '\n';
  return 0;
}