#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

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
          p = sqrt(p);
        }
        break;
      }
    }

    cout << p << " " << q << '\n';
  }
  return 0;
}