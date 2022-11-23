#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  a *= 100; b *= 100;

  ll m = 31;
  set<ll> water;
  rep(i, m) rep(j, m) {
    ll w = a*i + b*j;
    if (w > f) continue;
    water.emplace(w);
  }

  ll n = 101;
  set<ll> sugar;
  rep(i, n) rep(j, n) {
    ll s = c*i + d*j;
    if (s > f) continue;
    sugar.emplace(s);
  }

  ll ans_sugar = 0;
  ll ans_water = 0;
  double melt = 0;

  for (auto w : water) {
    for (auto s : sugar) {
      if (w+s > f) continue;
      if (s > w*e/100) continue;

      if (w+s > 0) {
        double m = (double)s / (w+s);
        if (m > melt) {
          melt = m;
          ans_sugar = s;
          ans_water = w;
        }
      }
    }
  }

  if (ans_sugar == 0) ans_water = a;
  cout << ans_sugar+ans_water << " " << ans_sugar << '\n';
  return 0;
}