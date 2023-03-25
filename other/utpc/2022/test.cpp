#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


// 素因数分解
map<ll, ll> factorize(ll n) {
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


ll calc_k(ll n) {
  set<ll> st;
  string s = to_string(n);
  sort(s.begin(), s.end());
  do {
    ll x = stoll(s);
    st.emplace(x);
  } while (next_permutation(s.begin(), s.end()));
  ll g = 0;
  for (auto x : st) g = gcd(g, x);
  return g;
}


int main() {
  // ll n = 7077;
  // auto primes= factorize(n);
  // for (auto [p, ex] : primes) {
  //   cout << p << " " << ex << '\n';
  // }

  // vector<ll> s = {9099, 999, 9909, 9990};
  // ll g = 0;
  // for (auto x : s) g = gcd(g, x);
  // cout << g << '\n';

  // ll n = 27;
  cout << calc_k(4444444440) << '\n';
  return 0;
}