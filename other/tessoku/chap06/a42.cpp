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

  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  ll ans = 0;
  for (ll x = 1; x <= 100; ++x) {
    for (ll y = 1; y <= 100; ++y) {
      ll cnt = 0;

      rep(i, n) {
        if (a[i] < x or a[i] > x+k) continue;
        if (b[i] < y or b[i] > y+k) continue;
        ++cnt;
      }

      auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
      chmax(ans, cnt);
    }
  }

  cout << ans << '\n';
  return 0;
}