#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };

  ll w, h, n;
  cin >> w >> h >> n;

  ll left = 0; ll right = w;
  ll bottom = 0; ll top = h;

  rep(i, n) {
    ll x, y, a;
    cin >> x >> y >> a;

    if (a == 1) chmax(left, x);
    if (a == 2) chmin(right, x);
    if (a == 3) chmax(bottom, y);
    if (a == 4) chmin(top, y);
  }

  ll ans = 0;
  if (top-bottom >= 0 and right-left >= 0) ans = (top-bottom)*(right-left);
  cout << ans << '\n';
  return 0;
}