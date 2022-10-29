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
#include <atcoder/modint>
using namespace atcoder;


int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  using mint = modint998244353;
  vector<mint> dp(n+1);
  dp[0] = 1;

  rep(i, k) {
    vector<mint> prev(n+1);
    swap(prev, dp);

    rep(j, n+1) {
      if (prev[j] == 0) continue;

      for (ll dj = 1; dj <= m; ++dj) {
        ll nj = j + dj;
        if (nj > n) nj -= n;

        dp[nj] += prev[j];
      }
    }
  }

  if (dp[n] == 0) {
    cout << 0 << '\n';
    return 0;
  }

  mint x = 2;
  x = x.pow(k) / dp[n];

  mint ans = mint(x).inv();
  cout << ans.val() << '\n';
  return 0;
}