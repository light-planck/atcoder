#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll q;
  cin >> q;

  auto is_prime = [&](ll n) {
    for (ll i = 2; i*i <= n; ++i) {
      if (n%i == 0) return false;
    }
    return true;
  };
  
  while (q--) {
    ll x;
    cin >> x;

    if (is_prime(x)) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}