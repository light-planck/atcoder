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

  vector<ll> cnt(n+1);

  for (ll i = 2; i <= n; ++i) {
    auto primes = factorize(i);
    for (auto [p, ex] : primes) cnt[p] += ex;
  }

  ll ans = 0;

  // (a^3, b^4, c^4) (b < c)
  for (ll a = 1; a <= n; ++a) {
    for (ll b = 1; b <= n; ++b) {
      for (ll c = b+1; c <= n; ++c) {
        if ((a == b) or (c == a)) continue;
        if (cnt[a] >= 2 and cnt[b] >= 4 and cnt[c] >= 4) ++ans;
      }
    }
  }

  // 3, 25
  // 5, 15
  for (ll a = 1; a <= n; ++a) {
    for (ll b = 1; b <= n; ++b) {
      if (a == b) continue;
      if (cnt[a] >= 2 and cnt[b] >= 24) ++ans;
      if (cnt[a] >= 4 and cnt[b] >= 14) ++ans;
    }
  }

  // 75
  for (ll a = 1; a <= n; ++a) {
    if (cnt[a] >= 74) ++ans;
  }

  cout << ans << '\n';
  return 0;
}