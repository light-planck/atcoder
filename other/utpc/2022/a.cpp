#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <numeric>
#include <map>
#include <chrono>
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


int main() {
  ll limit = 1000;

  for (ll k = 3; k <= limit; k += 3) {
    if (k%10 == 0) continue;
    bool skip = true;
    cout << "k: " << k << '\n';

    std::chrono::system_clock::time_point  start, end; // 型は auto で可
    start = std::chrono::system_clock::now(); // 計測開始時間
    bool flag = false;

    for (ll i = 1; i < 1000000; ++i) {
      ll n = k * i;
      set<ll> st;
      string s = to_string(n);
      sort(s.begin(), s.end());
      do {
        end = std::chrono::system_clock::now();  // 計測終了時間
        double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
        if (elapsed >= 20*1000) {
          cout << "break" << '\n';
          flag = true;
          break;
        }

        ll x = stoll(s);
        st.emplace(x);
      } while (next_permutation(s.begin(), s.end()));

      if (flag) break;

      ll g = 0;
      for (auto x : st) g = gcd(g, x);
      if (g == k) {
        skip = false;
        cout << "n = " << n << " = ";
        auto primes = factorize(n);
        for (auto [p, ex] : primes) printf(" %lld^%lld ・", p, ex);
        cout << '\n';
        break;
      }
    }

    if (skip) cout << -1 << '\n';
  }
  return 0;
}