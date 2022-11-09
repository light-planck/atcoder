#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, x, y;
  cin >> n >> x >> y;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  x -= a[0];

  vector<ll> dxs, dys;
  for (ll i = 1; i < n; ++i) {
    if (i%2 == 0) dxs.emplace_back(a[i]);
    else dys.emplace_back(a[i]);
  }

  auto check = [](vector<ll> dxs, ll x) {
    set<ll> dp;
    dp.emplace(0);

    for (auto dx : dxs) {
      set<ll> prev;
      swap(prev, dp);

      for (auto now : prev) {
        dp.emplace(now + dx);
        dp.emplace(now - dx);
      }
    }

    return dp.count(x);
  };

  if (check(dxs, x) and check(dys, y)) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}