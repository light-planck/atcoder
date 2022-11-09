#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


constexpr ll mod = 1e9 + 7;

ll Pow(ll x, ll n) {
  ll res = 1;

  while (n > 0) {
    if (n & 1) res *= x;
    res %= mod;

    x *= x;
    x %= mod;
    n >>= 1;
  }
  res %= mod;

  return res;
}


int main() {
  ll n, r;
  cin >> n >> r;

  // a/b = a * b^m-2 (mod m)
  ll a = 1;
  rep(i, n) {
    a *= (i+1);
    a %= mod;
  }

  ll b = 1;
  rep(i, r) {
    b *= (i+1);
    b %= mod;
  }
  for (ll i = n-r; i >= 1; --i) {
    b *= i;
    b %= mod;
  }

  ll ans = a * Pow(b, mod-2);
  ans %= mod;
  cout << ans << '\n';
  return 0;
}