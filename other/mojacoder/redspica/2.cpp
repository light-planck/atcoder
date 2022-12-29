#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


ll cnt = 1;


double calc_kairi(ll x, ll y) {
  return abs((double)x/y - cnt/365.0);
}


int main() {
  double ans = 1e18;

  ll x = 0; ll y = 0;
  for (ll m = 1; m <= 12; ++m) {
    ll max_day = 31;
    if (m == 2) max_day = 28;
    if (m == 4 or m == 6 or m == 9 or m == 11) --max_day;

    for (ll d = 1; d <= max_day; ++d) {
      double kairi = calc_kairi(m, d);
      if (ans > kairi) {
        x = m;
        y = d;
        ans = kairi;
      }

      ++cnt;
    }
  }

  cout << x << "/" << y << '\n';
  return 0;
}