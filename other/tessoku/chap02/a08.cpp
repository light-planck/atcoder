#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector x(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> x[i][j];

  vector s(h+1, vector<ll>(w+1));
  rep(i, h) rep(j, w) {
    s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + x[i][j];
  }

  ll q;
  cin >> q;

  while (q--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    --a; --b; --c; --d;

    ll ans = s[c+1][d+1] - s[c+1][b] - s[a][d+1] + s[a][b];
    cout << ans << '\n';
  }
  return 0;
}