#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll D;
  cin >> D;

  ll ans = 1ll << 60;
  for (ll x = 0; x * x <= D; ++x) {
    ll y = sqrt(abs(x * x - D));
    ans = min(ans, abs(x * x + y * y - D));
    ans = min(ans, abs(x * x + (y + 1) * (y + 1) - D));
  }

  cout << ans << '\n';
}
