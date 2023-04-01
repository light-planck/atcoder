#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  constexpr ll inf = 1ll << 60;
  ll ans = inf;
  ll limit = llround(sqrt(m));
  ll max_n = 1e12;
  bool flag = false;

  for (ll a = 1; a <= limit; ++a) {
    auto Round = [](ll a, ll b) { return (a + b - 1) / b; };
    ll b = Round(m, a);

    if (a < 1 or a > n) continue;
    if (b < 1 or b > n) continue;
    if (a*b < m) continue;

    if (ans == inf) {
      if (a == max_n and b == max_n) {
        flag = true;
        continue;
      }
    }

    ans = min(ans, a*b);
  }

  if (flag and ans==inf) {
    cout << '1' + string('0', 24) << '\n';
    return 0;
  }

  if (ans == inf) ans = -1;
  cout << ans << '\n';
  return 0;
}