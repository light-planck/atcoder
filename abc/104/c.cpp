#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll d, g;
  cin >> d >> g;

  vector<ll> p(d), c(d);
  rep(i, d) cin >> p[i] >> c[i];

  ll ans = 0;
  ll now = g;
  for (ll i = d-1; i >= 0; --i) {
    auto round = [](ll a, ll b) { return (a + b - 1) / b; };
    ll time = min(round(now, 100*(i+1)), p[i]);

    if (time == p[i]) now -= c[i];
    now -= time * 100 * (i+1);
    ans += time;

    if (now <= 0) {
      break;
    }
  }

  using P = pair<ll, ll>;
  vector<P> bonus;
  rep(i, d) {
    bonus.emplace_back(p[i], -(p[i]*100*(i+1)+c[i]));
  }
  sort(bonus.begin(), bonus.end());

  ll ans2 = 0;
  now = 0;
  for (auto [cnt, b] : bonus) {
    b *= -1;
    now += b;
    ans2 += cnt;

    if (now >= g) break;
  }

  cout << min(ans, ans2) << '\n';
  return 0;
}