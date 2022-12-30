#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 1e18;

  auto calc = [&](ll x) {
    ll sum = 0;
    ll cnt = 0;
    rep(i, n) {
      if (i%2 == x) {
        if (sum+a[i] > 0) sum += a[i];
        else {
          cnt += 1 - (sum+a[i]);
          sum = 1;
        }
      }
      else {
        if (sum+a[i] < 0) sum += a[i];
        else {
          cnt += (sum+a[i]) + 1;
          sum = -1;
        }
      }
    }

    auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
    chmin(ans, cnt);
  };

  rep(i, 2) calc(i);
  cout << ans << '\n';
  return 0;
}