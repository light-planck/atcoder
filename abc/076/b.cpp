#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  ll ans = 1ll << 60;
  for (ll i = 0; i <= n; ++i) {
    ll now = 1;
    rep(l, i) now *= 2;

    ll j = n - i;
    rep(l, j) now += k;
    ans = min(ans, now);
  }

  cout << ans << '\n';
  return 0;
}