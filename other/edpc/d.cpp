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
  ll n, max_w;
  cin >> n >> max_w;

  vector<ll> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];

  vector<ll> dp(max_w+1);
  rep(i, n) {
    vector<ll> prev(max_w+1);
    swap(dp, prev);

    for (ll j = 0; j <= max_w; ++j) {
      auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
      chmax(dp[j], prev[j]);
      if (j+w[i] <= max_w) chmax(dp[j+w[i]], prev[j]+v[i]);
    }
  }

  cout << dp[max_w] << '\n';
  return 0;
}