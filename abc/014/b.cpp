#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, x;
  cin >> n >> x;
  
  vector a(n, 0ll);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  rep(i, n) {
    if (x & (1ll<<i)) ans += a[i];
  }

  cout << ans << '\n';
  return 0;
}