#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;
  --a; --b;

  ll h = 100; ll w = 100;
  vector<string> s(h, string(w, '.'));
  for (ll i = h/2; i < h; ++i) s[i] = string(w, '#');

  const vector<pair<ll, ll>> dij = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  auto check = [&](ll i, ll j) {
    if (i < 0 or i >= h) return false;
    if (j < 0 or j >= w) return false;
    return true;
  };

  // 上半分の白をb個黒に塗る
  for (ll i = 0; i < h/2; ++i) for (ll j = 0; j < w; ++j) {
    if (s[i][j] == '#') continue;

    bool ok = true;
    for (auto [di, dj] : dij) {
      if (b == 0) continue;
      ll ni = i+di; ll nj = j+dj;
      if (not check(ni, nj)) continue;
      if (s[ni][nj] == '#') ok = false;
    }

    if (ok and b > 0) {
      s[i][j] = '#';
      --b;
    }
  }

  // 下半分の黒をa個分白に塗る
  for (ll i = h-1; i >= h/2; --i) for (ll j = 0; j < w; ++j) {
    if (s[i][j] == '.') continue;
    bool ok = true;

    for (auto [di, dj] : dij) {
      if (a == 0) continue;
      ll ni = i+di; ll nj = j+dj;
      if (not check(ni, nj)) continue;
      if (s[ni][nj] == '.') ok = false;
    }

    if (ok and a > 0) {
      s[i][j] = '.';
      --a;
    }
  }

  cout << h << " " << w << '\n';
  for (string row : s) cout << row << '\n';
  return 0;
}