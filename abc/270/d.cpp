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

  ll now = n;
  ll ans = 0;
  ll i = k-1;

  while (now > 0) {
    rep(j, 2) {
      // ll idx = lower_bound(a.begin(), a.end(), now) - a.begin();
      // if (idx == n) --idx;
      while (a[i] > now and i > 0) --i;
      now -= a[i];
      if (j == 0) ans += a[i];
    }
  }

  cout << ans << '\n';
  return 0;
}