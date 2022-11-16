#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };

  ll d, g;
  cin >> d >> g;

  vector<ll> p(d), c(d);
  rep(i, d) cin >> p[i] >> c[i];

  ll ans = 9e18;

  for (ll bit = 0; bit < (1LL<<d); ++bit) {
    ll cnt = 0;
    ll score = 0;

    rep(i, d) {
      if ((bit>>i) & 1LL) {
        cnt += p[i];
        score += 100*(i+1)*p[i] + c[i];
      }
    }

    if (score < g) {
      for (ll i = d-1; i >= 0; --i) {
        if ((bit>>i) & 1LL) continue;

        for (ll j = 0; j < p[i]; ++j) {
          if (score >= g) break;
          score += 100 * (i+1);
          ++cnt;
        }
      }
    }

    if (score >= g) chmin(ans, cnt);
  }

  cout << ans << '\n';
  return 0;
}