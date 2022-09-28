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

  vector a(n, vector<ll>(3));
  rep(i, n) rep(j, 3) cin >> a[i][j];

  vector<ll> dp(3);
  rep(i, n) {
    vector<ll> prev(3);
    swap(dp, prev);

    rep(j, 3) {
      rep(k, 3) {
        if (j == k) continue;

        auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
        chmax(dp[k], prev[j]+a[i][k]);
      }
    }
  }

  ll ans = *max_element(dp.begin(), dp.end());
  cout << ans << '\n';
  return 0;
}