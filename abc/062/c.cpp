#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  ll ans = 9e18;

  auto solve1 = [&ans](ll h, ll w) {
    for (ll a = 1; a <= h; ++a) {
      ll b = (h-a) / 2;
      ll c = h - (a+b);

      if (a < 0 or b < 0 or c < 0) continue;
      if (a > h or b > h or c > h) continue;

      ll mn = min({a, b, c});
      ll mx = max({a, b, c});

      auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
      chmin(ans, (mx-mn) * w);
    }
  };

  auto solve2 = [&ans](ll h, ll w) {
    for (ll a = 1; a <= h; ++a) {
      ll b = h - a;
      ll c = w / 2;
      ll d = w - c;

      if (a < 0 or b < 0 or c < 0 or d < 0) continue;
      if (a > h or b > h or c > w or d > w) continue;

      ll mn = min({a*w, b*c, b*d});
      ll mx = max({a*w, b*c, b*d});

      auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
      chmin(ans, mx-mn);
    }
  };

  solve1(h, w);
  solve1(w, h);
  solve2(h, w);
  solve2(w, h);

  cout << ans << '\n';
  return 0;
}