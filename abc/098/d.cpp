#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector a(n, 0ll);
  rep(i, n) cin >> a[i];

  // 累積和
  vector s(n+1, 0ll);
  rep(i, n) s[i+1] = s[i] + a[i];

  // 累積xor
  vector x(n+1, 0ll);
  rep(i, n) x[i+1] = x[i] ^ a[i];

  // a[l] + a[l+1] + ... + a[r] = a[l] ^ a[l+1] ^ ... ^ a[r]
  // s[r+1] - s[l] = x[r+1] - x[l]
  // s[r+1] - x[r+1] = s[l] - x[l]
  // b[i] := x[i] - s[i]
  // b[r+1] = b[l]
  vector b(n+1, 0ll);
  rep(i, n+1) b[i] = x[i] - s[i];

  ll ans = 0;
  map<ll, ll> cnt;
  rep(r, n+1) {
    ans += cnt[b[r]];
    ++cnt[b[r]];
  }

  cout << ans << '\n';
  return 0;
}