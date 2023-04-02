#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  constexpr ll inf = 1ll << 60;
  ll ans = inf;
  for (ll a = 1; a <= n; ++a) {
    ll b = (m+a-1) / a;
    if (b <= n) ans = min(ans, a*b);
    if (a > b) break;
  }

  if (ans == inf) ans = -1;
  cout << ans << '\n';
  return 0;
}