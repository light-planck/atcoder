#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> sum(n+1);
  rep(i, n) sum[i+1] = sum[i] + a[i];

  ll ans = 9e18;
  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
  for (ll i = 1; i < n; ++i) {
    ll x = sum[i];
    ll y = sum[n] - sum[i];
    chmin(ans, abs(x-y));
  }

  cout << ans << '\n';
  return 0;
}