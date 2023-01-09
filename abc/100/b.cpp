#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll d, n;
  cin >> d >> n;

  ll ans = 0;
  if (n == 100) ++n;

  auto Pow = [](ll x, ll n) { ll res = 1; while (n > 0) { if (n & 1) res *= x; x *= x; n >>= 1; } return res; };
  ans = Pow(100, d) * n;
  cout << ans << '\n';
  return 0;
}