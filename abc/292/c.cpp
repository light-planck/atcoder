#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


// 素因数分解
auto factorize(ll n) {
  map<ll, ll> primes;

  for (ll i = 2; i*i <= n; ++i) {
    if (n % i != 0) continue;

    ll ex = 0;
    while (n % i == 0) {
      ++ex;
      n /= i;
    }

    primes[i] = ex;
  }

  if (n != 1) primes[n] = 1;

  return primes;
}


int main() {
  ll n;
  cin >> n;
  
  ll ans = 0;
  for (ll x = 1; x <= n; ++x) {
    ll y = n - x;
    if (y <= 0 or y > n) continue;

    // cout << "x, y: " << x << " " << y << '\n';

    ll tmp_x = 1;
    map<ll, ll> primes_x = factorize(x);
    for (auto [p, ex] : primes_x) tmp_x *= ex + 1;
    // cout << "x tmp: " << tmp << '\n';
    // tmp *= 2;
    
    ll tmp_y = 1;
    map<ll, ll> primes_y = factorize(y);
    for (auto [p, ex] : primes_y) tmp_y *= ex + 1;
    // cout << "y tmp: " << tmp << '\n';

    ans += tmp_x*tmp_y;
  }

  cout << ans << '\n';
  return 0;
}