#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, S, M, L;
  cin >> N >> S >> M >> L;

  constexpr ll limit = 100;
  ll ans = 1ll << 60;
  for (ll s = 0; s < limit; ++s) {
    for (ll m = 0; m < limit; ++m) {
      for (ll l = 0; l < limit; ++l) {
        ll count = 6 * s + 8 * m + 12 * l;
        if (count >= N) {
          ans = min(ans, S * s + M * m + L * l);
        }
      }
    }
  }

  cout << ans << '\n';
}
