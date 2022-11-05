#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll g = 0;
  rep(i, n) g = gcd(g, a[i]);

  ll ans = 0;
  rep(i, n) {
    a[i] /= g;

    while (a[i]%2 == 0) {
      a[i] /= 2;
      ++ans;
    }
    while (a[i]%3 == 0) {
      a[i] /= 3;
      ++ans;
    }

    if (a[i] != 1) {
      cout << -1 << '\n';
      return 0;
    }
  }

  cout << ans << '\n';
  return 0;
}