#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;

  ll s, t;
  cin >> s >> t;

  ll ans = s*a + t*b;
  if (s+t >= k) ans -= (s+t) * c;
  cout << ans << '\n';
  return 0;
}