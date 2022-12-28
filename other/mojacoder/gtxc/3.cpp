#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> b(n);
  rep(i, n) cin >> b[i];

  ll k = 0;
  rep(i, n) {
    k = gcd(k, a[i]-b[i]);
  }

  ll ans = 0;
  if (k > 0) rep(i, n) ans += abs(a[i]-b[i]) / k;
  cout << ans << endl;
  return 0;
}