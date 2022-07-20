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
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;


// 素因数分解
vector<pair<long long, long long>> prime_factorize(long long n) {
  vector<pair<long long, long long>> primes;

  for (long long i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;

    long long exponent = 0;
    while (n % i == 0) {
      ++exponent;
      n /= i;
    }

    primes.emplace_back(i, exponent);
  }

  // 上の処理後にnが1でないならnは素数
  if (n != 1) {
    primes.emplace_back(n, 1);
  }

  return primes;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  map<ll, ll> lcm;

  rep(i, n) {
    auto primes = prime_factorize(a[i]);
    for (auto [p, ex] : primes) {
      chmax(lcm[p], ex);
    }
  }

  mint l = 1;
  for (auto [p, ex] : lcm) {
    l *= mint(p).pow(ex);
  }

  // ans += lcm / (a[i]^(mod-2))
  mint ans = 0;
  constexpr ll mod = 1e9 + 7;
  rep(i, n) {
    ans += l * mint(a[i]).pow(mod-2);
  }

  cout << ans.val() << "\n";
  return 0;
}