#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> c(n-1), s(n-1), f(n-1);
  rep(i, n-1) cin >> c[i] >> s[i] >> f[i];

  rep(i, n-1) {
    ll now = s[i];
    for (ll j = i; j < n-1; ++j) {
      if (j != i) {
        auto round = [](ll a, ll b) { return (a + b - 1) / b; };
        ll k = round(now-s[j], f[j]);
        if (now - s[j] < 0) k = 0;
        now = f[j]*k + s[j];
      }

      now += c[j];
    }

    cout << now << '\n';
  }
  cout << 0 << '\n';
  return 0;
}