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
  ll h, a;
  cin >> h >> a;

  ll p = a;
  while (p > 0) {
    if (is_prime(p)) break;
    --p;
  }

  auto round = [](ll a, ll b) { return (a + b - 1) / b; };
  cout << round(h, p) << '\n';
  return 0;
}