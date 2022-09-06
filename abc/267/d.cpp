#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  constexpr ll inf = 9e18;
  vector<ll> dp(m+1, -inf);
  dp[0] = 0;

  auto chmax = [](auto& a, auto b) { if (a < b) a = b; };

  rep(i, n) {
    vector<ll> prev(m+1, -inf);
    swap(prev, dp);
    dp[0] = 0;

    rep(j, m) {
      chmax(dp[j + 1], prev[j] + (j+1)*a[i]);
      chmax(dp[j + 1], prev[j + 1]);
    }
  }

  ll ans = dp[m];
  cout << ans << '\n';
  return 0;
}