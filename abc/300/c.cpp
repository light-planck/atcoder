#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  ll n = min(h, w);
  vector<ll> ans(n);

  vector<pair<ll, ll>> dij = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  auto check = [&](ll i, ll j) {
    if (i < 0 or i >= h) return false;
    if (j < 0 or j >= w) return false;
    return true;
  };

  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '.') continue;

      ll len = 0;
      for (ll d = 1; d <= n; ++d) {
        bool ok = true;

        for (auto [di, dj] : dij) {
          di *= d; dj *= d;
          ll ni = i+di; ll nj = j+dj;

          if (not check(ni, nj)) ok = false;
          else if (s[ni][nj] == '.') ok = false;
        }

        if (not ok) break;
        len = d;
      }

      if (len > 0) ++ans[len-1];
    }
  }

  for (auto x : ans) cout << x << ' ';
  cout << '\n';
  return 0;
}