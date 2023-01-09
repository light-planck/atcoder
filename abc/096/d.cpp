#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


// 2, 3, ... , sqrt(n)まで調べればよい
bool is_prime(long long x) {
  if (x < 2) return false;

  for (long long i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }

  return true;
}


int main() {
  ll n;
  cin >> n;

  vector<ll> primes;
  for (ll i = 2; i <= 55555; ++i) {
    if (is_prime(i) and i%5 == 1) primes.emplace_back(i);
  }

  rep(i, n) cout << primes[i] << ' ';
  cout << '\n';
  return 0;
}