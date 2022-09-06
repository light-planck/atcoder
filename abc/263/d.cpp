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
  ll n, l, r;
  cin >> n >> l >> r;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];

  vector<ll> f(n + 1);
  rep(x, n+1) f[x] = l*x - s[x];

  vector<ll> g(n + 1);
  rep(y, n+1) g[y] = r*(n-y) + s[y];

  vector<ll> min_g = g;
  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
  for (ll i = n-1; i >= 0; --i) {
    chmin(min_g[i], min_g[i + 1]);
  }

  ll ans = l * n;
  for (ll x = 0; x < n+1; ++x) {
    ll now = f[x] + min_g[x];

    chmin(ans, now);
  }

  cout << ans << '\n';
  return 0;
}