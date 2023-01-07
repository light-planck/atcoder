#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t;
  cin >> t;

  auto Sqrt = [](ll p) -> ll {
    for (ll i = 2; i*i <= p; ++i) {
      if (p%i == 0) {
        return p/i;
      }
    }
    return p;
  };

  while (t--) {
    ll n;
    cin >> n;

    auto solve = [&]() {
      ll p = 1; ll q = 0;

      for (ll i = 2; i*i*i <= n; ++i) {
        if (n%i == 0) {
          if ((n/i) % i == 0) {
            p = i;
            q = n / i / i;
          }
          else {
            q = i;
            p = n / q;
            p = Sqrt(p);
          }
        }
      }

      cout << p << " " << q << '\n';
    };

    solve();
  }
  return 0;
}