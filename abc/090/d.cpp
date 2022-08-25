#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  if (k == 0) {
    cout << n*n << '\n';
    return 0;
  }

  ll ans = 0;
  for (ll b = 1; b <= n; ++b) {
    ll r = n % b;
    ans += max(b-k, 0LL) * (n/b);
    ans += max(r-k+1, 0LL);
  }

  cout << ans << '\n';
  return 0;
}