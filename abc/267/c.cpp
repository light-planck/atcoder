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

  vector<ll> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];

  ll now = 0;
  rep(i, m) now += (i+1) * a[i];
  ll ans = now;

  for (ll i = 0; i < n-m; ++i) {
    now -= s[i + m] - s[i];
    now += m*a[i + m];
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    chmax(ans, now);
  }

  cout << ans << '\n';
  return 0;
}