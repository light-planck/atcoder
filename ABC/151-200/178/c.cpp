#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// 答え = 全体 - 0を含まないA - 9を含まないA + 0と9のどちらも含まないA

const int mod = 1e9 + 7;

ll pow_mod(ll x, ll n, ll md) {
  if (n == 0) return 1;

  ll res = pow_mod(x, n / 2, md);
  res *= res;
  res %= md;

  if (n % 2 == 1) {
    res *= x;
    res %= md;
  }

  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  ll ans = pow_mod(10, n, mod);
  ans %= mod;

  ans -= pow_mod(9, n, mod);
  ans += mod;
  ans %= mod;

  ans -= pow_mod(9, n, mod);
  ans += mod;
  ans %= mod;

  ans += pow_mod(8, n, mod);
  ans %= mod;

  cout << ans << "\n";
  return 0;
}