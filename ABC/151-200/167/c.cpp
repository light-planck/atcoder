#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<ll> c(n);
  vector<vector<ll>> a(n, vector<ll>(m));
  rep(i, n) {
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }
  ll ans = inf;
  for (int bit = 0; bit < (1 << n); bit++) {
    ll sum = 0;
    vector<ll> b(m);
    for (int i = 0; i < n; i++) {
      if (bit & (1 << i)) {
        sum += c[i];
        rep(j, m) b[j] += a[i][j];
      }
    }
    bool ok = true;
    for (auto z : b) if (z < x) ok = false;
    if (ok) ans = min(ans, sum);
  }
  if (ans != inf) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}