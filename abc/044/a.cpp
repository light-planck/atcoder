#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k, x, y;
  cin >> n >> k >> x >> y;

  ll ans = 0;
  ans += min(n, k) * x;
  ans += max(n-k, 0ll) * y;
  cout << ans << '\n';
  return 0;
}