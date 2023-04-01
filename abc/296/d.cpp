#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  auto Round = [](ll a, ll b) { return (a + b - 1) / b; };
  if (n < Round(m, n)) {
    cout << -1 << endl;
    return 0;
  }

  constexpr ll inf = 1ll << 60;
  ll ans = inf;
  ll limit = llround(sqrt(m));

  for (ll a = 1; a <= limit; ++a) {
    ll b = Round(m, a);

    if (a < 1 or a > n) continue;
    if (b < 1 or b > n) continue;
    if (a*b < m) continue;

    ans = min(ans, a*b);
  }

  if (ans == inf) ans = -1;
  cout << ans << '\n';
  return 0;
}