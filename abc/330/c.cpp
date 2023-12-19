#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll D;
  cin >> D;

  ll ans = 1ll << 60;
  for (ll x = 0; x * x <= D; ++x) {
    ll c = x * x - D;

    if (c >= 0) {
      ans = min(ans, c);
      continue;
    }

    vector<ll> y = {(ll)sqrt(-c), (ll)ceil(sqrt(-c))};
    for (auto yi : y) {
      ans = min(ans, abs(c + yi * yi));
    }
  }

  cout << ans << '\n';
}
