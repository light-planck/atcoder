#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector a(n, 0ll);
  rep(i, n) cin >> a[i];

  vector s(n+1, 0ll);
  rep(i, n) s[i+1] = (s[i]+a[i]) % m;

  ll ans = 0;
  map<ll, ll> cnt;
  rep(r, n+1) {
    ans += cnt[s[r]];
    ++cnt[s[r]];
  }

  cout << ans << '\n';
  return 0;
}