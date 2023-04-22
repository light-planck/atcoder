#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, t;
  cin >> n >> t;

  vector<ll> c(n), r(n);
  rep(i, n) cin >> c[i];
  rep(i, n) cin >> r[i];

  ll ans = -1;
  ll value = 0;
  rep(i, n) {
    if (c[i] == t) {
      if (r[i] > value) {
        value = r[i];
        ans = i + 1;
      }
    }
  }
  if (ans != -1) {
    cout << ans << '\n';
    return 0;
  }

  rep(i, n) {
    if (c[i] == c[0]) {
      if (r[i] > value) {
        value = r[i];
        ans = i + 1;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}