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
  ll n, x;
  cin >> n >> x;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  for (ll i = 0; i+1 < n; ++i) {
    auto f = [&](ll idx, ll t) {
      ans += a[idx] - t;
      a[idx] = t;
    };

    ll now = x;
    if (a[i] > x) f(i, now);
    now -= a[i];
    if (a[i+1] > now) f(i+1, now);
  }

  cout << ans << '\n';
  return 0;
}