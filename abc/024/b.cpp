#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, t;
  cin >> n >> t;

  vector a(n, 0ll);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  rep(i, n-1) {
    if (a[i+1]-a[i] > t) ans += t;
    else ans += a[i+1] - a[i];
  }
  ans += t;

  cout << ans << '\n';
  return 0;
}