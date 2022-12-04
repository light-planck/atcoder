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
  ll k;
  cin >> k;

  auto primes = factorize(k);

  ll ok = 1e12;
  ll ng = 1;
  while (abs(ok-ng) > 1) {
    ll mid = min(ok, ng) + abs(ok-ng)/2;
  
    auto check = [&](ll x) {
      for (auto [p, ex] : primes) {
        ll cnt = 0;

        ll y = x;
        while (y) {
          cnt += y / p;
          y /= p;
        }

        if (cnt < ex) return false;
      }

      return true;
    };
  
    if (check(mid)) ok = mid;
    else ng = mid;
  }

  cout << ok << '\n';
  return 0;
}