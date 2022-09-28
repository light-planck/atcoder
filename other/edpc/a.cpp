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
  ll n;
  cin >> n;

  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  constexpr ll inf = 9e18;
  vector<ll> dp(n, inf);
  dp[0] = 0;

  rep(i, n) {
    auto chmin = [](auto& a, auto b) { if (a > b) a = b; };

    if (i+1 < n) chmin(dp[i + 1], dp[i]+abs(h[i]-h[i+1]));
    if (i+2 < n) chmin(dp[i + 2], dp[i]+abs(h[i]-h[i+2]));
  }

  cout << dp[n-1] << '\n';
  return 0;
}