#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  ll W = 101;
  vector s(W, vector<bool>(W, false));
  rep(i, N) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for (ll x = a; x < b; ++x) {
      for (ll y = c; y < d; ++y) {
        s[y][x] = true;
      }
    }
  }

  ll ans = 0;
  rep(i, W) {
    rep(j, W) {
      if (s[i][j]) ++ans;
    }
  }

  cout << ans << '\n';
}
