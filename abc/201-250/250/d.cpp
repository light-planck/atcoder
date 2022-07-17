#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


vector<bool> eratos(ll n) {
  vector<bool> isprime(n+1, true);
  isprime[0] = false;
  isprime[1] = false;

  for (ll p = 2; p <= n; p++) {
    if (!isprime[p]) continue;
    for (ll q = p * 2; q <= n; q += p) {
      isprime[q] = false;
    }
  }
  return isprime;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  ll max_q = 1e6+1;

  auto is_prime = eratos(max_q);
  vector<ll> primes;
  for (ll i = 2; i < max_q; ++i) {
    if (i * i * i > n) continue;

    if (is_prime[i]) primes.emplace_back(i);
  }

  ll len = primes.size();
  ll ans = 0;
  for (ll i = 0; i < len; ++i) {
    for (ll j = i + 1; j < len; ++j) {
      if (primes[i] * primes[j] * primes[j] > n / primes[j]) break;

      ++ans;
    }
  }

  cout << ans << "\n";
  return 0;
}