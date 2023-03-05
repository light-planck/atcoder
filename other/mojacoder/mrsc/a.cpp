#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, l, r;
  cin >> n >> l >> r;

  ll ans = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    if (a <= l) ans += l - a;
    else if (a < r) ans += r - a;
  }

  cout << ans << '\n';
  return 0;
}