#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x;
  cin >> x;

  ll ans = 0;
  while (x) {
    ll r = x % 10;
    ans += r;
    x /= 10;
  }

  cout << ans << '\n';
  return 0;
}