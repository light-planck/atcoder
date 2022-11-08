#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll ans = 0;
  ll mod = 10000;
  rep(i, n) {
    char t; ll a;
    cin >> t >> a;

    if (t == '+') ans += a;
    if (t == '-') ans -= a;
    if (t == '*') ans *= a;

    ans += mod;
    ans %= mod;
    cout << ans << '\n';
  }
  return 0;
}