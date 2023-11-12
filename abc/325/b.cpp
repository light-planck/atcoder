#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  map<ll, ll> numbers;
  rep(i, N) {
    ll w, x;
    cin >> w >> x;

    for (ll h = 9 - x; h <= 18 - x; ++h) {
      numbers[h] += w;
    }
  }

  ll ans = 0;
  for (const auto [h, w] : numbers) {
    if (h > 0 and (h < 9 or h > 18)) continue;
    if (h < 0 and (h + 24 < 9 or h + 24 > 18)) continue;

    ans = max(ans, w);
  }

  cout << ans << '\n';
}
