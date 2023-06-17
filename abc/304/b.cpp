#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  auto Pow = [](ll x, ll n) {
    ll res = 1;
    while (n > 0) {
      if (n & 1)
        res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  };

  if (n <= 1000 - 1) {
    cout << n << '\n';
  } else {
    int x = 0;
    for (ll i = 4; i <= 9; ++i) {
      if (n <= Pow(10, i) - 1) {
        x = i;
        break;
      }
    }

    ll base = Pow(10, x - 3);
    ll d = n % base;
    n -= d;
    if (d >= 5 * base) {
      n += base;
    }
    cout << n << '\n';
  }
  return 0;
}
