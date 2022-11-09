#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 9e18;
  for (ll i = -100; i <= 100; ++i) {
    ll cnt = 0;
    rep(j, n) cnt += (i-a[j]) * (i-a[j]);
    chmin(ans, cnt);
  }

  cout << ans << '\n';
  return 0;
}