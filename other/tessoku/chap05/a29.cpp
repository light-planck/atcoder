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
  ll a, b;
  cin >> a >> b;

  cout << Pow(a, b) << '\n';
  return 0;
}