#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll B;
  cin >> B;

  auto Pow = [](ll x, ll n) {
    ll res = 1;
    while (n > 0) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  };

  for (ll a = 1; Pow(a, a) <= B; ++a) {
    if (Pow(a, a) == B) {
      cout << a << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';
}
