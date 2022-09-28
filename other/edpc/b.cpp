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
  ll n, k;
  cin >> n >> k;

  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  constexpr ll inf = 9e18;
  vector<ll> dp(n, inf);
  dp[0] = 0;

  rep(i, n) {
    for (ll j = 1; j <= k; ++j) {
      auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
      if (i+j < n) chmin(dp[i+j], dp[i]+abs(h[i]-h[i+j]));
    }
  }

  cout << dp[n-1] << '\n';
  return 0;
}