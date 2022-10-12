#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;


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

  map<ll, ll> cnt;
  for (ll i = 1; i <= n; ++i) {
    auto divs = factorize(i);
    for (auto [p, ex] : divs) cnt[p] += ex;
  }

  using mint = modint1000000007;
  mint ans = 1;
  for (auto [p, ex] : cnt) ans *= ex + 1;

  cout << ans.val() << '\n';
  return 0;
}