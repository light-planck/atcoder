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

  vector<ll> a(k);
  rep(i, k) cin >> a[i];

  vector<ll> dp(n + 1);
  rep(i, n) {
    rep(j, k) {
      auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
      if (i+1-a[j] < 0) break;
      chmax(dp[i+1], i+1 - dp[i+1-a[j]]);
    }
  }

  cout << dp[n] << '\n';
  return 0;
}