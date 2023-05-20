#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m, d;
  cin >> n >> m >> d;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> b(m);
  rep(i, m) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans = -1;
  rep(i, n) {
    ll idx = lower_bound(b.begin(), b.end(), a[i]+d) - b.begin();
    if (idx >= m) idx = m-1;
    if (b[idx] > a[i]+d) --idx;
    if (idx < 0) idx = 0;
    if (abs(a[i]-b[idx]) > d) continue;
    ans = max(ans, a[i]+b[idx]);
  }

  cout << ans << '\n';
  return 0;
}